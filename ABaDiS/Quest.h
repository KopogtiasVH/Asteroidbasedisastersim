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

	Quest(Enumerators::TypeOfQuest, int, int, int, int, Enumerators::statBoost, Room*);

	// Helpers
	bool createQuest();
	bool updateQuest();

	// Getters
	Enumerators::TypeOfQuest getTypeOfQuest() const;
	bool isDone() const;

private:

	Enumerators::TypeOfQuest typeOfQuest;
	questReward reward;
	bool finished;

	// Gather Quest
	int gathered;
	int needsGathered;

	// Holding Quest
	int timeHolding;
	int timeToHold;

	// Secureing Quest
	Room* toSecure;
};

