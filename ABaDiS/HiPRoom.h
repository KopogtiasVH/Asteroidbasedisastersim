#pragma once
#include "Room.h"
class HiPRoom :
	public Room
{
public:
	HiPRoom(int);

	// Other
	void setName();

	// Getters
	int getFood();
	int getScrap();
	int getWeapons();
	int getPopulation();

	bool takeFood(int);
	bool takeScrap(int);
	bool takeWeapon(int);
	bool takePopulation(int);


private:

	// Ressources
	int food;
	int scrap;
	int weapons;

	// Population
	int population;

	// Other
};

