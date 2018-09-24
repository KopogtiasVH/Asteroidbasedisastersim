#include "stdafx.h"
#include "GatheringQuest.h"

GatheringQuest::GatheringQuest(Being* c) : DevelopingQuest()
{
	client = c;
	switch (rand() % 3) {
	case 0:
		ressource = Enumerators::Ressource::food;
		break;
	case 1:
		ressource = Enumerators::Ressource::scrap;
		break;
	case 2:
		ressource = Enumerators::Ressource::meds;
		break;
	default:
		std::cerr << "Wrong random number generated" << std::endl;
	}
	toGather = (rand() % 50 + 50);
	gathered = 0;
	delivered = 0;
	createQuestFlavor();
}

#pragma region MAIN
void GatheringQuest::createQuestFlavor()
{
	std::string ressourceNoun;
	switch (ressource) {
	case Enumerators::Ressource::food:
		ressourceNoun = "food";
		break;
	case Enumerators::Ressource::scrap:
		ressourceNoun = "scrap";
		break;
	case Enumerators::Ressource::meds:
		ressourceNoun = "meds";
		break;
	default:
		std::cerr << "Wrong ressource assigned" << std::endl;
		break;
	}
	name = "Gather " + std::to_string(toGather) + " " + ressourceNoun + ".";
	description = "Gather " + std::to_string(toGather) + " " + ressourceNoun +
		" and deliver it to " + client->getSurName() + ".";
}

void GatheringQuest::assembleReward()
{
}

bool GatheringQuest::checkProgress()
{
	return (gathered + delivered == toGather);
}

void GatheringQuest::deliver()
{
	if (dynamic_cast<Leader*>(owner)) {
		Leader* oL = dynamic_cast<Leader*>(owner);
		int toDeliver = oL->getSquad()->getInventory()->returnRessource(ressource);
		delivered += toDeliver;
		oL->getSquad()->getInventory()->addToInventory(ressource, toDeliver * -1);
	}
}

Enumerators::Desire GatheringQuest::getDesire()
{
	Leader* oL = dynamic_cast<Leader*>(owner);
	if (!status && !oL->getSquad()->getInventory()->isFull())
		return Enumerators::Desire::scavenge;
	else if (!status && oL->getSquad()->getInventory()->isFull())
		return Enumerators::Desire::deliver;
	else if (status)
		return Enumerators::Desire::returnToClient;
	else
		std::cerr << "Error at gathering quest desire dispensing" << std::endl;
}

void GatheringQuest::updateQuest()
{
	if (dynamic_cast<Leader*>(owner)) {
		Leader* oL = dynamic_cast<Leader*>(owner);
		gathered = oL->getSquad()->getInventory()->returnRessource(ressource);
	}
	status = checkProgress();
}
#pragma endregion


#pragma region GETTERS
Being * GatheringQuest::getOwner() const
{
	return owner;
}

Enumerators::Ressource GatheringQuest::getRessource() const
{
	return ressource;
}

int GatheringQuest::needsGathered() const
{
	return toGather;
}

int GatheringQuest::hasGathered() const
{
	return gathered;
}

int GatheringQuest::hasDelivered() const {
	return delivered;
}
#pragma endregion






