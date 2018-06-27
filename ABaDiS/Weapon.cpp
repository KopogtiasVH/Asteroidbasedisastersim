#include "stdafx.h"
#include "Weapon.h"

Weapon::Weapon() {
	name = "none";
	wt = Weapon::blunt;
	strengthMod = 0;
	range = 0;
	extraDamage = 0;
	noOfUses = INFINITY;
	riskOfUse = 0;
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
		break;
	case Weapon::pierce:
		strengthMod = rand() % 2;
		range = 0;
		extraDamage = rand() % 3 + 1;
		noOfUses = INFINITY;
		riskOfUse = 0;
		break;
	case Weapon::ranged:
		strengthMod = 0;
		range = 2;
		extraDamage = rand() % 5 + 1;
		noOfUses = rand() % 12 + 12;
		riskOfUse = 10;
		break;
	case Weapon::explosive:
		strengthMod = 0;
		range = 1;
		extraDamage = rand() % 10 + 5;
		noOfUses = rand() % 3 + 1;
		riskOfUse = extraDamage + (rand() % 10 + 1);
		break;
	default:
		break;
	}
}

Weapon::Weapon(std::string type) {
	if (type == "sec_cqc") {
		name = "Police Baton";
		wt = Weapon::blunt;
		strengthMod = 2;
		range = 0;
		extraDamage = 0;
		noOfUses = INFINITY;
		riskOfUse = 0;
	}
	else if (type == "sec_ranged") {
		name = "Security Revolver";
		wt = Weapon::ranged;
		strengthMod = 0;
		range = 2;
		extraDamage = 4;
		noOfUses = 18;
		riskOfUse = 5;
	}
	else {
		std::cerr << "Wrong argument for specified weapontype" << std::endl;
	}
}

std::string Weapon::getName() const
{
	return name;
}
