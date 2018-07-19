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
	int getPriority() const;
	int getCurrentCondition() const;
	int getMaxCondition() const;

	bool isIntact() const;
	bool enterRoom(int);

	std::string getName() const;
	std::vector<Room> getConnections() const;

	bool isConnectedTo(Room) const;

	int ID;

protected:
	int maxCapacity;
	int currentCapacity;
	int population;
	int priority;
	int maxCondition;
	int currentCondition;

	bool intact;
	bool inSystem;

	std::vector<Room> connectedTo;
	std::string name;
};

