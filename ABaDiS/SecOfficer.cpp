#include "stdafx.h"
#include "SecOfficer.h"

/*
	Security Officers are better versions of SecTroops. They are stronger, braver and can lead squads.
	TODO: They can get orders from an allknowing security system which monitors the whole base.
*/

SecOfficer::SecOfficer(Room startingLocation) : Being(startingLocation)
{

	// Regular Officers always carry a Revolver
	weapon = Weapon("sec_ranged");

	// Add a random rank to the name.
	fullName = NameGenerator::randomRank("secofficer") + " " + fullName;

	// Get a Random class
	switch (rand() % 4) {
	case 0:
		oClass = SecOfficer::riotSpecialist;
		occupation = "Riot_Specialist";
		break;
	case 1:
		oClass = SecOfficer::detective;
		occupation = "Detective";
		break;
	case 2:
		oClass = SecOfficer::commander;
		occupation = "Security_Commander";
		break;
	case 3:
		oClass = SecOfficer::officer;
		occupation = "Security_Officer";
		break;
	default:
		break;
	}

	// SecOfficers are always stronger than Troops, they earned this title
	maxHealth += 10;
	healthPoints = maxHealth;
	maxMorale += 10;
	morale = maxMorale;

	// Officers are always armored
	armor = 2;

	// Riot Specialists have more armor and always carry an Energy Baton
	if (oClass == SecOfficer::riotSpecialist) {
		armor++;
		weapon = Weapon("sec_riotSpecialist");
	}

	// Maximum Squad size is in comparison to the Officers Willpower
	maxSquadSize = maxMorale - 5;

	// Commanders can command a bigger squad
	if (oClass == SecOfficer::commander)
		maxSquadSize += 5;

	// Initialize the squad vector
	squad = std::vector<SecTroop>();
}


// Generate a new SecTroop and add it to the squad
bool SecOfficer::recruit() {
	if (squad.size() < maxSquadSize) {
		SecTroop newRecruit = SecTroop(currentLocation);
		squad.push_back(newRecruit);
		return true;
	}
	else {
		return false;
	}
}

 // Add an existing SecTroop to the squad
bool SecOfficer::recruit(SecTroop newRecruit) {
	if (squad.size() < maxSquadSize) {
		squad.push_back(newRecruit);
		return true;
	}
	else {
		return false;
	}
}

 // Print the Squad to the console
void SecOfficer::printSquad() {
	std::cout << fullName << "'s Squad: (" << squad.size() << "/" << maxSquadSize << ")" << std::endl;
	for (int i = 0; i < squad.size(); i++) {
		std::cout << " - " << squad[i].getName() << std::endl;
	}
	std::cout << std::endl;
}

// Return the squad
std::vector<SecTroop> SecOfficer::getSquad() const {
	return squad;
}
