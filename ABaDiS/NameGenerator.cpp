#include "stdafx.h"
#include "NameGenerator.h"
#include <iostream>

/*
	A static class which handles name generation.
*/

bool NameGenerator::isGenerated = false;

// Human Names
std::vector<std::string> NameGenerator::maleNames;
std::vector<std::string> NameGenerator::femaleNames;
std::vector<std::string> NameGenerator::surNames;

// Security Ranks & ANARC Jobs
std::vector<std::string> NameGenerator::secRanks;
std::vector<std::string> NameGenerator::previousJobs;

// Militia Words
std::vector<std::string> NameGenerator::militiaVerbs;
std::vector<std::string> NameGenerator::militiaNouns;

// Room Names
std::vector<std::string> NameGenerator::lowCapRooms;
std::vector<std::string> NameGenerator::medCapMedPrioRooms;
std::vector<std::string> NameGenerator::streetNamesFirst;
std::vector<std::string> NameGenerator::streetNamesLast;

// Weapon Names
std::vector<std::string> NameGenerator::bluntWeapons;
std::vector<std::string> NameGenerator::pierceWeapons;
std::vector<std::string> NameGenerator::rangedWeapons;
std::vector<std::string> NameGenerator::explosiveWeapons;

std::string NameGenerator::lowCapRoomName(int cap) {
	if (!isGenerated) {
		setupNameLists();
	}

	std::string name = "";

	if (cap < 2000) {
		if (!lowCapRooms.empty()) {
			int i = rand() % lowCapRooms.size();
			name += lowCapRooms[i];
			lowCapRooms.erase(lowCapRooms.begin() + i);
		}
		else {
			std::cout << "Room List Empty" << std::endl;
			name = "UNKNOWN_SECTOR";
		}
	}

	return name;
}

std::string NameGenerator::roomName(int cap, int prio) {
	if (!isGenerated) {
		setupNameLists();
	}

	std::string name = "";

	if (cap < 100) {
		if (!lowCapRooms.empty()) {
			int i = rand() % lowCapRooms.size();
			name += lowCapRooms[i];
			lowCapRooms.erase(lowCapRooms.begin() + i);
		}
		else {
			std::cout << "Room List Empty" << std::endl;
			name = "UNKNOWN_SECTOR";
		}
	}
	else if (cap < 300) {
		if (!medCapMedPrioRooms.empty()) {
			int i = rand() % medCapMedPrioRooms.size();
			name += medCapMedPrioRooms[i];
			medCapMedPrioRooms.erase(medCapMedPrioRooms.begin() + i);
		}
		else {
			std::cout << "Room List Empty" << std::endl;
			name = "UNKNOWN_SECTOR";
		}
	}

	return name;
}

std::string NameGenerator::streetName(Enumerators::KindOfRoom kor) {
	if (!isGenerated) {
		setupNameLists();
	}

	std::string name = "";
	if (!streetNamesFirst.empty()) {
		int i = rand() % streetNamesFirst.size();
		name += streetNamesFirst[i];
		streetNamesFirst.erase(streetNamesFirst.begin() + i);
	}
	else {
		std::cout << "Room List Empty" << std::endl;
		name += "UNKNOWN";
	}

	switch (kor) {
	case (Enumerators::KindOfRoom::livingQuarter):
		name += " " + streetNamesLast[rand() % streetNamesLast.size()];
		break;
	case (Enumerators::KindOfRoom::street):
		name += " " + streetNamesLast[rand() % streetNamesLast.size()];
		break;
	default:
		std::cout << "Wrong Kind of Room to recieve a street name" << std::endl;
		name += " UNKNOWN";
		break;
	}

	return name;
}

