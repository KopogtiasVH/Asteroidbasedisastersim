#pragma once
class Map
{
public:
	Map();

	// Helpers
	bool contains(std::vector<Room*>, Room*);
	bool findShortestRoute(Room*, Room*);

private:
	std::vector<Room*> knownRooms;
	std::vector<Room*> route;
	Room* currentTarget;
	Room* nextTarget;
};