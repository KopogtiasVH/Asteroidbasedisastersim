#include "stdafx.h"
#include "HuntingQuest.h"


HuntingQuest::HuntingQuest(Being* c, Being* t) : MilitaryQuest()
{
	client = c;
	target = t;
	createQuestFlavor();
}

HuntingQuest::HuntingQuest(Being* c) : MilitaryQuest() {
	client = c;
	target = nullptr;
	createQuestFlavor();
}

void HuntingQuest::createQuestFlavor() {
	if (target == nullptr) {
		name = "Hunting Quest";
		description = name;
	}
	else {
		name = "Kill " + target->getSurName() + ".";
		description = "Kill " + target->getSurName() + " and report back to " + client->getSurName() + ".";
	}
}

void HuntingQuest::assembleReward()
{
}

bool HuntingQuest::checkProgress()
{
	return false;
}

void HuntingQuest::activateQuest(Being* o) {
	owner = o;
	active = true;
	if (dynamic_cast<Leader*>(o)) {
		Leader* oL = dynamic_cast<Leader*>(o);
		switch (oL->getFaction()) {
		case Enumerators::Faction::ANARC:
			target = BaseSystemHandler::getRandomSecOfficer();
			break;
		case Enumerators::Faction::SEC:
			target = BaseSystemHandler::getRandomMobLeader();
			break;
		default:
			std::cerr << "Faction does not exist" << std::endl;
			break;
		}
	}
	else {
		std::cerr << "Non-Leaders can't activate quests" << std::endl;
	}
	createQuestFlavor();
}
