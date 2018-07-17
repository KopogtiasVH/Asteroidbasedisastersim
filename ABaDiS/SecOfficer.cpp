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
		oClass = OfficerClass::riotSpecialist;
		occupation = "Riot_Specialist";
		break;
	case 1:
		oClass = OfficerClass::detective;
		occupation = "Detective";
		break;
	case 2:
		oClass = OfficerClass::commander;
		occupation = "Security_Commander";
		break;
	case 3:
		oClass = OfficerClass::officer;
		occupation = "Security_Officer";
		break;
	default:
		break;
	}

	// Regular Officers always carry a Revolver
	weapon = Weapon("sec_ranged");

	// Riot Specialists have more armor and always carry an Energy Baton
	if (oClass == OfficerClass::riotSpecialist) {
		armor++;
		weapon = Weapon("sec_riotSpecialist");
	}

	// Commanders can command a bigger squad
	if (oClass == OfficerClass::commander)
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
