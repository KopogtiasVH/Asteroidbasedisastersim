#include "stdafx.h"
#include "RecruitingQuest.h"


RecruitingQuest::RecruitingQuest(Being* o)
{
	activateQuest(o);
	if (dynamic_cast<Leader*>(owner)) {
		Leader* oL = dynamic_cast<Leader*>(owner);
		recruited = 0;
		toRecruit = oL->getSquad()->getMaxSize() * 0.5;
		oL->statBoost(Enumerators::StatBoost::charisma, 3);
	}
	createQuestFlavor();
}

void RecruitingQuest::createQuestFlavor() {
	name = "Recruit" + std::to_string(toRecruit) + " new People to " + dynamic_cast<Leader*>(owner)->getSquadName() + ".";
	description = name;
}

bool RecruitingQuest::checkProgress() {
	return (recruited == toRecruit);
}

void RecruitingQuest::wrapupQuest() {
	dynamic_cast<Leader*>(owner)->statBoost(Enumerators::StatBoost::charisma, -3);
}