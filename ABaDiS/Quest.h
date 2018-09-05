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

	Quest();

	// Getters
	std::string getQuestName();

protected:
	bool finished;
	std::string questName;
	Enumerators::TypeOfQuest toq;
};

