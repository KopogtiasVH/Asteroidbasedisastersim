#include "stdafx.h"
#include "EscortingQuest.h"


EscortingQuest::EscortingQuest(Being* e, Room* d) : DevelopingQuest()
{
	client = e;
	destination = d;
	createQuestFlavor();
}

#pragma region MAIN
void EscortingQuest::createQuestFlavor()
{
	name = "Escort " + client->getSurName() + " to " + destination->getName() + ".";
	description = name;
}

void EscortingQuest::assembleReward()
{
}

bool EscortingQuest::checkProgress()
{
	return (client->getCurrentLocation() == destination);
}

void EscortingQuest::updateQuest() {
	status = checkProgress();
	if (status && client->getCurrentLocation() == owner->getCurrentLocation())
		wrapupQuest();
}

Enumerators::Desire EscortingQuest::getDesire() {
	Leader* oL = dynamic_cast<Leader*>(owner);
	if (!status && oL->knowsRoom(destination))
		return Enumerators::Desire::traverse;
	else if (!status && !oL->knowsRoom(destination))
		return Enumerators::Desire::explore;
	else if (status)
		return Enumerators::Desire::returnToClient;
	else
		std::cerr << "Error at desire dispension for escorting quest" << std::endl;
}

#pragma endregion

#pragma region GETTERS
Being * EscortingQuest::getEscort() const
{
	return client;
}

Room * EscortingQuest::getDestination() const
{
	return destination;
}
#pragma endregion




