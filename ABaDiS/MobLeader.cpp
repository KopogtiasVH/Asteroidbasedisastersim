#include "stdafx.h"
#include "MobLeader.h"

/*
	MobLeaders are the most important asset of the ANARC. Without them the raging mob has no coordination and is doomed to fail.
*/

MobLeader::MobLeader(Room startingLocation) : Being(startingLocation)
{
	// Get a Random class
	switch (rand() % 4) {
	case 0:
		lClass = MobLeader::crimeBoss;
		occupation = "Crime_Boss";
		break;
	case 1:
		lClass = MobLeader::campaigner;
		occupation = "Campaigner";
		break;
	case 2:
		lClass = MobLeader::leader;
		occupation = "Leader";
		break;
	case 3:
		lClass = MobLeader::exmilitary;
		occupation = "Veteran";
	default:
		break;
	}

	// MobLeaders are always stronger than Goons, duh
	maxHealth += 10;
	healthPoints = maxHealth;
	maxMorale += 10;
	morale = maxMorale;

	armor = 2;

	// MobLeaders always carry a ranged weapon.
	weapon = Weapon(Weapon::ranged);

	// Stronger willpower controls greater mobs.
	maxMobSize = maxMorale - 5;

	// Crime Bosses have a bigger squad
	if (lClass == MobLeader::crimeBoss)
		maxMobSize += 5;

	// Initialize the following mob and generate it a name
	mob = std::vector<MobGoon>();
	mobName = NameGenerator::militiaName(surname);
}

// Generate a new Goon and add it to the mob
bool MobLeader::recruit() {
	if (mob.size() < maxMobSize) {
		MobGoon newGoon = MobGoon(currentLocation);
		mob.push_back(newGoon);
		return true;
	}
	else {
		return false;
	}
}

// print the mob to the console
void MobLeader::printMob() {
	std::cout << mobName << ": (" << mob.size() << "/" << maxMobSize << ")" << std::endl;
	for (int i = 0; i < mob.size(); i++) {
		std::cout << " - " << mob[i].getName() << std::endl;
	}
	std::cout << std::endl;
}

// return the mob
std::vector<MobGoon> MobLeader::getMob() const {
	return mob;
}
