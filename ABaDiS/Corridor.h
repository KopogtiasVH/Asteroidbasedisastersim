#pragma once
#include "Room.h"
class Corridor : public Room
{
public:
	Corridor();
	Corridor(Room*, Room*);
	
	void printRoom() override;

protected:

};

