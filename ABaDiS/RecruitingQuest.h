#pragma once
#include "PersonalQuest.h"
class RecruitingQuest :
	public PersonalQuest
{
public:
	RecruitingQuest(Being*);

	void createQuestFlavor();
	void updateQuest();
	bool checkProgress();
	void wrapupQuest();
	Enumerators::Desire getDesire();

private:
	int recruited;
	int toRecruit;
	int toRecruitTotal;
};

