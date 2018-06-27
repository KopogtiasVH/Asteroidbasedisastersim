#include "stdafx.h"
#include "SecOfficer.h"


SecOfficer::SecOfficer(Room startingLocation) : Being(startingLocation)
{
	occupation = "Security Officer";

	// Security Troops start with standardized security weapons.
	if ((rand() % 100 + 1) <= 20)
		weapon = Weapon("sec_ranged");
	else
		weapon = Weapon("sec_cqc");

	// Add a random rank to the name.
	name = NameGenerator::randomRank("secofficer") + " " + name;

	armor = 3;

	subordinates = std::vector<SecTroop>();
}

void SecOfficer::recruit() {
	SecTroop newRecruit = SecTroop(currentLocation);
	subordinates.push_back(newRecruit);
}

void SecOfficer::printSubordinates() {
	std::cout << name << "'s subordinates:" << std::endl;
	for (int i = 0; i < subordinates.size(); i++) {
		std::cout << " - " << subordinates[i].getName() << std::endl;
	}
	std::cout << std::endl;
}
