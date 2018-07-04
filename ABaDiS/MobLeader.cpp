#include "stdafx.h"
#include "MobLeader.h"


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

	weapon = Weapon(Weapon::ranged);

	maxMobSize = maxMorale - 5;

	// Crime Bosses have a bigger squad
	if (lClass == MobLeader::crimeBoss)
		maxMobSize += 5;

	mob = std::vector<MobGoon>();
	mobName = NameGenerator::militiaName(surname);
}

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

void MobLeader::printMob() {
	std::cout << mobName << ": (" << mob.size() << "/" << maxMobSize << ")" << std::endl;
	for (int i = 0; i < mob.size(); i++) {
		std::cout << " - " << mob[i].getName() << std::endl;
	}
	std::cout << std::endl;
}

std::vector<MobGoon> MobLeader::getMob() const {
	return mob;
}
