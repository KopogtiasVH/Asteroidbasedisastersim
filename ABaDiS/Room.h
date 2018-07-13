#pragma once

#include "NameGenerator.h"
#include "stdafx.h"
#include <vector>
#include <string>

class Room
{
public:
	Room();
	Room(std::string);

	void printRoom();

	bool connectTo(Room);


	int getCapacity() const;
	int getCurrentCapacity() const;

	bool isIntact() const;
	bool enterRoom(int);

	std::string getName() const;
	std::vector<Room> getConnections() const;

	bool isConnectedTo(Room) const;

	int ID;

private:
	int maxCapacity;
	int currentCapacity;
	int population;

	bool intact;
	bool inSystem;

	std::vector<Room> connectedTo;
	std::string name;
};

