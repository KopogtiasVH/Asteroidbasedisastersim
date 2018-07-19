#pragma once
#include "Room.h"
class Corridor : public Room
{
public:
	Corridor();
	Corridor(Room*, Room*);

	std::vector<Room*> toFrom;
	
	void printRoom() override;

protected:
	Enumerators::KindOfRoom kor;
};

