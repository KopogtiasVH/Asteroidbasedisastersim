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

// Weapon Names
std::vector<std::string> NameGenerator::bluntWeapons;
std::vector<std::string> NameGenerator::pierceWeapons;
std::vector<std::string> NameGenerator::rangedWeapons;
std::vector<std::string> NameGenerator::explosiveWeapons;

std::string NameGenerator::roomName(int cap) {
	if (!isGenerated) {
		setupNameLists();
	}

	std::string name = "Sector-";

	if (cap < 200) {
		name += lowCapRooms[rand() % lowCapRooms.size()];
	}

	return name;
}

std::string NameGenerator::humanName(std::string gender) {
	std::string name = "";

	if (!isGenerated) {
		setupNameLists();
	}

	if (gender == "m") {
		name = name + maleNames[rand() % maleNames.size()];
		if (rand() % 100 + 1 < 30) {
			name += " " + maleNames[rand() % maleNames.size()];
		}
		if (rand() % 100 + 1 < 30) {
			name += " " + maleNames[rand() % maleNames.size()];
		}
	}
	else if (gender =="f") {
		name += femaleNames[rand() % femaleNames.size()];
		if (rand() % 100 + 1 < 30) {
			name += " " + femaleNames[rand() % femaleNames.size()];
		}
		if (rand() % 100 + 1 < 30) {
			name += " " + femaleNames[rand() % femaleNames.size()];
		}
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