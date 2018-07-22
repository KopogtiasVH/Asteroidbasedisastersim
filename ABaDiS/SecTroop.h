#pragma once
#include "Being.h"
#include "Room.h"
#include "Leader.h"

class SecTroop : public Being
{
public:
	SecTroop(Room*);
	SecTroop(Leader*);

	void printBeingTable();
	void printBeingFlavor();

private:
	Leader* currentLeader;
};

