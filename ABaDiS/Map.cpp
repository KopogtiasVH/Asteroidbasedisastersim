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

bool Map::knows(Room* toCheck) {
	return contains(knownRooms, toCheck);
}

bool Map::knowsOther(Enumerators::KindOfRoom kor, Room* except) {
	for (Room* r : knownRooms) {
		if (r->getKor() == kor && r != except)
			return true;
	}
	return false;
}

bool Map::findRoomWithAvailableQuest(Room * from)
{
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

	auto flipMap = sortByValue(dist);
	for (auto r : flipMap) {
		if (dynamic_cast<HiPRoom*>(r.second)) {
			HiPRoom* hr = dynamic_cast<HiPRoom*>(r.second);
			if (hr->getClient()->hasAvailableQuest());
			findShortestRoute(from, r.second);
			std::cout << hr->getName() << " - Distance: " << dist.find(hr)->second << std::endl;
			hr->printRoom();
			return true;
		}
	}

	return false;
}

std::multimap<int, Room*> Map::sortByValue(std::map<Room*, int> m)
{
	std::multimap<int, Room*> flipMap = std::multimap<int, Room*>();
	for (auto r : m)
		flipMap.insert(std::make_pair(r.second, r.first));
	return flipMap;
}

void Map::addRoom(Room* toAdd) {
	if (!contains(knownRooms, toAdd))
		knownRooms.push_back(toAdd);
}

bool Map::findShortestRoute(Room* from, Room* to) {
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
			return true;
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
	return false;
}

bool Map::findSpecificRoom(Enumerators::KindOfRoom kor, Room* from)
{
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

	auto flipMap = sortByValue(dist);
	for (auto r : flipMap) {
		if (r.second->getKor() == kor && r.second != from) {
			findShortestRoute(from, r.second);
			return true;
		}
	}

	return false;
}

bool Map::findNearestRoomWithRessource(Enumerators::Ressource ressource, Room* from)
{
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
	
	auto flipMap = sortByValue(dist);
	for (auto r : flipMap) {
		if (dynamic_cast<HiPRoom*>(r.second)) {
			HiPRoom* hr = dynamic_cast<HiPRoom*>(r.second);
			if (hr->hasRessource(ressource));
			findShortestRoute(from, r.second);
			return true;
		}
	}
	
	return false;
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

std::vector<Room*> Map::getRoute()
{
	return route;
}

int Map::getSize() const
{
	return knownRooms.size();
}
