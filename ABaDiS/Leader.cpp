#include "stdafx.h"
#include "Being.h"

Leader::Leader(Room currentLocation, Faction f) : Being(currentLocation)
{
	// Leaders have a Faction to determine their fighting behavior
	faction = f;

	// Leaders are always stronger than Troops, they earned this title
	maxHealth += 10;
	healthPoints = maxHealth;
	maxMorale += 10;
	morale = maxMorale;

	// Leaders are always armored
	armor = 2;

	// Maximum Squad size is in comparison to the Officers Willpower
	maxSquadSize = maxMorale - 5;

	// All Leaders have a Squad
	switch (faction) {
	case ANARC:
		squad = Squad(maxSquadSize, "ANARC", surname);
		break;
	case SEC:
		squad = Squad(maxSquadSize, "SEC", surname);
		break;
	default:
		break;
	}
}

// return the squad.
Squad Leader::getSquad() const{
	return squad;
}

// print the squad.
void Leader::printSquad() {
	squad.printSquad();
}

bool Leader::recruit(Being toRecruit) {
	return squad.recruit(toRecruit);
}

bool Leader::recruit() {
	return false;
}