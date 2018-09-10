#pragma once
#include "Being.h"
#include "Leader.h"

class Client :
	public Being
{
public:
	Client(Room*);
	Quest* getAvailableQuest() const;
	Quest* assignQuest(Being*);

private:
	Quest* createQuest();
	Room* getValidRoom();

	Quest* availableQuest;
};