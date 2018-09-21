#include "stdafx.h"
#include "RecruitingQuest.h"


RecruitingQuest::RecruitingQuest(Being* o)
{
	activateQuest(o);
	if (dynamic_cast<Leader*>(owner)) {
		Leader* oL = dynamic_cast<Leader*>(owner);
		recruited = oL->getSquad()->getSize();
		toRecruit = oL->getSquad()->getMaxSize() * 0.5;
		toRecruitTotal = oL->getSquad()->getSize() + toRecruit;
		if (toRecruitTotal > oL->getSquad()->getMaxSize())
			toRecruit = oL->getSquad()->getMaxSize() - oL->getSquad()->getSize();
		oL->statBoost(Enumerators::StatBoost::charisma, 3);
	}
	createQuestFlavor();
}

void RecruitingQuest::createQuestFlavor() {
	name = "Recruit" + std::to_string(toRecruit) + " new People to " + dynamic_cast<Leader*>(owner)->getSquadName() + ".";
	description = name;
}

bool RecruitingQuest::checkProgress() {
	return (recruited == toRecruitTotal);
}

void RecruitingQuest::updateQuest() {
	Leader* oL = dynamic_cast<Leader*>(owner);
	recruited = oL->getSquad()->getSize();
	status = checkProgress();
	if (status)
		wrapupQuest();
}

Enumerators::Desire RecruitingQuest::getDesire() {
	Leader* oL = dynamic_cast<Leader*>(owner);
	if (oL->getFaction() == Enumerators::Faction::ANARC) {
		if (oL->getCurrentLocation()->getKor() == Enumerators::KindOfRoom::livingQuarter) 
			return Enumerators::Desire::recruit;
		else 
			return Enumerators::Desire::traverse;
	}
	else if (oL->getFaction() == Enumerators::Faction::SEC) {
		if (oL->getCurrentLocation()->getKor() == Enumerators::KindOfRoom::security) 
			return Enumerators::Desire::recruit;
		else 
			return Enumerators::Desire::traverse;
	}
}

void RecruitingQuest::wrapupQuest() {
	dynamic_cast<Leader*>(owner)->statBoost(Enumerators::StatBoost::charisma, -3);
	delete(this);
}