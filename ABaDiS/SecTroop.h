#pragma once

#include "stdafx.h"

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

