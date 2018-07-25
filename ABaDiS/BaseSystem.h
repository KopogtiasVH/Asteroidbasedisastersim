#pragma once

#include "stdafx.h"
#include "Battle.h"

class BaseSystem
{
public:
	BaseSystem();
	
	void step();

	bool allowRecruitment();

	// ROOM section
	bool createRoom();
	bool connectRooms(Room*, Room*);
	bool connectRooms(int, int);
	void printRooms();
	Room* getRandomRoom();
	void createBase(int);
	
	// LEADER Section
	bool createMobLeader(Room*);
	bool createSecLeader(Room*);
	void printLeaders();
	bool recruit(Leader*);
	bool recruit(int);

	// BATTLE Section
	void createFight(Leader*, Leader*, Room*);
	void fight(Battle*);
	void fightAllBattles();
	void printBattleResult(Battle::battleResult);

	// Getters
	Leader* getLeader(int i);
	Battle* getBattle(int i);
	Room* getRoom(int i);
	std::vector<Battle> getBattles();
	std::vector<Room*> getRooms();
	


private:
	std::vector<Room*> rooms;
	std::vector<Leader*> leaders;
	std::vector<Battle> battles;

	float tension;
};

