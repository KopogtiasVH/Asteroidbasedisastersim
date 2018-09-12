#include "stdafx.h"
#include "SecureQuest.h"


SecureQuest::SecureQuest(Being* c, Room* tS) : MilitaryQuest()
{
	client = c;
	toSecure = tS;
	ownFaction = Enumerators::Faction::NONE;
	otherFaction = Enumerators::Faction::NONE;
	createQuestFlavor();
}

void SecureQuest::createQuestFlavor()
{
	switch (ownFaction) {
	case Enumerators::Faction::NONE:
		name = "Secure Quest";
		description = name;
		break;
	case Enumerators::Faction::ANARC:
		name = "Secure " + toSecure->getName() + ".";
		description = "Clean " + toSecure->getName() + " of all Security presence and report back to " + client->getSurName() + ".";
		break;
	case Enumerators::Faction::SEC:
		name = "Secure " + toSecure->getName() + ".";
		description = "Clean " + toSecure->getName() + " of all Anarchist presence and report back to " + client->getSurName() + ".";
		break;
	default:
		std::cerr << "Wrong Faction assigned" << std::endl;
		break;
	}
}

void SecureQuest::assembleReward()
{
}

bool SecureQuest::checkProgress()
{
	return !toSecure->isPresent(otherFaction);
}

void SecureQuest::activateQuest(Being * o)
{
	owner = o;
	if (dynamic_cast<Leader*>(o)) {
		Leader* oL = dynamic_cast<Leader*>(o);
		ownFaction = oL->getFaction();
		switch (ownFaction) {
		case Enumerators::Faction::ANARC:
			otherFaction = Enumerators::Faction::SEC;
			break;
		case Enumerators::Faction::SEC:
			otherFaction = Enumerators::Faction::ANARC;
			break;
		default:
			std::cerr << "False ownFaction assigned" << std::endl;
			break;
		}
	}
	createQuestFlavor();
}