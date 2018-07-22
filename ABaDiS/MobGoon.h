#pragma once

#include "Being.h"
#include "Room.h"
#include "Leader.h"

class MobGoon : public Being
{
public:
	MobGoon(Room*);
	MobGoon(Leader*);

	void printBeingTable();
	void printBeingFlavor();

private:
	Leader* currentLeader;
};

