#include "stdafx.h"
#include "Being.h"

#pragma region CONSTRUCTORS

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
	currentDesire = Enumerators::Desire::idle;

	explored = false;
	recruited = false;
	finishedQuests = 0;

	map = Map();

	enterRoom(currentLocation);

}

#pragma endregion

#pragma region VIRTUALS

bool Leader::recruit() {
	return false;
}

bool Leader::recruit(Being* toRecruit) {
	return squad->recruit(toRecruit);
}

Enumerators::Desire Leader::getNewDesire() {
	if (currentQuest == nullptr)
		return Enumerators::Desire::getNewQuest;
	else {
		return currentQuest->getDesire();
	}
}

void Leader::enterRoom(Room* toEnter) {

}

bool Leader::takeQuest(Client* c) {
	if (c->getAlignment() == Enumerators::Alignment::neutral || c->getAlignment() == alignment) {
		currentQuest = c->assignQuest(this);
		return true;
	}
	else
		return false;
}

void Leader::explore() {
	for (Room* r : currentLocation->getConnections()) {
		if (!knowsRoom(r)) {
			enterRoom(r);
			return;
		}
	}
	enterRoom(currentLocation->getConnections()[rand() % currentLocation->getConnections().size()]);
}

void Leader::recieveReward(Quest::questReward reward)
{
}

void Leader::interpretDesire(Enumerators::Desire desire) {
	if (desire == Enumerators::Desire::empty)
		currentDesire = getNewDesire();
	else 
		currentDesire = desire;
	switch (currentDesire) {
	case Enumerators::Desire::deliver:
		if (dynamic_cast<GatheringQuest*>(currentQuest)) {
			GatheringQuest* q = dynamic_cast<GatheringQuest*>(currentQuest);
			if (currentLocation == q->getClient()->getCurrentLocation()) {
				q->deliver();
			}
			else if (!knowsRoom(q->getClient()->getCurrentLocation())){
				explore();
			}
			else if (knowsRoom(q->getClient()->getCurrentLocation())) {
				map.findShortestRoute(currentLocation, q->getClient()->getCurrentLocation());
				enterRoom(map.getRoute()[1]);
			}
		}
		else {
			std::cerr << "Wrong Quest Type for this desire" << std::endl;
		}
		break;
	case Enumerators::Desire::explore:
		explore();
		break;
	case Enumerators::Desire::idle:
		break;
	case Enumerators::Desire::recruit:
		if (!recruit()) {
			switch (faction) {
			case Enumerators::Faction::ANARC:
				if (map.knowsOther(Enumerators::KindOfRoom::livingQuarter, currentLocation)) {
					map.findSpecificRoom(Enumerators::KindOfRoom::livingQuarter, currentLocation);
					enterRoom(map.getRoute()[1]);
				}
				else {
					explore();
				}
				break;
			case Enumerators::Faction::SEC:
				if (map.knowsOther(Enumerators::KindOfRoom::security, currentLocation)) {
					map.findSpecificRoom(Enumerators::KindOfRoom::security, currentLocation);
					enterRoom(map.getRoute()[1]);
				}
				else {
					explore();
				}
				break;
			default:
				std::cerr << "Wrong Faction for recruiting" << std::endl;
				break;
			}
		}
		break;
	case Enumerators::Desire::returnToClient:
		if (currentLocation != currentQuest->getClient()->getCurrentLocation()) {
			if (knowsRoom(currentQuest->getClient()->getCurrentLocation())) {
				map.findShortestRoute(currentLocation, currentQuest->getClient()->getCurrentLocation());
				enterRoom(map.getRoute()[1]);
			}
			else
				explore();
		}
		break;
	case Enumerators::Desire::scavenge:
		if (dynamic_cast<GatheringQuest*>(currentQuest)) {
			GatheringQuest* q = dynamic_cast<GatheringQuest*>(currentQuest);
			if (!scavenge(q->getRessource())) {
				map.findNearestRoomWithRessource(q->getRessource(), currentLocation);
				enterRoom(map.getRoute()[1]);
			}
		}
		else
			std::cerr << "Wrong Quest Type for this desire." << std::endl;
		break;
	case Enumerators::Desire::traverse:
		break;
	case Enumerators::Desire::getNewQuest:
		if (finishedQuests = 0)
			takePersonalQuest();
		else if (squad->getSize() < squad->getMaxSize() / 2)
			takePersonalQuest();
		else if (map.getKnownRooms()->size() < 10)
			takePersonalQuest();
		else {
			if (!takeNewQuest()) {
				if (map.findRoomWithAvailableQuest(currentLocation)) {
					enterRoom(map.getRoute()[1]);
				}
				else
					explore();
			}
		}
		break;
	default:
		std::cerr << "Wrong desire input" << std::endl;
	}
}

