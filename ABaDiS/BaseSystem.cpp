#include "stdafx.h"
#include "BaseSystem.h"


BaseSystem::BaseSystem()
{
	rooms = std::vector<Room*>();
	leaders = std::vector<Leader*>();
	battles = std::vector<Battle>();

	tension = 0;
}

BaseSystem::BaseSystem(int noOfRooms) 
{
	rooms = std::vector<Room*>();
	leaders = std::vector<Leader*>();
	battles = std::vector<Battle>();

	tension = 0;

	createBase(noOfRooms);
}

// Generic Section



// ROOM Section

bool BaseSystem::createRoom() {
	rooms.push_back(new Room());
	return true;
}

bool BaseSystem::connectRooms(Room* a, Room* b) {
	if (a != b) {
		if (a->connectTo(b) && b->connectTo(a)) {
			Corridor* newCorridor = new Corridor(a, b);
			rooms.push_back(newCorridor);
			return true;
		}
		else {
			std::cerr << "Something went wrong" << std::endl;
			return false;
		}
	}
	else {
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

// Creates a new System with minimum number of rooms
void BaseSystem::createBase(int minimumNoOfRooms) {
	if (rooms.size() <= 0)
		rooms.push_back(new Room());
	Room* prev = rooms[rand() % rooms.size()];
	Room* a;
	if (rand() % 100 < 20) {
		a = new HiPRoom(rand() % 3 + 7);
		std::cout << "Hiproom generated" << std::endl;
	}
	else {
		a = new Room();
	}
	Room* b = new Room();
	rooms.push_back(a);
	rooms.push_back(b);
	connectRooms(a, b);
	connectRooms(prev, a);
	if (rooms.size() < minimumNoOfRooms)
		createBase(minimumNoOfRooms);
	else {
		for (int i = 0; i < minimumNoOfRooms / 10; i++) {
			Room* a = rooms[rand() % rooms.size()];
			Room* b = rooms[rand() % rooms.size()];
			if (!a->isConnectedTo(b))
				connectRooms(a, b);
			else --i;
		}
		setHiPRoomNames();
	}
}

// Creates a new System with minimum number of rooms and even priority distribution
void BaseSystem::createBaseDistributed(int minimumNoOfRooms, int p) {

}

void BaseSystem::printRooms() {
	for (Room* room : rooms) {
		room->printRoom();
	}
}

Room* BaseSystem::getRandomRoom() {
	return rooms[rand() % rooms.size()];
}

void BaseSystem::setHiPRoomNames() {
	for (Room* r : rooms) {
		if (dynamic_cast<HiPRoom*>(r)) {
			dynamic_cast<HiPRoom*>(r)->setName();
		}
	}
}

// LEADER Section

bool BaseSystem::createMobLeader(Room* r) {
	leaders.push_back(new MobLeader(r));
	return true;
}

bool BaseSystem::createSecLeader(Room* r) {
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

// Battle Section

void BaseSystem::createFight(Leader* a, Leader* b, Room* r) {
	battles.push_back(Battle(a, b, r));
}

void BaseSystem::fight(Battle* b) {
	Battle::battleResult* btr = b->fight();
	if (btr != NULL) {
		printBattleResult(*btr);
	}
}

void BaseSystem::fightAllBattles() {
	std::vector<Battle>::iterator it = battles.begin();
	while (it != battles.end()) {
		Battle* b = &*it;
		fight(b);
		if (!b->isFightOngoing()) {
			it = battles.erase(it);
		}
		else {
			++it;
		}
	}

}

void BaseSystem::printBattleResult(Battle::battleResult result) {
	std::cout << std::endl << result.title << ":" << std::endl;

	if (result.draw) {
		std::cout << "The " << result.title << " between " << result.winningLeader->getSquadName()
			<< " and " << result.losingLeader->getSquadName() << " ended in a draw." << std::endl;
	}
	else {
		std::cout << result.winningLeader->getSquadName() << " dominated over " << result.losingLeader->getSquadName()
			<< " in the " << result.title << "." << std::endl;
	}
	std::cout << result.bodyCount << " have been killed and " << result.woundedCount << " have been wounded." << std::endl
		<< "The Fighting lastet for " << result.noOfRounds << " cycles." << std::endl << std::endl;
}

// Getters

Leader* BaseSystem::getLeader(int i) {
	if (i <= leaders.size()) {
		return leaders[i];
	}
	else {
		std::cerr << "Index out of Bounds" << std::endl;
		return NULL;
	}
}

Battle* BaseSystem::getBattle(int i) {
	if (i <= battles.size()) {
		return &battles[i];
	}
	else {
		std::cerr << "Index out of bounds." << std::endl;
		return NULL;
	}
}

Room* BaseSystem::getRoom(int i) {
	if (i <= rooms.size()) {
		return rooms[i];
	}
	else {
		std::cerr << "Index out of Bounds." << std::endl;
	}
}

std::vector<Battle> BaseSystem::getBattles() {
	return battles;
}

std::vector<Room*> BaseSystem::getRooms() {
	return rooms;
}