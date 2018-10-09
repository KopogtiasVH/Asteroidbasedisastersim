#include "stdafx.h"
#include "Room.h"

/*
	A Room is a fictional Place in the Base. All things and fights are located inside them.
	Usually a Room is connected to other Rooms.
*/

Room::Room()
{
	currentCapacity = 0;
	maxCapacity = ((rand() % 20) + 1) * 10;
	priority = rand() % 6 + 1;
	maxCondition = maxCapacity * priority;
	currentCondition = maxCondition;

	intact = true;
	inSystem = false;

	connectedTo = std::vector<Room*>();

	waitingGoons = std::vector<MobGoon*>();
	waitingTroops = std::vector<SecTroop*>();

	name = NameGenerator::roomName(maxCapacity, priority);
	kor = Enumerators::KindOfRoom::generic;
	presence = Enumerators::Faction::NONE;
}

Room::Room(int p)
{
	currentCapacity = 0;
	maxCapacity = ((rand() % 20) + 1) * 10;
	priority = p;
	maxCondition = maxCapacity * priority;
	currentCondition = maxCondition;

	intact = true;
	inSystem = false;

	connectedTo = std::vector<Room*>();

	waitingGoons = std::vector<MobGoon*>();
	waitingTroops = std::vector<SecTroop*>();

	name = NameGenerator::roomName(maxCapacity, priority);
	kor = Enumerators::KindOfRoom::generic;
	presence = Enumerators::Faction::NONE;
}

// Helper Methods

// Connects this Room to the other
bool Room::connectTo(Room* toConnectTo) {
	connectedTo.push_back(toConnectTo);
	inSystem = true;
	return true;
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

// Raises the capacity
bool Room::enteringBeings(int i) {
	if (currentCapacity + i <= maxCapacity) {
		currentCapacity += i;
		return true;
	}
	std::cerr << "Squad too Big" << std::endl;
	return false;
}

void Room::addWaitingGoons(MobGoon* toAdd)
{
	waitingGoons.push_back(toAdd);
}

void Room::addWaitingTroops(SecTroop* toAdd)
{
	waitingTroops.push_back(toAdd);
}

void Room::setPresence(Enumerators::Faction setFaction)
{
	presence = setFaction;
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

bool Room::isEmpty() const
{
	return (currentCapacity == 0);
}

bool Room::isPresent(Enumerators::Faction faction) const{
	return (faction == presence);
}

bool Room::hasWaitingGoons() const
{
	return waitingGoons.size() > 0;
}

bool Room::hasWaitingTroops() const
{
	return waitingTroops.size() > 0;
}

std::string Room::getName() const
{
	return name;
}

std::vector<Room*> Room::getConnections() const
{
	return connectedTo;
}

Enumerators::KindOfRoom Room::getKor() const
{
	return kor;
}

// Function to Print the Room to the console.
void Room::printRoom() {
	std::cout << name << ":" << std::endl
		<< "	Capacity:  " << getCurrentCapacity() << " / " << getCapacity() << std::endl
		<< "	Condition: " << getCurrentCondition() << " / " << getMaxCondition() << std::endl
		<< "	Priority:  " << getPriority() << std::endl << std::endl;
}