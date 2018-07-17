#include "stdafx.h"

/*
	SecTroop is a regular Security Enforcer. Usually he serves under a Security Officer but he can also recieve Orders from the Bases Security Network.
*/

SecTroop::SecTroop(Room startingLocation) : Being(startingLocation)
{
	kob = Enumerators::KindOfBeing::sectroop;

	occupation = "Security Enforcer";

	// Security Troops start with standardized security weapons. Either a Security Revolver or a Police Baton.
	if ((rand() % 100 + 1) <= 20) 
		weapon = Weapon("sec_ranged");
	else
		weapon = Weapon("sec_cqc");

	// Add a random rank to the name.
	fullName = NameGenerator::randomRank(kob) + " " + fullName;

	// Security is always armored
	armor = 2;
}

