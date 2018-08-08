#pragma once

#include "NameGenerator.h"
#include "stdafx.h"
#include <vector>
#include <string>

class Room
{
public:

	// Constructors
	Room();
	Room(int);
	Room(std::string);

	// Helpers
	bool connectTo(Room*);
	bool enterRoom(int);
	bool isConnectedTo(Room*);

	// Getters
	int getCapacity() const;
	int getCurrentCapacity() const;
	int getPriority() const;
	int getCurrentCondition() const;
	int getMaxCondition() const;

	bool isIntact() const;
	bool isEmpty() const;

	std::string getName() const;
	std::vector<Room*> getConnections() const;
	Enumerators::KindOfRoom getKor() const;

	// Printers
	virtual void printRoom();

protected:

	// Statistics
	int maxCapacity;
	int currentCapacity;
	int population;
	int priority;
	int maxCondition;
	int currentCondition;

	bool intact;
	bool inSystem;

	std::vector<Room*> connectedTo;

	std::string name;

	Enumerators::KindOfRoom kor;
};

