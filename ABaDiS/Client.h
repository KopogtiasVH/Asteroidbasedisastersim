#pragma once
#include "Being.h"
class Client :
	public Being
{
public:
	Client(Room*);
	Quest* getAvailableQuest() const;

private:
	Quest* createQuest();

	Quest* availableQuest;
};