bool Leader::takeNewQuest()
{
	if (dynamic_cast<HiPRoom*>(currentLocation)) {
		HiPRoom* HiR = dynamic_cast<HiPRoom*>(currentLocation);
		if (HiR->getClient() != nullptr) {
			if (HiR->getClient()->hasAvailableQuest()) {
				if (takeQuest(HiR->getClient()))
					return true;
			}
		}
	}
	return false;
}

void Leader::takePersonalQuest()
{
	if ((explored && recruited) || (!explored && !recruited)) {
		if (rand() % 2 > 0)
			currentQuest = new ExploringQuest(this);
		else
			currentQuest = new RecruitingQuest(this);
	}
	else if (!explored)
		currentQuest = new ExploringQuest(this);
	else if (!recruited)
		currentQuest = new RecruitingQuest(this);
	else
		std::cerr << "Personal Quest ERROR!" << std::endl;
}

bool Leader::scavenge(Enumerators::Ressource ressource)
{
	if (dynamic_cast<HiPRoom*>(currentLocation) && dynamic_cast<HiPRoom*>(currentLocation)->hasRessource(ressource)) {
		HiPRoom* cL = dynamic_cast<HiPRoom*>(currentLocation);
		switch (ressource) {
		case Enumerators::Ressource::food:
			cL->takeFood(1);
			squad->getInventory()->addToInventory(Enumerators::Ressource::food, 1);
			break;
		case Enumerators::Ressource::meds:
			cL->takeMeds(1);
			squad->getInventory()->addToInventory(Enumerators::Ressource::meds, 1);
			break;
		case Enumerators::Ressource::scrap:
			cL->takeScrap(1);
			squad->getInventory()->addToInventory(Enumerators::Ressource::scrap, 1);
			break;
		case Enumerators::Ressource::weapons:
			cL->takeWeapon(1);
			break;
		default:
			std::cerr << "Can't gather this ressource" << std::endl;
			return false;
			break;
		}
		return true;
	}
	return false;
}

#pragma endregion

#pragma region HELPERS



void Leader::toggleFighting(bool b)
{
	isFighting = b;
}

bool Leader::knowsRoom(Room* toCheck)
{
	return map.knows(toCheck);
}

#pragma endregion

#pragma region GETTERS

// return the squad.
Squad* Leader::getSquad() const {
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


#pragma endregion

#pragma region PRINTERS

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

	std::string desireString = "";
	switch (currentDesire) {
	case Enumerators::Desire::deliver:
		desireString = "Delivering";
		break;
	case Enumerators::Desire::explore:
		desireString = "Exploring";
		break;
	case Enumerators::Desire::idle:
		desireString = "Waiting";
		break;
	case Enumerators::Desire::investigate:
		desireString = "Investigating";
		break;
	case Enumerators::Desire::recruit:
		desireString = "Recruiting";
		break;
	case Enumerators::Desire::returnToClient:
		desireString = "Returning Quest";
		break;
	case Enumerators::Desire::scavenge:
		desireString = "Scavenging";
		break;
	case Enumerators::Desire::traverse:
		desireString = "Traversing";
		break;
	default:
		desireString = "ERROR";
		break;
	}

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
		<< "	Quest:      " << questName << std::endl
		<< "	Desire:     " << desireString << std::endl << std::endl;
}

#pragma endregion