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
	int getStrengthMod() const;
	int getRange() const;
	int getExtraDamage() const;
	int getNoOfUses() const;
	int getRiskOfUse() const;
	int getAccuracy() const;

	void useWeapon();

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

