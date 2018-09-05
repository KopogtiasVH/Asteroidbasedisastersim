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

	virtual void createQuestFlavor();	// creates a questname and it's description
	virtual void assembleReward();		// creates the reward based on difficulty and type of quest

	// Getters
	std::string getQuestName();
	std::string getDescription();
	Enumerators::TypeOfQuest getTypeOfQuest();
	bool getStatus();
	questReward getReward();
	Enumerators::alignment getAlignment();

protected:
	std::string name;
	std::string description;
	bool status;
	Enumerators::TypeOfQuest toq;
	questReward reward;
	Enumerators::alignment alignment;
	
};

