#include "stdafx.h"

/*
Nothing more but a hired muscle.
*/

MobGoon::MobGoon(Room startingLocation) : Being(startingLocation)
{
	occupation = "Rioteer";

	// choosing a starting weapon
	int weaponGen = rand() % 100 + 1;
	if (weaponGen < 25)
		weapon = Weapon();
	else if (weaponGen < 50)
		weapon = Weapon(Weapon::blunt);
	else if (weaponGen < 75)
		weapon = Weapon(Weapon::pierce);
	else if (weaponGen < 95)
		weapon = Weapon(Weapon::ranged);
	else
		weapon = Weapon(Weapon::explosive);

	armor = rand() % 2;
}
