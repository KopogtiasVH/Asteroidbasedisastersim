#pragma once
#include "Room.h"
class Corridor :
	public Room
{
public:
	Corridor();

	std::vector<Room> toFrom;

protected:
	Enumerators::KindOfRoom kor;
};

