#pragma once
#include "DevelopingQuest.h"
class GatheringQuest :
	public DevelopingQuest
{
public:
	GatheringQuest(Being*);

	// Main Functions
	void createQuestFlavor();
	void assembleReward();
	bool checkProgress();
	void deliver();

	void updateQuest();

	// Getters
	Being* getOwner() const;
	Enumerators::Ressource getRessource() const;
	int needsGathered() const;
	int hasGathered() const;
	int hasDelivered() const;


private:
	Being* client;
	Enumerators::Ressource ressource;
	int toGather;
	int gathered;
	int delivered;
};

