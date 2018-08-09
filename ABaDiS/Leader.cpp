#include "stdafx.h"
#include "Being.h"

Leader::Leader(Room* currentLocation, Enumerators::Faction f) : Being(currentLocation)
{
	// Leaders have a Faction to determine their fighting behavior
	faction = f;

	// Leaders are always stronger than Troops, they earned this title
	maxHealth += 10;
	healthPoints = maxHealth;
	maxMorale += 10;
	currentMorale = maxMorale;

	// Leaders are always armored
	armor = 2;

	// Maximum Squad size is in comparison to the Officers Willpower
	maxSquadSize = maxMorale - 5;

	// All Leaders have a Squad
	squad = new Squad(maxSquadSize, f, surname);
	squadName = squad->getSquadName();

	// Leaders don't start in fights
	isFighting = false;
}

// return the squad.
Squad* Leader::getSquad() const{
	return squad;
}

// return squad's name
std::string Leader::getSquadName() const {
	return squadName;
}

// print the squad.
void Leader::printSquad() {
	squad->printSquad();
}

bool Leader::recruit(Being* toRecruit) {
	return squad->recruit(toRecruit);
}

bool Leader::recruit() {
	return false;
}

void Leader::getNewDesire() {

}

void Leader::enterRoom(Room* toEnter) {

}