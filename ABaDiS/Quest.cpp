#include "stdafx.h"
#include "Quest.h"

Quest::Quest() {
	name = "";
	description = "";
	status = false;
	toq = Enumerators::TypeOfQuest::generic;
	reward = {};
	alignment = Enumerators::Alignment::neutral;
	owner = nullptr;
}

Quest::Quest(Being* o) {
	name = "";
	description = "";
	status = false;
	toq = Enumerators::TypeOfQuest::generic;
	reward = {};
	alignment = Enumerators::Alignment::neutral;
	owner = o;
}

// creates a questName and it's description
void Quest::createQuestFlavor() {};

// creates the reward based on difficulty and type of quest
void Quest::assembleReward() {}

void Quest::updateQuest() {}

// check if the quest is completed yet
bool Quest::checkProgress()
{
	return false;
};

// Make the quest ready to assign to a leader
void Quest::activateQuest(Being* o) {
	owner = o;
	active = true;
}

Enumerators::Desire Quest::getDesire() {
	return Enumerators::Desire::idle;
}

void Quest::wrapupQuest()
{
}

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

Being * Quest::getClient()
{
	return client;
}
