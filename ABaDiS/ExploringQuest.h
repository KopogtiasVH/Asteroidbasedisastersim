#pragma once
#include "PersonalQuest.h"
class ExploringQuest :
	public PersonalQuest
{
public:
	ExploringQuest(Being*);

	void createQuestFlavor();
	bool checkProgress();
	void updateQuest();
	void wrapupQuest();


private:
	int toExplore;
	int toExploreTotal;
	int explored;
};

