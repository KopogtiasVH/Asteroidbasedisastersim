#pragma once

#include "Room.h"
#include "NameGenerator.h"
#include "Weapon.h"

class Being
{
public:
	Being(Room startingLocation);
	void doDamage(int);
	void changeMorale(int);
	void printBeing();

protected:
	bool isAlive;
	bool eager;

	Room currentLocation;
	Weapon weapon;

	int maxHealth;
	int healthPoints;
	int maxMorale;
	int morale;

	int strength;
	int willpower;

	int armor;

	std::string name;
	std::string gender;
	std::string occupation;
};

