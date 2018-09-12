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

private:
	Being* client;
	Being* target;
};

