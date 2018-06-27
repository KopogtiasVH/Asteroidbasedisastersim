#pragma once

#include "NameGenerator.h"

#include <vector>
#include <string>

class Room
{
public:
	Room();
	Room(std::string);

	int getCapacity() const;
	bool isIntact() const;
	std::string getName() const;
	std::vector<Room> isConnectedTo() const;

private:
	int capacity;
	bool intact;
	std::vector<Room> connectedTo;
	std::string name;

	void printRoom();
};

