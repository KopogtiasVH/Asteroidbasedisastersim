#pragma once
#include "stdafx.h"

class Enumerators
{
public:
	// The classes for SecOfficers
	enum class OfficerClass {
		riotSpecialist,
		detective,
		commander,
		officer
	};

	// The identifiers of Beings
	enum class KindOfBeing {
		none,
		sectroop,
		secofficer,
		mobgoon,
		mobleader
	};

	// Identifies Corridors from Living Quarters
	enum class KindOfRoom {
		generic,
		street,
		livingQuarter,
		docks,
		warehouse,
		security
	};

	// The Factions a Leader can belong to
	enum class Faction {
		ANARC,
		SEC,
		NONE
	};

	// Genders
	enum class Gender {
		male,
		female
	};

	// Weapontypes
	enum class Weapontype {
		blunt,
		pierce,
		ranged,
		explosive
	};

	// Health Status
	enum class BodyStatus {
		well,
		scared,
		fleeing,
		wounded,
		severlyWounded,
		dead
	};

	// Quest Types
	enum class TypeOfQuest {
		generic,
		gathering,
		secure,
		hold,
		recruit,
		special
	};

	// Stat Boosts for Questrewards
	enum class StatBoost {
		maxHealth,
		maxMorale,
		strength,
		willpower,
		charisma,
		random,
		none
	};

	// Types of Ressources
	enum class Ressource {
		food,
		scrap,
		meds,
		none
	};

	// Alignments
	enum class Alignment {
		neutral,
		lawful,
		chaotic
	};

	// Desires
	enum class Desire {
		idle,
		returnToClient,
		explore,
		traverse,
		recruit,
		scavenge,
		investigate
	};
};

