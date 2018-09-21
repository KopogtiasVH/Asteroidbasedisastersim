#pragma once
#include "MilitaryQuest.h"
class HuntingQuest :
	public MilitaryQuest
{
public:
	HuntingQuest(Being* c, Being* t);
	HuntingQuest(Being* c);

	void createQuestFlavor();
	void assembleReward();
	bool checkProgress();
	void activateQuest(Being*);

	void updateQuest();
	Enumerators::Desire getDesire();
	void wrapupQuest();

private:
	Being* client;
	Being* target;
};