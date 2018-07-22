#include "stdafx.h"

/*
	Nothing more but a hired muscle.
*/

MobGoon::MobGoon(Room* startingLocation) : Being(startingLocation)
{
	kob = Enumerators::KindOfBeing::mobgoon;

	occupation = NameGenerator::randomJob();

	// choosing a starting weapon
	int weaponGen = rand() % 100 + 1;
	if (weaponGen < 25)
		weapon = new Weapon();
	else if (weaponGen < 50)
		weapon = new Weapon(Weapon::blunt);
	else if (weaponGen < 75)
		weapon = new Weapon(Weapon::pierce);
	else if (weaponGen < 95)
		weapon = new Weapon(Weapon::ranged);
	else
		weapon = new Weapon(Weapon::explosive);

	// Goons have either no ore light armor.
	armor = rand() % 2;
}
