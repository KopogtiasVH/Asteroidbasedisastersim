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

	enum typeToGather {
		food,
		scrap,
		none
	};

	// Regular Quest
	Quest(Enumerators::TypeOfQuest, int, int, int, int, Enumerators::statBoost, Room*, Room*);

	// Recruiting "Quest"
	Quest(Enumerators::TypeOfQuest, int, int);

	// Helpers
	bool createQuest();
	bool updateQuest();

	// Getters
	Enumerators::TypeOfQuest getTypeOfQuest() const;
	bool isDone() const;

private:

	Room* originRoom;
	Enumerators::TypeOfQuest typeOfQuest;
	typeToGather ttg;
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

