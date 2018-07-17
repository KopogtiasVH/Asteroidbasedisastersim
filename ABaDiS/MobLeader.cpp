#include "stdafx.h"
#include "MobLeader.h"

/*
	MobLeaders are the most important asset of the ANARC. Without them the raging mob has no coordination and is doomed to fail.
*/

MobLeader::MobLeader(Room startingLocation) : Leader(startingLocation, Faction::ANARC)
{

	kob = Enumerators::KindOfBeing::mobleader;

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

	// MobLeaders always carry a ranged weapon.
	weapon = Weapon(Weapon::ranged);


	// Crime Bosses have a bigger squad
	if (lClass == MobLeader::crimeBoss) {
		maxSquadSize += 5;
		squad.setMaxSize(maxSquadSize);
	}

}

// Generate a new Goon and add it to the mob
bool MobLeader::recruit() {
	MobGoon newGoon = MobGoon(currentLocation);
	return squad.recruit(newGoon);
}

// return the mob
Squad MobLeader::getSquad() const {
	return squad;
}
