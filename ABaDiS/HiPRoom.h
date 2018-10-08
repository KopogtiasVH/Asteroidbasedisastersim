#pragma once
#include "Room.h"
class HiPRoom :
	public Room
{
public:
	HiPRoom(int);

	// Other
	void setName();
	void printRoom();

	// Getters
	int getFood();
	int getScrap();
	int getWeapons();
	int getPopulation();
	int getMeds();

	bool hasRessource(Enumerators::Ressource);

	bool takeFood(int);
	bool takeScrap(int);
	bool takeWeapon(int);
	bool takePopulation(int);
	bool takeMeds(int);


private:

	// Ressources
	int food;
	int scrap;
	int weapons;
	int meds;

	// Population
	int population;

	// Other
};

