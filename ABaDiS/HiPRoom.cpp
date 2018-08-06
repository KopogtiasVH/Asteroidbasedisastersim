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
		break;
	case 1:
		// living quarters have some of mostly everything and are the main source of recruitable MobGoons
		kor = Enumerators::KindOfRoom::livingQuarter;
		food = rand() % maxCapacity / 2;
		scrap = rand() % maxCapacity / 4;
		weapons = 0;
		population = maxCapacity;
		break;
	case 2:
		// Warehouses have high supply of food, some scrap and sometimes even weapons
		kor = Enumerators::KindOfRoom::warehouse;
		food = maxCapacity / 2 + rand() % maxCapacity;
		scrap = rand() % maxCapacity / 4;
		weapons = rand() % 3;
		population = 0;
		break;
	case 3:
		// Security Checkpoints have weapons and sometimes a prisoner or two
		kor = Enumerators::KindOfRoom::security;
		food = 0;
		scrap = 0;
		weapons = maxCapacity / 10;
		population = rand() % 3;
		break;
	default:
		std::cerr << "Something went wrong" << std::endl;
	}

	name = "NEEDS ASSIGNMENT";
}

// Other

// Set the Name -- Must be done later because it must be connected to a Corridor before a Name can be generated
void HiPRoom::setName() {
	for (Room* r : connectedTo) {
		if (dynamic_cast<Corridor*>(r)) {
			name = NameGenerator::hiPRoomName(kor, r->getName());
			std::cout << "name assignment" << std::endl;
		}
	}
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

Enumerators::KindOfRoom HiPRoom::getKor()
{
	return kor;
}
