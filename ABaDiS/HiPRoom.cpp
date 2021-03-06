#include "stdafx.h"
#include "HiPRoom.h"


HiPRoom::HiPRoom(int p) : Room(p)
{
	// Throw a dice to generate the type of this high priority room
	switch (rand() % 4) {
	case 0:
		// Docks have high supply on scrap and some food
		kor = Enumerators::KindOfRoom::docks;
		food = rand() % maxCapacity / 4;
		scrap = maxCapacity / 2 + rand() % maxCapacity;
		weapons = 0;
		population = 0;
		meds = rand() % 5;
		break;
	case 1:
		// living quarters have some of mostly everything and are the main source of recruitable MobGoons
		kor = Enumerators::KindOfRoom::livingQuarter;
		food = rand() % maxCapacity / 2;
		scrap = rand() % maxCapacity / 4;
		weapons = 0;
		population = maxCapacity;
		meds = rand() % 5;
		break;
	case 2:
		// Warehouses have high supply of food, some scrap and sometimes even weapons
		kor = Enumerators::KindOfRoom::warehouse;
		food = maxCapacity / 2 + rand() % maxCapacity;
		scrap = rand() % maxCapacity / 4;
		weapons = rand() % 3;
		population = 0;
		meds = rand() % 5;
		break;
	case 3:
		// Security Checkpoints have weapons and sometimes a prisoner or two
		kor = Enumerators::KindOfRoom::security;
		food = 0;
		scrap = 0;
		weapons = maxCapacity / 10;
		population = rand() % 3;
		meds = rand() % 5;
		break;
	default:
		std::cerr << "Wrong type of HiPRoom generated" << std::endl;
	}

	name = "NEEDS ASSIGNMENT";
	populationList = std::set<Being*>();
	client = nullptr;
}

// Other

// Set the Name -- Must be done later because it must be connected to a Corridor before a Name can be generated
void HiPRoom::setName() {
	for (Room* r : connectedTo) {
		if (dynamic_cast<Corridor*>(r)) {
			name = NameGenerator::hiPRoomName(kor, r->getName());
			break;
		}
	}
}

void HiPRoom::printRoom()
{
	std::string korString;
	switch (kor) {
	case Enumerators::KindOfRoom::docks:
		korString = "Docks";
		break;
	case Enumerators::KindOfRoom::generic:
		korString = "Generic";
		break;
	case Enumerators::KindOfRoom::livingQuarter:
		korString = "Living Quarters";
		break;
	case Enumerators::KindOfRoom::security:
		korString = "Security Checkpoint";
		break;
	case Enumerators::KindOfRoom::street:
		korString = "Corridor";
		break;
	case Enumerators::KindOfRoom::warehouse:
		korString = "Storage Unit";
		break;
	default:
		korString = "ERROR";
		break;
	}

	std::cout << name << ":" << std::endl
		<< "	Capacity:   " << getCurrentCapacity() << " / " << getCapacity() << std::endl
		<< "	Condition:  " << getCurrentCondition() << " / " << getMaxCondition() << std::endl
		<< "	Priority:   " << getPriority() << std::endl
		<< "	Roomtype:   " << korString << std::endl
		<< "	Food:       " << getFood() << std::endl
		<< "	Scrap:      " << getScrap() << std::endl
		<< "	Weapons:    " << getWeapons() << std::endl
		<< "	Meds:       " << getMeds() << std::endl
		<< "	Population: " << getPopulation() << std::endl << std::endl;

}

void HiPRoom::addPop(Being * toAdd)
{
	populationList.insert(toAdd);
}

Being * HiPRoom::draftPop(int p)
{
	Being* recruit = nullptr;
	for (Being* b : populationList) {
		if (p + BaseSystemHandler::getTension() > b->getPersuadability()) {
			recruit = b;
			break;
		}
	}
	if (recruit != nullptr)
		populationList.erase(recruit);
	return recruit;
}

void HiPRoom::setClient(Client * c)
{
	client = c;
}

Client * HiPRoom::getClient()
{
	return client;
}

// Getters
int HiPRoom::getFood()
{
	return food;
}

int HiPRoom::getScrap()
{
	return scrap;
}

int HiPRoom::getWeapons()
{
	return weapons;
}

int HiPRoom::getPopulation()
{
	return population;
}

int HiPRoom::getMeds()
{
	return meds;
}

bool HiPRoom::hasRessource(Enumerators::Ressource r)
{
	switch (r) {
	case Enumerators::Ressource::food:
		return getFood() > 0;
		break;
	case Enumerators::Ressource::meds:
		return getMeds() > 0;
		break;
	case Enumerators::Ressource::scrap:
		return getScrap() > 0;
		break;
	case Enumerators::Ressource::population:
		return getPopulation() > 0;
		break;
	case Enumerators::Ressource::weapons:
		return getWeapons() > 0;
		break;
	default:
		std::cerr << "Error at ressource" << std::endl;
		return false;
		break;
	}
}

bool HiPRoom::takeFood(int toDeduct)
{
	if (food - toDeduct >= 0)
		food -= toDeduct;
	else
		return false;
	return true;
}

bool HiPRoom::takeScrap(int toDeduct)
{
	if (scrap - toDeduct >= 0)
		scrap -= toDeduct;
	else
		return false;
	return true;
}

bool HiPRoom::takeWeapon(int toDeduct)
{
	if (weapons - toDeduct >= 0)
		weapons -= toDeduct;
	else
		return false;
	return true;
}

bool HiPRoom::takePopulation(int toDeduct)
{
	if (population - toDeduct >= 0)
		population -= toDeduct;
	else
		return false;
	return true;
}

bool HiPRoom::takeMeds(int toDeduct)
{
	if (meds - toDeduct >= 0)
		meds -= toDeduct;
	else
		return false;
	return true;
}

bool HiPRoom::hasPopulation()
{
	return populationList.size() > 0;
}