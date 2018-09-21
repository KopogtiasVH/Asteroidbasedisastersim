#include "stdafx.h"
#include "Map.h"
#include <map>
#include <set>


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

bool Map::knows(Room* toCheck) {
	return contains(knownRooms, toCheck);
}

void Map::addRoom(Room* toAdd) {
	if (!contains(knownRooms, toAdd))
		knownRooms.push_back(toAdd);
}

std::vector<Room*> Map::findShortestRoute(Room* from, Room* to) {
	std::vector<Room*> graph = knownRooms;
	std::vector<Room*> S;
	std::set<Room*> Q;
	std::map<Room*, int> dist;
	std::map<Room*, Room*> prev;
	for (Room* r : graph) {
		dist.insert(std::make_pair(r, INT_MAX));
		prev.insert(std::make_pair(r, nullptr));
		Q.insert(r);
	}
	dist.find(from)->second = 0;

	while (!Q.empty()) {
		Room* u = nullptr;
		int dist_temp = INT_MAX;
		for (Room* r : Q) {
			if (dist.find(r)->second < dist_temp) {
				u = r;
				dist_temp = dist.find(r)->second;
			}

		}
		if (u == to) {
			std::cout << "Found Route" << std::endl;
			if (prev.find(u)->second != nullptr || u == from) {
				while (u != nullptr) {
					S.insert(S.begin(), u);
					u = prev.find(u)->second;
				}
			}
			route = S;
			return S;
		}
		Q.erase(u);
		for (Room* v : u->getConnections()) {
			if (contains(knownRooms, v)) {
				int alt = dist.find(u)->second + 1;
				if (alt < dist.find(v)->second) {
					dist.find(v)->second = alt;
					prev.find(v)->second = u;
				}
			}
		}
	}

	route = S;
	return S;
}

void Map::printRoute() {
	std::cout << std::endl;
	for (Room* r : route)
		std::cout << r->getName() << std::endl;
	std::cout << std::endl;
}

void Map::printMap() {
	std::cout << "The Map contains: " << std::endl;
	for (Room* r : knownRooms) {
		std::cout << r->getName() << std::endl;
	}
	std::cout << std::endl;
}

std::vector<Room*>* Map::getKnownRooms()
{
	return &knownRooms;
}

int Map::getSize() const
{
	return knownRooms.size();
}
