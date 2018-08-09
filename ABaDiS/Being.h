#pragma once

#include "stdafx.h"

class Being
{
public:
	Being(Room*);
	void doDamage(int);
	void changeMorale(int);

	// Helpers
	void setSquadAffiliation(bool);

	//Printers
	virtual void printBeingTable();
	virtual void printBeingFlavor();
	virtual void printWeapon();

	int attack();

	// Getters
	std::string getName() const;
	std::string getSurName() const;
	int getMaxMorale() const;
	int getCurrentMorale() const;
	int getMaxHealth() const;
	int getCurrentHealth() const;
	Enumerators::BodyStatus getStatus() const;
	Room* getCurrentLocation() const;
	Weapon* getWeapon() const;
	bool isInSquad() const;

protected:
	bool eager;
	bool inSquad;

	Room* currentLocation;
	Weapon* weapon;
	Enumerators::KindOfBeing kob;

	int maxHealth;
	int healthPoints;
	int maxMorale;
	int currentMorale;

	Enumerators::BodyStatus status;

	int strength;
	int willpower;

	int armor;

	std::string fullName;
	std::string name;
	std::string surname;
	std::string occupation;

	Enumerators::Gender gender;
};

