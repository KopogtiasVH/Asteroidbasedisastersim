#pragma once
#include "DevelopingQuest.h"
class EscortingQuest :
	public DevelopingQuest
{
public:
	EscortingQuest(Being*, Room*);

	// Main Functions
	void createQuestFlavor();
	void assembleReward();
	bool checkProgress();

	// Getters
	Being* getEscort() const;
	Room* getDestination() const;

private:
	Being * escort;
	Room* destination;
};

