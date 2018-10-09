#include "stdafx.h"
#include "SecTroop.h"

/*
	SecTroop is a regular Security Enforcer. Usually he serves under a Security Officer but he can also recieve Orders from the Bases Security Network.
*/

SecTroop::SecTroop(Room* startingLocation) : Being(startingLocation)
{
	kob = Enumerators::KindOfBeing::sectroop;

	occupation = "Security Enforcer";

	// Security Troops start with standardized security weapons. Either a Security Revolver or a Police Baton.
	if ((rand() % 100 + 1) <= 20) 
		weapon = new Weapon("sec_ranged");
	else
		weapon = new Weapon("sec_cqc");

	// Add a random rank to the name.
	fullName = NameGenerator::randomRank(kob) + " " + fullName;

	// Security is always armored
	armor = 2;

	// No Current Leader
	currentLeader = nullptr;
}

SecTroop::SecTroop(Leader* startingLeader) : Being(currentLocation)
{
	kob = Enumerators::KindOfBeing::sectroop;

	occupation = "Security Enforcer";

	// Security Troops start with standardized security weapons. Either a Security Revolver or a Police Baton.
	if ((rand() % 100 + 1) <= 20)
		weapon = new Weapon("sec_ranged");
	else
		weapon = new Weapon("sec_cqc");

	// Add a random rank to the name.
	fullName = NameGenerator::randomRank(kob) + " " + fullName;

	// Security is always armored.
	armor = 2;

	// Leader and Location handling.
	currentLeader = startingLeader;
	currentLocation = currentLeader->getCurrentLocation();
}

void SecTroop::printBeingTable()
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
		<< "	Occupation: " << occupation << std::endl 
		<< "	Leader:     " << currentLeader->getName() << std::endl
		<< "	Squad:      " << currentLeader->getSquad()->getSquadName() << std::endl << std::endl;
}

// Print the being in a prosaic form
void SecTroop::printBeingFlavor()
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
		willpowerflav = "pretty brave. ";
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
	std::cout << "	" << pronoun << weaponflav << armorflav << std::endl;
	std::cout << "	" << pronoun << " is serving in " << currentLeader->getSquadName() << std::endl << std::endl;

}