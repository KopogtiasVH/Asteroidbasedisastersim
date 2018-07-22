#include "stdafx.h"

/*
	Being is the general AI class. Every living thing on the Asteroid Base is a Being.
*/

Being::Being(Room* startingLocation)
{

	// General Setup of a regular Human Being
	isAlive = true;
	eager = true;
	currentLocation = startingLocation;

	willpower = (rand() % 5) + 1;
	maxMorale = 5 + willpower;
	currentMorale = maxMorale;

	strength = (rand() % 5) + 1;
	maxHealth = 5 + strength;
	healthPoints = maxHealth;

	// TODO: Might switch gender from string to enum
	if (rand() % 2 >= 1)
		gender = Enumerators::Gender::male;
	else
		gender = Enumerators::Gender::female;

	// TODO: Switch name into 3 distinct preNames
	name = NameGenerator::humanName(gender);
	surname = NameGenerator::humanSurname();
	fullName = name + " " + surname;

	occupation = "none";

	weapon = new Weapon();
	armor = 0;

	kob = Enumerators::KindOfBeing::none;
}

int Being::getMaxMorale() const {
	return maxMorale;
}

int Being::getCurrentMorale() const {
	return currentMorale;
}

Room* Being::getCurrentLocation() const {
	return currentLocation;
}

Weapon* Being::getWeapon() const {
	return weapon;
}

// Deal Damage to the being, check for status
// TODO: implement status check
void Being::doDamage(int d)
{
	healthPoints -= d;
	if (healthPoints <= 0)
		isAlive = false;
}

// Deal Morale Damage, check for status
// TODO: implement status check
void Being::changeMorale(int d) 
{
	currentMorale -= d;
}

// Return the name of the being (duh)
std::string Being::getName() const {
	return fullName;
}

// Return only the Surname
std::string Being::getSurName() const {
	return surname;
}

// Functions for printing stuff to the console

// Print the being as a table
void Being::printBeingTable() 
{
	std::string genderString = "";
	switch (gender) {
	case (Enumerators::Gender::male):
		genderString = "m";
		break;
	case (Enumerators::Gender::female):
		genderString = "f";
		break;
	default:
		genderString = "ERROR";
		break;
	}

	std::cout << "Being:" << std::endl
		<< "	Name:       " << fullName << std::endl
		<< "	Gender:     " << genderString << std::endl
		<< "	Location:   " << currentLocation->getName() << std::endl
		<< "	Health:     " << healthPoints << "/" << maxHealth << std::endl
		<< "	Morale:     " << currentMorale << "/" << maxMorale << std::endl
		<< "	Strength:   " << strength << std::endl
		<< "	Willpower:  " << willpower << std::endl
		<< "	Weapon:     " << weapon->getName() << std::endl
		<< "	Armor:      " << armor << std::endl
		<< "	Occupation: " << occupation << std::endl << std::endl;
}

// Print the being in a prosaic form
void Being::printBeingFlavor()
{
	std::string genderflav, occupationflav, locflav, strengthflav, willpowerflav, weaponflav, armorflav, pronoun, strbrvratio;
	
	switch (gender) {
	case (Enumerators::Gender::male):
		genderflav = " is a male ";
		pronoun = "He ";
		break;
	case (Enumerators::Gender::female):
		genderflav = " is a female ";
		pronoun = "She ";
		break;
	default:
		break;
	}

	if (occupation == "none")
		occupationflav = "unemployed person, ";
	else
		occupationflav = occupation + ", ";

	locflav = "who is currently at " + currentLocation->getName() + ".";

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
	else if (strength == 3)
		strbrvratio = " and is ";
	else 
		strbrvratio = " and ";

	if (weapon->getName() == "Bare_Fist")
		weaponflav = "is holding no weapon";
	else
		weaponflav = "is holding a " + weapon->getName();

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


	std::cout << fullName << ": " << std::endl;
	std::cout << "	" << name[0] << ". " << surname << genderflav << occupationflav << locflav << std::endl;
	std::cout << "	" << pronoun << strengthflav << strbrvratio << willpowerflav << std::endl;
	std::cout << "	" << pronoun << weaponflav << armorflav << std::endl << std::endl;

}

// Print the weapon of the Being in a prosaic form
void Being::printWeapon()
{
	std::cout << fullName << " is holding a " << weapon->getName() << std::endl;
}
