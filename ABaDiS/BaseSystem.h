#pragma once

#include "stdafx.h"

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
	
	// LEADER Section
	bool createMobLeader(Room*);
	bool createSecLeader(Room*);
	void printLeaders();
	bool recruit(Leader*);
	bool recruit(int);

	// Getters
	Leader* getLeader(int i);


private:
	std::vector<Room*> rooms;
	std::vector<Leader*> leaders;

	float tension;
};

