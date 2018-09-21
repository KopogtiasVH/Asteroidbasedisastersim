#pragma once
#include "MilitaryQuest.h"
class SecureQuest :
	public MilitaryQuest
{
public:
	SecureQuest(Being*, Room*);

	void createQuestFlavor();
	void assembleReward();
	bool checkProgress();
	void activateQuest(Being*);
	void updateQuest();
	Enumerators::Desire getDesire();
	void wrapupQuest();

private:
	Being* client;
	Room* toSecure;
	Enumerators::Faction ownFaction;
	Enumerators::Faction otherFaction;
};

