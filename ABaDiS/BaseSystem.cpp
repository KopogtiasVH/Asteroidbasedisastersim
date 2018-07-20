#include "stdafx.h"
#include "BaseSystem.h"


BaseSystem::BaseSystem()
{
	rooms = std::vector<Room*>();
	leaders = std::vector<Leader*>();

	tension = 0;
}

bool BaseSystem::connectRooms(Room* a, Room* b) {
	if (a != b) {
		if (a->connectTo(b) && b->connectTo(a)) {
			Corridor* newCorridor = new Corridor(a, b);
			rooms.push_back(newCorridor);
			return true;
		} else {
			std::cerr << "Something went wrong" << std::endl;
			return false;
		}
	} else {
		std::cerr << "You can't connect a Room to itself" << std::endl;
		return false;
	}
}

bool BaseSystem::connectRooms(int a, int b) {
	if (a <= rooms.size() &&
		b <= rooms.size() &&
		a != b) {
		if (connectRooms(rooms[a], rooms[b])) {
			return true;
		}
		else {
			std::cerr << "Something went wrong" << std::endl;
			return false;
		}
	}
	else {
		std::cerr << "One of the Indices is out of bounds" << std::endl;
		return false;
	}
}

void BaseSystem::printRooms() {
	for (Room* room : rooms) {
		room->printRoom();
	}
}

bool BaseSystem::createRoom() {
	rooms.push_back(new Room());
	return true;
}

bool BaseSystem::createMobLeader(Room r) {
	leaders.push_back(new MobLeader(r));
	return true;
}

Room* BaseSystem::getRandomRoom() {
	return rooms[rand() % rooms.size()];
}

bool BaseSystem::createSecLeader(Room r) {
	leaders.push_back(new SecOfficer(r));
	return true;
}

void BaseSystem::printLeaders() {
	for (Leader* leader : leaders) {
		leader->printBeingTable();
		leader->printSquad();
	}
}

bool BaseSystem::recruit(Leader* l) {
	if (l->recruit())
		return true;
	return false;
}

bool BaseSystem::recruit(int i) {
	if (i <= leaders.size()) {
		return recruit(leaders[i]);
	}
	return false;
}