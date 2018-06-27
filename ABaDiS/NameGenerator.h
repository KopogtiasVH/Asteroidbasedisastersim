#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Weapon.h"

class NameGenerator
{
public:
	static std::string humanName(std::string gender);
	static std::string roomName(int cap);
	static std::string weaponName(Weapon::weapontype);

	static void setupNameLists();
	static std::vector<std::string> fileToStringVector(std::string myFileName);
	static bool isGenerated;

private:

	static std::vector<std::string> maleNames;
	static std::vector<std::string> femaleNames;
	static std::vector<std::string> surNames;

	static std::vector<std::string> lowCapRooms;
	
	static std::vector<std::string> bluntWeapons;
	static std::vector<std::string> pierceWeapons;
	static std::vector<std::string> rangedWeapons;
	static std::vector<std::string> explosiveWeapons;
};

