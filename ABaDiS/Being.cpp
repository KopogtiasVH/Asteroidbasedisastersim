#include "stdafx.h"
#include "Being.h"

#include <iostream>

Being::Being(Room startingLocation)
{
	isAlive = true;
	eager = true;
	currentLocation = startingLocation;

	willpower = (rand() % 5) + 1;
	maxMorale = 5 + willpower;
	morale = maxMorale;

	strength = (rand() % 5) + 1;
	maxHealth = 5 + strength;
	healthPoints = maxHealth;

	if (rand() % 2 >= 1)
		gender = "m";
	else
		gender = "f";

	name = NameGenerator::humanName(gender);
	occupation = "none";

	weapon = Weapon();
}

void Being::doDamage(int d)
{
	healthPoints -= d;
	if (healthPoints <= 0)
		isAlive = false;
}

void Being::changeMorale(int d) 
{
	morale -= d;

}

void Being::printBeing() 
{
	std::cout << "Being:" << std::endl
		<< "Name: " << name << std::endl
		<< "Gender: " << gender << std::endl
		<< "Current Location: " << currentLocation.getName() << std::endl
		<< "Health: " << healthPoints << "/" << maxHealth << std::endl
		<< "Morale: " << morale << "/" << maxMorale << std::endl
		<< "Strength: " << strength << std::endl
		<< "Willpower: " << willpower << std::endl
		<< "Weapon: " << weapon.getName() << std::endl
		<< "Occupation :" << occupation << std::endl << std::endl;
}
