#pragma once
#include "Room.h"
class Corridor :
	public Room
{
public:
	Corridor(Room*, Room*);

	std::vector<Room*> toFrom;
	
	void printRoom();

protected:
	Enumerators::KindOfRoom kor;
};

