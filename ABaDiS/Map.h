#pragma once
#include <map>

class Map
{
public:
	Map();

	// Helpers
	bool contains(std::vector<Room*>, Room*);
	bool contains(std::multimap<Room*, Room*>, Room*);

	bool findShortestRoute(Room*, Room*);

	void addRoom(Room*);

private:
	std::multimap<Room*, Room*> knownRooms;
	std::vector<Room*> route;
	Room* currentTarget;
	Room* nextTarget;
};
