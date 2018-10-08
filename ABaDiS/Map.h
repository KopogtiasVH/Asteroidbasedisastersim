#pragma once

#include <map>
#include <set>
#include <algorithm>

class Map
{
public:
	Map();

	// Helpers
	bool contains(std::vector<Room*>, Room*);
	bool knows(Room*);
	std::multimap<int, Room*> sortByValue(std::map<Room*, int>);

	bool findShortestRoute(Room*, Room*);
	Room* findSpecificRoom(Enumerators::KindOfRoom);
	bool findNearestRoomWithRessource(Enumerators::Ressource, Room*);

	void addRoom(Room*);

	// Printers
	void printRoute();
	void printMap();

	// Getters
	std::vector<Room*>* getKnownRooms();
	std::vector<Room*> getRoute();
	int getSize() const;

private:
	std::vector<Room*> knownRooms;
	std::vector<Room*> route;
	Room* currentTarget;
	Room* nextTarget;
};
