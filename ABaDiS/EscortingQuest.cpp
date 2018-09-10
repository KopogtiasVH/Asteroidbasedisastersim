#include "stdafx.h"
#include "EscortingQuest.h"


EscortingQuest::EscortingQuest(Being* e, Room* d) : DevelopingQuest()
{
	escort = e;
	destination = d;
}

#pragma region MAIN
void EscortingQuest::createQuestFlavor()
{
	name = "Escort " + escort->getSurName() + " to " + destination->getName() + ".";
	description = name;
}

void EscortingQuest::assembleReward()
{
}

bool EscortingQuest::checkProgress()
{
	return false;
}
#pragma endregion

#pragma region GETTERS
Being * EscortingQuest::getEscort() const
{
	return escort;
}

Room * EscortingQuest::getDestination() const
{
	return destination;
}
#pragma endregion




