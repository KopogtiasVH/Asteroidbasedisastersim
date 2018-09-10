#include "stdafx.h"

/*
	Being is the general AI class. Every living thing on the Asteroid Base is a Being.
*/
#pragma region CONSTRUCTORS
Being::Being()
{

	// General Setup of a regular Human Being
	status = Enumerators::BodyStatus::well;
	eager = true;
	inSquad = false;
	currentLocation = nullptr;

	willpower = (rand() % 5) + 1;
	maxMorale = 5 + willpower;
	currentMorale = maxMorale;

	strength = (rand() % 5) + 1;
	maxHealth = 5 + strength;
	healthPoints = maxHealth;

	maxInventorySpace = strength + rand() % 5;
	currentInventorySpace = 0;
	carryingFood = 0;
	carryingScrap = 0;

	if (rand() % 2 >= 1)
		gender = Enumerators::Gender::male;
	else
		gender = Enumerators::Gender::female;

	switch (rand() % 3) {
	case 0:
		alignment = Enumerators::Alignment::neutral;
		break;
	case 1:
		alignment = Enumerators::Alignment::lawful;
		break;
	case 2:
		alignment = Enumerators::Alignment::chaotic;
	default:
		std::cerr << "No such alignment exists" << std::endl;
		break;
	}

	// TODO: Switch name into 3 distinct preNames
	name = NameGenerator::humanName(gender);
	surname = NameGenerator::humanSurname();
	fullName = name + " " + surname;

	occupation = "none";

	weapon = new Weapon();
	armor = 0;

	kob = Enumerators::KindOfBeing::none;
}

Being::Being(Room* startingLocation)
{

	// General Setup of a regular Human Being
	status = Enumerators::BodyStatus::well;
	eager = true;
	inSquad = false;
	currentLocation = startingLocation;

	willpower = (rand() % 5) + 1;
	maxMorale = 5 + willpower;
	currentMorale = maxMorale;

	strength = (rand() % 5) + 1;
	maxHealth = 5 + strength;
	healthPoints = maxHealth;

	maxInventorySpace = strength + rand() % 5;
	currentInventorySpace = 0;
	carryingFood = 0;
	carryingScrap = 0;

	if (rand() % 2 >= 1)
		gender = Enumerators::Gender::male;
	else
		gender = Enumerators::Gender::female;

	switch (rand() % 3) {
	case 0:
		alignment = Enumerators::Alignment::neutral;
		break;
	case 1:
		alignment = Enumerators::Alignment::lawful;
		break;
	case 2:
		alignment = Enumerators::Alignment::chaotic;
		break;
	default:
		std::cerr << "No such alignment exists" << std::endl;
		break;
	}

	// TODO: Switch name into 3 distinct preNames
	name = NameGenerator::humanName(gender);
	surname = NameGenerator::humanSurname();
	fullName = name + " " + surname;

	occupation = "none";

	weapon = new Weapon();
	armor = 0;

	kob = Enumerators::KindOfBeing::none;
}
#pragma endregion

#pragma region MAIN
// The Main function of all Beings is called every frame to calculate behavior
void Being::step()
{
}
#pragma endregion

#pragma region HELPERS
void Being::setSquadAffiliation(bool s) {
	inSquad = s;
}

void Being::scavenge(Room* r, Enumerators::Ressource toScavenge)
{
	if (dynamic_cast<HiPRoom*>(r)) {
		HiPRoom* hr = dynamic_cast<HiPRoom*>(r);
		switch (toScavenge) {
		case (Enumerators::Ressource::food):
			if (hr->takeFood(1) && currentInventorySpace < maxInventorySpace) {
				carryingFood++;
				currentInventorySpace++;
			}
			break;
		case (Enumerators::Ressource::scrap):
			if (hr->takeScrap(1) && currentInventorySpace < maxInventorySpace) {
				carryingScrap++;
				currentInventorySpace++;
			}
			break;
		default:
			std::cerr << "Can't scavenge this ressource" << std::endl;
		}
	}
}

// Calculate the Damage this Being will do
int Being::attack() {
	if (rand() % 100 + 1 <= weapon->getAccuracy() && weapon->getNoOfUses() > 0) {
		weapon->useWeapon();
		float damage = 0;
		// Blunt and Pierce Weapons
		if (weapon->getWeapontype() == Enumerators::Weapontype::blunt ||
			weapon->getWeapontype() == Enumerators::Weapontype::pierce) {
			damage += (strength + weapon->getStrengthMod()) / 2;
		}
		damage += weapon->getExtraDamage();

		if (rand() % 100 + 1 <= weapon->getRiskOfUse()) {
			doDamage(damage / 2);
			return 0;
		}
		else {
			return damage;
		}
	}
	return 0;
}

// Deal Damage to the being, check for status
void Being::doDamage(int d)
{
	d -= armor;
	if (d < 0)
		d = 0;
	healthPoints -= d;
	if (healthPoints <= 0)
		status = Enumerators::BodyStatus::dead;
	else if (healthPoints <= maxHealth * 0.2)
		status = Enumerators::BodyStatus::severlyWounded;
	else if (healthPoints <= maxHealth * 0.6)
		status = Enumerators::BodyStatus::wounded;
}

// Deal Morale Damage, check for status
// TODO: implement status check
void Being::changeMorale(int d)
{
	currentMorale -= d;
}
#pragma endregion

#pragma region PRINTERS
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
	std::cout << "	" << pronoun << weaponflav << armorflav << std::endl << std::endl;

}

// Print the weapon of the Being in a prosaic form
void Being::printWeapon()
{
	std::cout << fullName << " is holding a " << weapon->getName() << std::endl;
}

#pragma endregion

#pragma region GETTERS
// Return the name of the being (duh)
std::string Being::getName() const {
	return fullName;
}

// Return only the Surname
std::string Being::getSurName() const {
	return surname;
}

int Being::getMaxMorale() const {
	return maxMorale;
}

int Being::getCurrentMorale() const {
	return currentMorale;
}

int Being::getMaxHealth() const {
	return maxHealth;
}

int Being::getCurrentHealth() const {
	return healthPoints;
}

int Being::getCurrentInventorySpace() const
{
	return currentInventorySpace;
}

int Being::getMaxInventorySpace() const
{
	return maxInventorySpace;
}

int Being::getCarryingFood() const
{
	return carryingFood;
}

int Being::getCarryingScrap() const
{
	return carryingScrap;
}

Enumerators::BodyStatus Being::getStatus() const {
	return status;
}

Room* Being::getCurrentLocation() const {
	return currentLocation;
}

Weapon* Being::getWeapon() const {
	return weapon;
}

bool Being::isInSquad() const {
	return inSquad;
}
Enumerators::Alignment Being::getAlignment() const
{
	return alignment;
}
#pragma endregion
