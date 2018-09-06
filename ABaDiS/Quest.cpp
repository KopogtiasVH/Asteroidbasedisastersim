#include "stdafx.h"
#include "Quest.h"

Quest::Quest() {
	name = "";
	description = "";
	status = false;
	toq = Enumerators::TypeOfQuest::generic;
	reward = {};
	alignment = Enumerators::Alignment::neutral;

}

void Quest::createQuestFlavor() {};
void Quest::assembleReward() {};

std::string Quest::getQuestName() 
{
	return name;
}

std::string Quest::getDescription() {
	return description;
}

Enumerators::TypeOfQuest Quest::getTypeOfQuest()
{
	return toq;
}

bool Quest::getStatus()
{
	return status;
}

Quest::questReward Quest::getReward()
{
	return reward;
}

Enumerators::Alignment Quest::getAlignment()
{
	return alignment;
}
