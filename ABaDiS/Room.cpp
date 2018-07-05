#include "stdafx.h"
#include "Room.h"
#include <iostream>

/*
	A Room is a fictional Place in the Base. All things and fights are located inside them.
	Usually a Room is connected to other Rooms.
*/

Room::Room()
{
	capacity = ((rand() % 20) + 1) * 10;
	intact = true;
	connectedTo = std::vector<Room>();

	name = NameGenerator::lowCapRoomName(capacity);
	
	//printRoom();
}

Room::Room(std::string n_) 
{
	capacity = ((rand() % 20) + 1) * 10;
	intact = true;
	connectedTo = std::vector<Room>();

	name = n_;

	//printRoom();
}

int Room::getCapacity() const
{
	return capacity;
}

bool Room::isIntact() const
{
	return intact;
}

std::string Room::getName() const
{
	return name;
}

std::vector<Room> Room::isConnectedTo() const
{
	return connectedTo;
}


void Room::printRoom() {
	std::cout << name << ":" << std::endl 
		<< "	Capacity: " << getCapacity() << std::endl << std::endl;
}