std::string NameGenerator::humanName(Enumerators::Gender gender) {
	std::string name = "";

	if (!isGenerated) {
		setupNameLists();
	}
	switch (gender) {
	case (Enumerators::Gender::male):
		name = name + maleNames[rand() % maleNames.size()];
		if (rand() % 100 + 1 < 25) {
			name += " " + maleNames[rand() % maleNames.size()];
		}
		if (rand() % 100 + 1 < 25) {
			name += " " + maleNames[rand() % maleNames.size()];
		}
		break;
	case (Enumerators::Gender::female):
		name += femaleNames[rand() % femaleNames.size()];
		if (rand() % 100 + 1 < 25) {
			name += " " + femaleNames[rand() % femaleNames.size()];
		}
		if (rand() % 100 + 1 < 25) {
			name += " " + femaleNames[rand() % femaleNames.size()];
		}
		break;
	default:
		std::cerr << "No suitable Gender found" << std::endl;
	}

	return name;
}

std::string NameGenerator::humanSurname() {
	if (!isGenerated) {
		setupNameLists();
	}

	return surNames[rand() % surNames.size()];
}

std::string NameGenerator::weaponName(Weapon::weapontype t) {
	if (!isGenerated) {
		setupNameLists();
	}

	if (t == Weapon::blunt)
		return bluntWeapons[rand() % bluntWeapons.size()];
	else if (t == Weapon::pierce)
		return pierceWeapons[rand() % pierceWeapons.size()];
	else if (t == Weapon::ranged)
		return rangedWeapons[rand() % rangedWeapons.size()];
	else if (t == Weapon::explosive)
		return explosiveWeapons[rand() % explosiveWeapons.size()];
}


std::string NameGenerator::randomRank(std::string toAssign) {
	if (!isGenerated) {
		setupNameLists();
	}
	
	if (toAssign == "sectroop")
		return secRanks[rand() % 5];
	else if (toAssign == "secofficer")
		return secRanks[rand() % 5 + 5];
}

std::string NameGenerator::randomRank(Enumerators::KindOfBeing toAssign)
{
	switch (toAssign) {
	case (Enumerators::KindOfBeing::sectroop):
		return secRanks[rand() % 5];
	case (Enumerators::KindOfBeing::secofficer):
		return secRanks[rand() % 5 + 5];
	default:
		std::cerr << "Wrong Kind of Being to recieve a Rank" << std::endl;
		return "";
	}
}

std::string NameGenerator::randomJob() {
	if (!isGenerated) {
		setupNameLists();
	}

	return previousJobs[rand() % previousJobs.size()];
}

std::string NameGenerator::militiaName(std::string name) {
	if (!isGenerated) {
		setupNameLists();
	}

	std::string result = "";

	if ((rand() % 100 + 1) < 33)
		result += name + "'s ";
	else {
		result += militiaVerbs[rand() % militiaVerbs.size()] + " ";
	}

	result += militiaNouns[rand() % militiaNouns.size()];

	return result;
}


void NameGenerator::setupNameLists()
{
	maleNames = fileToStringVector("./data/maleNames.csv");
	femaleNames = fileToStringVector("./data/femaleNames.csv");
	surNames = fileToStringVector("./data/surNames.csv");

	secRanks = fileToStringVector("./data/secRanks.csv");
	previousJobs = fileToStringVector("./data/previousJobs.csv");

	militiaVerbs = fileToStringVector("./data/militiaVerbs.csv");
	militiaNouns = fileToStringVector("./data/militiaNouns.csv");

	lowCapRooms = fileToStringVector("./data/lowCapRooms.csv");
	medCapMedPrioRooms = fileToStringVector("./data/medCapLowPrioRooms.csv");
	streetNamesFirst = fileToStringVector("./data/streetNamesFirst.csv");
	streetNamesLast = fileToStringVector("./data/streetNamesLast.csv");

	bluntWeapons = fileToStringVector("./data/bluntWeapons.csv");
	pierceWeapons = fileToStringVector("./data/pierceWeapons.csv");
	rangedWeapons = fileToStringVector("./data/rangedWeapons.csv");
	explosiveWeapons = fileToStringVector("./data/explosiveWeapons.csv");
	
	isGenerated = true;
}

std::vector<std::string> NameGenerator::fileToStringVector(std::string myFileName) {
	std::string line;
	std::ifstream myFile;
	std::vector<std::string> result;

	myFile.open(myFileName);
	if (myFile.is_open()) {
		while (!myFile.eof()) {
			myFile >> line;
			result.push_back(line);
		}
	}
	return result;
}