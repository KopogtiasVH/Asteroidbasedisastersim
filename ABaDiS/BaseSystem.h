#pragma once
#include "stdafx.h"
#include "Room.h"
#include"Corridor.h"

class BaseSystem
{
public:
	BaseSystem();
	
	void step();

	bool allowRecruitment();

	bool createRoom();
	bool connectRooms(Room, Room);
	bool connectRooms(int, int);

	void printRooms();
	
private:
	std::vector<Room> rooms;
	std::vector<Corridor> corridors;
	std::vector<Leader> leaders;

	float tension;
};

