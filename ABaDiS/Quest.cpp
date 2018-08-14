#include "stdafx.h"
#include "Quest.h"

// Regular Quest
Quest::Quest(Enumerators::TypeOfQuest toq, int sc, int fo, int we, int ar, Enumerators::statBoost boost, Room* toSec, Room* origin)
{
	originRoom = origin;

	reward = questReward{ sc, fo, we, ar, boost };
	typeOfQuest = toq;
	finished = false;

	gathered = 0;
	needsGathered = 0;

	timeHolding = 0;
	timeToHold = 0;

	toSecure = toSec;

	createQuest();

	ttg = none;
}

// Recruiting "Quest" as it's not really a quest but behaves as one.
Quest::Quest(Enumerators::TypeOfQuest toq, int maxSquadSize, int currentSquadSize) {
	if (toq != Enumerators::TypeOfQuest::recruit) {
		std::cerr << "Wrong type of quest for a recruiting quest" << std::endl;
		delete this;
	}
	else {

	}
}

// Helpers
bool Quest::createQuest() {
	switch (typeOfQuest) {
	case Enumerators::TypeOfQuest::gathering:
		needsGathered = rand() % 100 + 100;
		if (rand() % 2 == 0)
			ttg = typeToGather::food;
		else
			ttg = typeToGather::scrap;
		switch (ttg) {
		case (scrap):
			questName = "Gather " + std::to_string(needsGathered) + *" scrap.";
			break;
		case (food):
			questName = "Gather " + std::to_string(needsGathered) + " food.";
			break;
		default:
			std::cout << "Error while assigning questname" << std::endl;
		}
		return true;
		break;
	case Enumerators::TypeOfQuest::hold:
		timeToHold = rand() % 50 + 50;
		questName = "Hold " + toSecure->getName() + " for " + std::to_string(timeToHold) + " Cycles.";
		return true;
		break;
	case Enumerators::TypeOfQuest::secure:
		questName = "Secure " + toSecure->getName() + ".";
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

std::string Quest::getQuestName() const {
	return questName;
}