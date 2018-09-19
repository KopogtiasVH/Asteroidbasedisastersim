#include "stdafx.h"
#include "Map.h"


Map::Map()
{
	knownRooms = std::multimap<Room*, Room*>();
	route = std::vector<Room*>();
	currentTarget = nullptr;
	nextTarget = nullptr;
}

bool Map::contains(std::vector<Room*> list, Room* toCheck) {
	for (Room* r : list) {
		if (r == toCheck)
			return true;
	}
	return false;
}

bool Map::contains(std::multimap<Room*, Room*> list, Room* toCheck) {
	return (list.find(toCheck)->first != nullptr);
}

void Map::addRoom(Room* toAdd) {
	for (Room* i : toAdd->getConnections()) {
		knownRooms.insert(std::make_pair(toAdd, i));
		knownRooms.insert(std::make_pair(i, toAdd));
	}
}


bool Map::findShortestRoute(Room* from, Room* to) {
if (!contains(knownRooms, to) || !contains(knownRooms, from))
return false;
int recordShortest = INT_MAX;
std::vector<Room*> traversedRooms;
Room* currentRoom = from;
start:
traversedRooms.push_back(currentRoom);
if (knownRooms.count(currentRoom) > 1 && knownRooms.find(currentRoom)->second == to) {
route = traversedRooms;
return true;
}
else if (knownRooms.count(currentRoom) > 1 && !contains(traversedRooms, knownRooms.find(currentRoom)->second)) {
currentRoom = knownRooms.find(currentRoom)->second;
goto start;
} else {
for (auto i = knownRooms.equal_range(currentRoom).first;
i != knownRooms.equal_range(currentRoom).second; ++i) {
if (i->second == to) {
route = traversedRooms;
return true;
}
}
for (auto i = knownRooms.equal_range(currentRoom).first;
i != knownRooms.equal_range(currentRoom).second; ++i) {
if (!contains(traversedRooms, i->second)) {
currentRoom = i->second;
goto start;
}
}
}
return false;
}
