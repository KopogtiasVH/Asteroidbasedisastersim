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
	Enumerators::Desire getDesire();

private:
	int toExplore;
	int toExploreTotal;
	int explored;
};

