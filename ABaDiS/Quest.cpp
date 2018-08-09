#include "stdafx.h"
#include "Quest.h"


Quest::Quest(Enumerators::TypeOfQuest toq, int sc, int fo, int we, int ar, Enumerators::statBoost boost, Room* toSec)
{
	reward = questReward{ sc, fo, we, ar, boost };
	typeOfQuest = toq;
	finished = false;

	gathered = 0;
	needsGathered = 0;

	timeHolding = 0;
	timeToHold = 0;

	toSecure = toSec;

	createQuest();
}

// Helpers
bool Quest::createQuest() {
	switch (typeOfQuest) {
	case Enumerators::TypeOfQuest::gathering:
		needsGathered = rand() % 100 + 100;
		return true;
		break;
	case Enumerators::TypeOfQuest::hold:
		timeToHold = rand() % 50 + 50;
		return true;
		break;
	case Enumerators::TypeOfQuest::secure:
		return true;
		break;
	default:
		std::cerr << "Wrong typeOfQuest for Regular Quest" << std::endl;
		break;
	}
	return false;
}

bool Quest::updateQuest() {
	switch (typeOfQuest) {
	case Enumerators::TypeOfQuest::gathering:
		if (gathered >= needsGathered)
			return true;
		break;
	case Enumerators::TypeOfQuest::hold:
		if (timeHolding >= timeToHold)
			return true;
		break;
	case Enumerators::TypeOfQuest::secure:
		return toSecure->isSecurityPresent();
		break;
	default:
		std::cerr << "Wrong typeOfQuest for Regular Quest" << std::endl;
		break;
	}
	return false;
}

// Getters
Enumerators::TypeOfQuest Quest::getTypeOfQuest() const {
	return typeOfQuest;
}

bool Quest::isDone() const {
	return finished;
}