#pragma once
#include "PersonalQuest.h"
class RecruitingQuest :
	public PersonalQuest
{
public:
	RecruitingQuest(Being*);

	void createQuestFlavor();
	bool checkProgress();
	void wrapupQuest();

private:
	int recruited;
	int toRecruit;
};

