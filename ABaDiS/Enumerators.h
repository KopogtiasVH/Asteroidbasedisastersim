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
		street,
		livingQuarter
	};

	enum class Faction {
		ANARC,
		SEC
	};
};

