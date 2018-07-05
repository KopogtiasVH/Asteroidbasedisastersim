#pragma once

#include "stdafx.h"

class Being
{
public:
	Being(Room startingLocation);
	void doDamage(int);
	void changeMorale(int);
	void printBeingTable();
	void printBeingFlavor();
	void printWeapon();

	std::string getName() const;

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

	std::string fullName;
	std::string name;
	std::string surname;
	std::string gender;
	std::string occupation;
};

