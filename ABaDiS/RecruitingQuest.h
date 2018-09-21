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

private:
	int recruited;
	int toRecruit;
	int toRecruitTotal;
};

