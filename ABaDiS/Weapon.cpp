#include "stdafx.h"

/*
	A weapon used in battle. There are 4 general types of weapons.
*/

Weapon::Weapon() {
	name = "Bare_Fist";
	wt = Weapon::blunt;
	strengthMod = 0;
	range = 0;
	extraDamage = 0;
	noOfUses = INFINITY;
	riskOfUse = 0;
	accuracy = 90;
}

Weapon::Weapon(Weapon::weapontype t)
{
	name = NameGenerator::weaponName(t);
	wt = t;

	switch (t) {
	case Weapon::blunt:
		strengthMod = rand() % 3 + 1;
		range = 0;
		extraDamage = 0;
		noOfUses = INFINITY;
		riskOfUse = 0;
		accuracy = 90;
		break;
	case Weapon::pierce:
		strengthMod = rand() % 2;
		range = 0;
		extraDamage = rand() % 3 + 1;
		noOfUses = INFINITY;
		riskOfUse = 0;
		accuracy = 90;
		break;
	case Weapon::ranged:
		strengthMod = 0;
		range = 2;
		extraDamage = rand() % 5 + 1;
		noOfUses = rand() % 12 + 12;
		riskOfUse = 10;
		accuracy = 50;
		break;
	case Weapon::explosive:
		strengthMod = 0;
		range = 1;
		extraDamage = rand() % 10 + 5;
		noOfUses = rand() % 3 + 1;
		riskOfUse = extraDamage + (rand() % 10 + 1);
		accuracy = 50;
		break;
	default:
		break;
	}
}

Weapon::Weapon(std::string type) {
	if (type == "sec_cqc") {
		name = "Police_Baton";
		wt = Weapon::blunt;
		strengthMod = 2;
		range = 0;
		extraDamage = 0;
		noOfUses = INFINITY;
		riskOfUse = 0;
		accuracy = 90;
	}
	else if (type == "sec_ranged") {
		name = "Security_Revolver";
		wt = Weapon::ranged;
		strengthMod = 0;
		range = 2;
		extraDamage = 4;
		noOfUses = 18;
		riskOfUse = 5;
		accuracy = 60;
	}
	else if (type == "sec_riotSpecialist") {
		name = "Energy_Baton";
		wt = Weapon::blunt;
		strengthMod = 2;
		range = 0;
		extraDamage = 1;
		noOfUses = INFINITY;
		riskOfUse = 0;
		accuracy = 90;
	}
	else {
		std::cerr << "Wrong argument for specified weapontype" << std::endl;
	}
}

std::string Weapon::getName() const
{
	return name;
}
