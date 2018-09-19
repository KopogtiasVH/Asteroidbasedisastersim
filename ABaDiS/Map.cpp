#include "stdafx.h"
#include "Map.h"


Map::Map()
{
	knownRooms = std::vector<Room*>();
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

bool Map::findShortestRoute(Room* from, Room* to) {
	if (!contains(knownRooms, to) || !contains(knownRooms, from))
		return false;
	int recordShortest = 0;
findingLoop:
	int currentShortest = 0;
	Room* currentRoomIterator = from;
	while (!contains(route, to) && !contains(route, from)) {
		std::vector<Room*> connections = currentRoomIterator->getConnections();
	}
	

}