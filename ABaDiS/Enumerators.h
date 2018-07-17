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

};

