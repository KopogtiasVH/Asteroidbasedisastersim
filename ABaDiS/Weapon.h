#pragma once
#include "stdafx.h"
#include "Enumerators.h"

class Weapon
{
public:
	
	

	Weapon();
	Weapon(Enumerators::Weapontype);
	Weapon(std::string);
	Weapon(Enumerators::OfficerClass);

	std::string getName() const;
	Enumerators::Weapontype getWeapontype() const;

private:
	std::string name;
	Enumerators::Weapontype wt;
	int strengthMod;
	int range;
	int extraDamage;
	int noOfUses;
	int riskOfUse;
	int accuracy;
};

