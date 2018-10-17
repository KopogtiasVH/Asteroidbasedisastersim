#pragma once
#include "Being.h"
#include "Leader.h"

class Client :
	public Being
{
public:
	Client(Room*);

	// Getters
	Quest* getAvailableQuest() const;
	Quest* hasAvailableQuest();
	
	// Helpers
	Quest* assignQuest(Being*);
	void finishQuest();

	// Printers
	void printBeingTable();

private:
	Quest* createQuest();
	Room* getValidRoom();

	Quest* availableQuest;
};