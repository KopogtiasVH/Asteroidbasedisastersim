#pragma once

#include "stdafx.h"

class Being
{
public:
	Being(Room*);
	void doDamage(int);
	void changeMorale(int);

	//Printers
	virtual void printBeingTable();
	virtual void printBeingFlavor();
	virtual void printWeapon();

	std::string getName() const;
	std::string getSurName() const;
	int getMaxMorale() const;
	int getCurrentMorale() const;

	Room* getCurrentLocation() const;

protected:
	bool isAlive;
	bool eager;

	Room* currentLocation;
	Weapon* weapon;
	Enumerators::KindOfBeing kob;

	int maxHealth;
	int healthPoints;
	int maxMorale;
	int currentMorale;

	int strength;
	int willpower;

	int armor;

	std::string fullName;
	std::string name;
	std::string surname;
	std::string occupation;

	Enumerators::Gender gender;
};

