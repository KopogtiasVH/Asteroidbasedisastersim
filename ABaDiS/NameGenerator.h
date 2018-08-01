#pragma once
#include "stdafx.h"
#include <vector>
#include <string>
#include "Weapon.h"

class NameGenerator
{
public:

	// Humans
	static std::string humanName(Enumerators::Gender);
	static std::string humanSurname();

	// Human additional
	static std::string randomRank(Enumerators::KindOfBeing);
	static std::string randomJob();
	static std::string militiaName(std::string);

	// Rooms
	static std::string lowCapRoomName(int cap);
	static std::string medCapRoomName();
	static std::string roomName(int, int);
	static std::string hiPRoomName(Enumerators::KindOfRoom);
	static std::string streetName(Enumerators::KindOfRoom);

	// Weapons
	static std::string weaponName(Enumerators::Weapontype);
	
	// Battles
	static std::string battleName(std::string, int);

	// Companies
	static std::string companyName();

	// Additional Methods
	static void setupNameLists();
	static std::vector<std::string> fileToStringVector(std::string myFileName);

private:
	// Boolean to detect if the following vectors are already populated
	static bool isGenerated;

	// Humans
	static std::vector<std::string> maleNames;
	static std::vector<std::string> femaleNames;
	static std::vector<std::string> surNames;

	// Humans Additional
	static std::vector<std::string> secRanks;
	static std::vector<std::string> previousJobs;
	static std::vector<std::string> militiaVerbs;
	static std::vector<std::string> militiaNouns;

	// Rooms
	static std::vector<std::string> lowCapRooms;
	static std::vector<std::string> medCapMedPrioRooms;
	static std::vector<std::string> medCapLowPrioTypes;
	static std::vector<std::string> streetNamesFirst;
	static std::vector<std::string> streetNamesLast;
	static std::vector<std::string> asianWords;
	static std::vector<std::string> nerdWords;
	static std::vector<std::string> nightlifeWords;
	
	// Weapons
	static std::vector<std::string> bluntWeapons;
	static std::vector<std::string> pierceWeapons;
	static std::vector<std::string> rangedWeapons;
	static std::vector<std::string> explosiveWeapons;

	// Battles
	static std::vector<std::string> battleNouns;
	static std::vector<std::string> battlePrepositions;

	// Companies
	static std::vector<std::string> alphabet;
	static std::vector<std::string> corporationFirst;
	static std::vector<std::string> corporationSecond;
	static std::vector<std::string> corporationLast;
};

