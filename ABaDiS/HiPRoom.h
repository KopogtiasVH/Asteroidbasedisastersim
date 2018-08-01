#pragma once
#include "Room.h"
class HiPRoom :
	public Room
{
public:
	HiPRoom(int);

	// Getters
	int getFood();
	int getScrap();
	int getWeapons();
	
	int getPopulation();
	Enumerators::KindOfRoom getKor();

private:

	// Ressources
	int food;
	int scrap;
	int weapons;

	// Population
	int population;

	// Other
	Enumerators::KindOfRoom kor;
};

