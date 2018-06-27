#include "stdafx.h"
#include "SecTroop.h"

SecTroop::SecTroop(Room startingLocation) : Being(startingLocation)
{
	occupation = "Security Enforcer";

	// Security Troops start with standardized security weapons.
	if ((rand() % 100 + 1) <= 20) 
		weapon = Weapon("sec_ranged");
	else
		weapon = Weapon("sec_cqc");
}

