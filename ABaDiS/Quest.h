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

protected:
	bool finished;
	Enumerators::TypeOfQuest toq;
};

