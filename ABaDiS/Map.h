#pragma once

class Map
{
public:
	Map();

	// Helpers
	bool contains(std::vector<Room*>, Room*);
	bool knows(Room*);

	std::vector<Room*> findShortestRoute(Room*, Room*);
	Room* findSpecificRoom(Enumerators::KindOfRoom);

	void addRoom(Room*);

	// Printers
	void printRoute();
	void printMap();

	// Getters
	std::vector<Room*>* getKnownRooms();
	int getSize() const;

private:
	std::vector<Room*> knownRooms;
	std::vector<Room*> route;
	Room* currentTarget;
	Room* nextTarget;
};
