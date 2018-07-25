#include "stdafx.h"
#include "Room.h"
#include <iostream>

/*
	A Room is a fictional Place in the Base. All things and fights are located inside them.
	Usually a Room is connected to other Rooms.
*/

Room::Room()
{
	currentCapacity = 0;
	maxCapacity = ((rand() % 20) + 1) * 10;
	priority = rand() % 10 + 1;
	maxCondition = maxCapacity * priority;
	currentCondition = maxCondition;
	intact = true;
	inSystem = false;
	connectedTo = std::vector<Room*>();

	ID = rand();

	name = NameGenerator::roomName(maxCapacity, priority);
	
	//printRoom();
}

Room::Room(std::string n_) 
{
	currentCapacity = 0;
	maxCapacity = ((rand() % 20) + 1) * 10;
	priority = rand() % 10 + 1;
	intact = true;
	inSystem = false;
	connectedTo = std::vector<Room*>();

	ID = rand();

	name = n_;

	//printRoom();
}

// Function to enter Room
bool Room::enterRoom(int toEnter) {
	if (currentCapacity + toEnter <= maxCapacity) {
		currentCapacity += toEnter;
		return true;
	}
	else {
		std::cerr << "Entering Squad is too big." << std::endl;
		return false;
	}
}

// Returns true if this Room is connected to other
bool Room::isConnectedTo(Room* toCheck) {
	for (Room* r : connectedTo)
		if (r == toCheck)
			return true;
	return false;
}

bool Room::connectTo(Room* toConnectTo) {
	connectedTo.push_back(toConnectTo);
	inSystem = true;
	return true;
}

/*
	Getter and Setter Functions
*/
int Room::getCapacity() const
{
	return maxCapacity;
}

int Room::getCurrentCapacity() const{
	return currentCapacity;
}

int Room::getPriority() const {
	return priority;
}

int Room::getCurrentCondition() const {
	return currentCondition;
}

int Room::getMaxCondition() const {
	return maxCondition;
}

bool Room::isIntact() const
{
	return intact;
}

std::string Room::getName() const
{
	return name;
}

std::vector<Room*> Room::getConnections() const
{
	return connectedTo;
}

// Function to Print the Room to the console.
void Room::printRoom() {
	std::cout << name << ":" << std::endl
		<< "	Capacity:  " << getCurrentCapacity() << " / " << getCapacity() << std::endl
		<< "	Condition: " << getCurrentCondition() << " / " << getMaxCondition() << std::endl
		<< "	Priority:  " << getPriority() << std::endl << std::endl;
}