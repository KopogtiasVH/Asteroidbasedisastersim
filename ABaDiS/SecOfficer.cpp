#include "stdafx.h"
#include "SecOfficer.h"

/*
	Security Officers are better versions of SecTroops. They are stronger, braver and can lead squads.
	TODO: They can get orders from an allknowing security system which monitors the whole base.
*/

SecOfficer::SecOfficer(Room startingLocation) : Leader(startingLocation, Faction::SEC)
{
	// Add a random rank to the name.
	fullName = NameGenerator::randomRank("secofficer") + " " + fullName;

	// Get a Random class
	switch (rand() % 4) {
	case 0:
		oClass = Enumerators::OfficerClass::riotSpecialist;
		occupation = "Riot_Specialist";
		break;
	case 1:
		oClass = Enumerators::OfficerClass::detective;
		occupation = "Detective";
		break;
	case 2:
		oClass = Enumerators::OfficerClass::commander;
		occupation = "Security_Commander";
		break;
	case 3:
		oClass = Enumerators::OfficerClass::officer;
		occupation = "Security_Officer";
		break;
	default:
		break;
	}

	// SecOfficers recieve their weapon based on their class
	weapon = Weapon(oClass);

	// Riot Specialists have more armor and always carry an Energy Baton
	if (oClass == Enumerators::OfficerClass::riotSpecialist) {
		armor++;
	}

	// Commanders can command a bigger squad
	if (oClass == Enumerators::OfficerClass::commander)
		maxSquadSize += 5;
}

// Generate a new SecTroop and add it to the squad
bool SecOfficer::recruit() {
	SecTroop newRecruit = SecTroop(currentLocation);
	return squad.recruit(newRecruit);
}

 // Add an existing SecTroop to the squad
bool SecOfficer::recruit(SecTroop newRecruit) {
	return squad.recruit(newRecruit);
}
