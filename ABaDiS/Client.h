#pragma once
#include "Being.h"

class Client :
	public Being
{
public:
	Client(Room*);

	// Getters
	Quest* getAvailableQuest() const;
	
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