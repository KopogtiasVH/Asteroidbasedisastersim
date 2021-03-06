#pragma once

#include "stdafx.h"
#include "Battle.h"

class BaseSystem
{
public:
	BaseSystem();
	BaseSystem(int);
	
	void step();

	// ROOM section
	bool createRoom();
	bool connectRooms(Room*, Room*);
	bool connectRooms(int, int);
	void printRooms();
	Room* getRandomRoom();
	void createBase(int);
	void createBaseDistributed(int, int);
	void setHiPRoomNames();
	
	// LEADER Section
	bool createMobLeader(Room*);
	bool createSecLeader(Room*);
	void printLeaders();
	bool recruit(Leader*);
	bool recruit(int);
	void addLeaders(int);
	Leader* getRandomLeader();
	MobLeader* getRandomMob();
	SecOfficer* getRandomSec();
	Leader* spawnTargetLeader(Room*, Enumerators::Faction, int);

	// BATTLE Section
	void createFight(Leader*, Leader*, Room*);
	void fight(Battle*);
	void fightAllBattles();
	void printBattleResult(Battle::battleResult);

	// Getters
	Leader* getLeader(int i);
	Battle* getBattle(int i);
	Room* getRoom(int i);
	std::vector<Battle>* getBattles();
	std::vector<Room*>* getRooms();
	std::vector<Leader*>* getLeaders();
	float getTension();

	// Clients
	void addClients();
	void printClients();

	// Population
	void addPopulation();
	
private:
	std::vector<Room*> rooms;
	std::vector<Leader*> leaders;
	std::vector<Battle> battles;
	std::vector<Client*> clients;
	std::vector<MobLeader*> mob;
	std::vector<SecOfficer*> sec;

	float tension;
};

