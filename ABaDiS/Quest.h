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
		Enumerators::StatBoost statBoost;
	};

	Quest();
	Quest(Being*);

	virtual void createQuestFlavor();	// creates a questname and it's description
	virtual void assembleReward();		// creates the reward based on difficulty and type of quest
	virtual bool checkProgress();		// check if the requirements are met
	virtual void activateQuest(Being*);	// activate the quest so no other Leader can take it while the other is away to fullfill it
	virtual void wrapupQuest();			// prepare the quest for deletion

	// Getters
	std::string getQuestName();
	std::string getDescription();
	Enumerators::TypeOfQuest getTypeOfQuest();
	bool getStatus();
	questReward getReward();
	Enumerators::Alignment getAlignment();

protected:
	std::string name;
	std::string description;
	bool status;
	bool active;
	Enumerators::TypeOfQuest toq;
	questReward reward;
	Enumerators::Alignment alignment;
	Being* owner;
	
};

