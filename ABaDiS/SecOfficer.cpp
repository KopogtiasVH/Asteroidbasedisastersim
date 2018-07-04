#include "stdafx.h"
#include "SecOfficer.h"


SecOfficer::SecOfficer(Room startingLocation) : Being(startingLocation)
{

	// Regular Officers always carry a Revolver
	weapon = Weapon("sec_ranged");

	// Add a random rank to the name.
	name = NameGenerator::randomRank("secofficer") + " " + name;

	// Get a Random class
	switch (rand() % 4) {
	case 0:
		oClass = SecOfficer::riotSpecialist;
		occupation = "Riot Specialist";
		break;
	case 1:
		oClass = SecOfficer::detective;
		occupation = "Detective";
		break;
	case 2:
		oClass = SecOfficer::commander;
		occupation = "Security Commander";
		break;
	case 3:
		oClass = SecOfficer::officer;
		occupation = "Security Officer";
		break;
	default:
		break;
	}

	armor = 2;

	if (oClass == SecOfficer::riotSpecialist)
		armor++;

	maxHealth += 10;
	healthPoints = maxHealth;
	maxMorale += 10;
	morale = maxMorale;

	maxSquadSize = maxMorale - 5;

	if (oClass == SecOfficer::commander)
		maxSquadSize += 5;

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

bool SecOfficer::recruit(SecTroop newRecruit) {
	if (squad.size() < maxSquadSize) {
		squad.push_back(newRecruit);
		return true;
	}
	else {
		return false;
	}
}

void SecOfficer::printSubordinates() {
	std::cout << name << "'s Squad: (" << squad.size() << "/" << maxSquadSize << ")" << std::endl;
	for (int i = 0; i < squad.size(); i++) {
		std::cout << " - " << squad[i].getName() << std::endl;
	}
	std::cout << std::endl;
}
