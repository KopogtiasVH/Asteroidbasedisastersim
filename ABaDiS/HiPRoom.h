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


private:

	// Ressources
	int food;
	int scrap;
	int weapons;

	// Population
	int population;

	// Other
};

