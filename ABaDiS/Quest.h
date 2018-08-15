#pragma once
#include "Room.h"

class Quest
{
public:
	
	struct questReward {
		int scrap;
		int food;
		int weapons;
		int availableRecruits;
		Enumerators::statBoost statBoost;
	};

	// Regular Quest
	Quest(Enumerators::TypeOfQuest, int, int, int, int, Enumerators::statBoost, Room*, Room*, Enumerators::Faction);

	// Recruiting "Quest"
	Quest(Enumerators::TypeOfQuest, int, int);

	// Helpers
	bool createQuest();
	bool isQuestFinished();
	void nextTask();

	// Getters
	Enumerators::TypeOfQuest getTypeOfQuest() const;
	bool isDone() const;
	std::string getQuestName() const;

private:

	Room* originRoom;
	Enumerators::TypeOfQuest typeOfQuest;
	Enumerators::ressource ttg;
	Enumerators::Faction ownFaction;
	questReward reward;
	bool finished;
	std::string questName;

	// Gather Quest
	int gathered;
	int needsGathered;

	// Holding Quest
	int timeHolding;
	int timeToHold;

	// Secureing Quest
	Room* toSecure;
};

