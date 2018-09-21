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
	squad = new Squad(maxSquadSize, strength, f, surname);
	squadName = squad->getSquadName();

	// Leaders don't start in fights
	isFighting = false;

	// Leaders start without a quest
	currentQuest = nullptr;

	map = Map();

	enterRoom(currentLocation);

}

// return the squad.
Squad* Leader::getSquad() const{
	return squad;
}

// return squad's name
std::string Leader::getSquadName() const {
	return squadName;
}

Quest* Leader::getCurrentQuest() const {
	return currentQuest;
}

Map * Leader::getMap()
{
	return &map;
}

Enumerators::Faction Leader::getFaction() const {
	return faction;
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

void Leader::takeQuest(Client* c) {
	if (c->getAlignment() == Enumerators::Alignment::neutral || c->getAlignment() == alignment)
		currentQuest = c->assignQuest(this);
}

void Leader::explore(int toExplore) {
	if (toExplore > 0) {
		toExplore--;
		for (Room* r : currentLocation->getConnections()) {
			if (!knowsRoom(r)) {
				enterRoom(r);
				break;
			}
		}
		explore(toExplore);
	}
}

void Leader::recieveReward(Quest::questReward reward)
{
}

void Leader::toggleFighting(bool b)
{
	isFighting = b;
}

bool Leader::knowsRoom(Room* toCheck)
{
	return map.knows(toCheck);
}

void Leader::printBeingTable() {
	std::string genderString = "";
	switch (gender) {
	case (Enumerators::Gender::male):
		genderString = "m";
		break;
	case (Enumerators::Gender::female):
		genderString = "f";
		break;
	default:
		genderString = "ERROR";
		break;
	}

	std::string questName = "";
	if (currentQuest != nullptr)
		questName = currentQuest->getQuestName();
	else
		questName = "None";

	std::cout << "Being:" << std::endl
		<< "	Name:       " << fullName << std::endl
		<< "	Gender:     " << genderString << std::endl
		<< "	Location:   " << currentLocation->getName() << std::endl
		<< "	Health:     " << healthPoints << "/" << maxHealth << std::endl
		<< "	Morale:     " << currentMorale << "/" << maxMorale << std::endl
		<< "	Strength:   " << strength << std::endl
		<< "	Willpower:  " << willpower << std::endl
		<< "	Weapon:     " << weapon->getName() << std::endl
		<< "	Armor:      " << armor << std::endl
		<< "	Occupation: " << occupation << std::endl 
		<< "	Quest:      " << questName << std::endl << std::endl;
}