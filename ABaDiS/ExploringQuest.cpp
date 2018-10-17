#include "stdafx.h"
#include "ExploringQuest.h"


ExploringQuest::ExploringQuest(Being* o)
{
	activateQuest(o);
	if (dynamic_cast<Leader*>(o)) {
		Leader* oL = dynamic_cast<Leader*>(o);
		explored = oL->getMap()->getSize();
		toExplore = rand() % 5 + 5;
		toExploreTotal = explored + toExplore;
	}
	else {
		std::cerr << "Non Leaders shouldn't be able to accept quests" << std::endl;
		delete(this);
	}
	createQuestFlavor();
}

void ExploringQuest::createQuestFlavor() {
	name = "Explore " + std::to_string(toExplore) + " Rooms.";
	description = "Add " + std::to_string(toExplore) + " new Rooms to your map.";
}

bool ExploringQuest::checkProgress() {
	return (explored >= toExploreTotal);
}

void ExploringQuest::updateQuest() {
	Leader* oL = dynamic_cast<Leader*>(owner);
	explored = oL->getMap()->getSize();
	status = checkProgress();
	if (status || BaseSystemHandler::getNoOfRooms() <= oL->getMap()->getSize()) {
		wrapupQuest();
	}
}

Enumerators::Desire ExploringQuest::getDesire() {
	if (!status) {
		return Enumerators::Desire::explore;
	}
}

void ExploringQuest::wrapupQuest() {
	delete(this);
}