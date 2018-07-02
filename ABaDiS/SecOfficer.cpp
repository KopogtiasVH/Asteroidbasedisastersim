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

	maxSubordinates = maxMorale - 5;

	if (oClass == SecOfficer::commander)
		maxSubordinates += 5;

	subordinates = std::vector<SecTroop>();
}

bool SecOfficer::recruit() {
	if (subordinates.size() < maxSubordinates) {
		SecTroop newRecruit = SecTroop(currentLocation);
		subordinates.push_back(newRecruit);
		return true;
	}
	else {
		return false;
	}
}

void SecOfficer::printSubordinates() {
	std::cout << name << "'s subordinates: (" << subordinates.size() << "/" << maxSubordinates << ")" << std::endl;
	for (int i = 0; i < subordinates.size(); i++) {
		std::cout << " - " << subordinates[i].getName() << std::endl;
	}
	std::cout << std::endl;
}
