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
		SEC
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
};

