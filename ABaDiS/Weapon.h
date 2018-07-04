#pragma once
class Weapon
{
public:
	
	enum weapontype {
		blunt,
		pierce,
		ranged,
		explosive
	};

	Weapon();
	Weapon(weapontype);
	Weapon(std::string);

	std::string getName() const;

private:
	std::string name;
	weapontype wt;
	int strengthMod;
	int range;
	int extraDamage;
	int noOfUses;
	int riskOfUse;
	int accuracy;
};

