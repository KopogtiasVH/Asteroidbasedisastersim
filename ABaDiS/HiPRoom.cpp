#include "stdafx.h"
#include "HiPRoom.h"


HiPRoom::HiPRoom() : Room()
{
	switch (rand() % 4) {
	case 0:
		kor = Enumerators::KindOfRoom::docks;
		food = rand() % maxCapacity / 4;
		scrap = maxCapacity / 2 + rand() % maxCapacity;
		weapons = 0;
		population = 0;
		break;
	case 1:
		kor = Enumerators::KindOfRoom::livingQuarter;
		food = rand() % maxCapacity / 2;
		scrap = rand() % maxCapacity / 4;
		weapons = 0;
		population = maxCapacity;
		break;
	case 2:
		kor = Enumerators::KindOfRoom::warehouse;
		food = maxCapacity / 2 + rand() % maxCapacity;
		scrap = rand() % maxCapacity / 4;
		weapons = rand() % 3;
		population = 0;
		break;
	case 3:
		kor = Enumerators::KindOfRoom::security;
		food = 0;
		scrap = 0;
		weapons = maxCapacity / 10;
		population = rand() % 3;
		break;
	default:
		std::cerr << "Something went wrong" << std::endl;
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
