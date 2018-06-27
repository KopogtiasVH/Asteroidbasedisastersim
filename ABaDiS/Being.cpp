#include "stdafx.h"

/*
	Being is the general AI class. Every living thing on the Asteroid Base is a Being.
*/

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
	armor = 0;
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

std::string Being::getName() const {
	return name;
}


// Functions for printing stuff to the console

void Being::printBeing() 
{
	std::cout << "Being:" << std::endl
		<< "	Name:       " << name << std::endl
		<< "	Gender:     " << gender << std::endl
		<< "	Location:   " << currentLocation.getName() << std::endl
		<< "	Health:     " << healthPoints << "/" << maxHealth << std::endl
		<< "	Morale:     " << morale << "/" << maxMorale << std::endl
		<< "	Strength:   " << strength << std::endl
		<< "	Willpower:  " << willpower << std::endl
		<< "	Weapon:     " << weapon.getName() << std::endl
		<< "	Armor:      " << armor << std::endl
		<< "	Occupation: " << occupation << std::endl << std::endl;
}

void Being::printBeingFlavor()
{
	std::string genderflav, occupationflav, locflav, strengthflav, willpowerflav, weaponflav, armorflav, pronoun, strbrvratio;
	
	if (gender == "m") {
		genderflav = " is a male ";
		pronoun = "He ";
	}
	else {
		genderflav = " is a female ";
		pronoun = "She ";
	}

	if (occupation == "none")
		occupationflav = "jobless person, ";
	else
		occupationflav = occupation + ", ";

	locflav = "who is currently at " + currentLocation.getName() + ".";

	switch (strength) {
	case 1:
		strengthflav = "is very weak";
		break;
	case 2:
		strengthflav = "is weak";
		break;
	case 3:
		strengthflav = "has average strength";
		break;
	case 4:
		strengthflav = "is pretty strong";
		break;
	case 5:
		strengthflav = "is very strong";
		break;
	default:
		break;
	}

	switch (willpower) {
	case 1:
	case 2:
		willpowerflav = "a coward. ";
		break;
	case 3:
		willpowerflav = "a little brave. ";
		break;
	case 4:
		willpowerflav = "pretty brave. " ;
		break;
	case 5:
		willpowerflav = "very brave. ";
		break;
	default:
		break;
	}
	
	if ((strength >= 4 && willpower <= 2) || (strength <= 2 && willpower >= 4))
		strbrvratio = " but ";
	else 
		strbrvratio = " and ";

	if (weapon.getName() == "Bare_Fist")
		weaponflav = "is holding no weapon.";
	else
		weaponflav = "is holding a " + weapon.getName();

	switch (armor) {
	case 0:
		armorflav = " and is wearing no armor.";
		break;
	case 1:
		armorflav = " and is wearing light armor.";
		break;
	case 2:
		armorflav = " and is wearing heavy armor.";
		break;
	case 3:
		armorflav = " and is exceptionally well armored.";
		break;
	default:
		break;
	}


	std::cout << name << ": " << std::endl;
	std::cout << name << genderflav << occupationflav << locflav << std::endl;
	std::cout << pronoun << strengthflav << strbrvratio << willpowerflav << std::endl;
	std::cout << pronoun << weaponflav << armorflav << std::endl << std::endl;

}

void Being::printWeapon()
{
	std::cout << name << " is holding a " << weapon.getName() << std::endl;
}
