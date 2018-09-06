#pragma once

#include "stdafx.h"

class Being
{
public:
	Being();
	Being(Room*);

	virtual void step();

	// Helpers
	void setSquadAffiliation(bool);
	void scavenge(Room*, Enumerators::Ressource);
	int attack();
	void doDamage(int);
	void changeMorale(int);

	//Printers
	virtual void printBeingTable();
	virtual void printBeingFlavor();
	virtual void printWeapon();

	// Getters
	std::string getName() const;
	std::string getSurName() const;
	int getMaxMorale() const;
	int getCurrentMorale() const;
	int getMaxHealth() const;
	int getCurrentHealth() const;
	int getCurrentInventorySpace() const;
	int getMaxInventorySpace() const;
	int getCarryingFood() const;
	int getCarryingScrap() const;
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
	int currentInventorySpace;
	int maxInventorySpace;

	int carryingFood;
	int carryingScrap;

	Enumerators::BodyStatus status;

	int strength;
	int willpower;

	int armor;

	std::string fullName;
	std::string name;
	std::string surname;
	std::string occupation;

	Enumerators::Gender gender;
	Enumerators::Alignment alignment;
};

