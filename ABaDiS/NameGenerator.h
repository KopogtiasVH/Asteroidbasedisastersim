#pragma once
#include "stdafx.h"
#include <vector>
#include <string>
#include "Weapon.h"

class NameGenerator
{
public:
	static std::string humanName(Enumerators::Gender);
	static std::string humanSurname();
	static std::string lowCapRoomName(int cap);
	static std::string medCapRoomName();
	static std::string roomName(int, int);
	static std::string streetName(Enumerators::KindOfRoom);
	static std::string weaponName(Enumerators::Weapontype);
	static std::string randomRank(Enumerators::KindOfBeing);
	static std::string randomJob();
	static std::string militiaName(std::string);
	static std::string battleName(std::string, int);

	static void setupNameLists();
	static std::vector<std::string> fileToStringVector(std::string myFileName);

	static bool isGenerated;

private:

	static std::vector<std::string> maleNames;
	static std::vector<std::string> femaleNames;
	static std::vector<std::string> surNames;

	static std::vector<std::string> secRanks;
	static std::vector<std::string> previousJobs;

	static std::vector<std::string> militiaVerbs;
	static std::vector<std::string> militiaNouns;

	static std::vector<std::string> lowCapRooms;
	static std::vector<std::string> medCapMedPrioRooms;
	static std::vector<std::string> medCapLowPrioTypes;
	static std::vector<std::string> streetNamesFirst;
	static std::vector<std::string> streetNamesLast;
	static std::vector<std::string> asianWords;
	static std::vector<std::string> nerdWords;
	static std::vector<std::string> nightlifeWords;
	
	static std::vector<std::string> bluntWeapons;
	static std::vector<std::string> pierceWeapons;
	static std::vector<std::string> rangedWeapons;
	static std::vector<std::string> explosiveWeapons;

	static std::vector<std::string> battleNouns;
	static std::vector<std::string> battlePrepositions;
};

