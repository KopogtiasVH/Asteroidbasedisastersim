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
std::vector<std::string> NameGenerator::asianWords;
std::vector<std::string> NameGenerator::nerdWords;
std::vector<std::string> NameGenerator::nightlifeWords;
std::vector<std::string> NameGenerator::medCapLowPrioTypes;

// Weapon Names
std::vector<std::string> NameGenerator::bluntWeapons;
std::vector<std::string> NameGenerator::pierceWeapons;
std::vector<std::string> NameGenerator::rangedWeapons;
std::vector<std::string> NameGenerator::explosiveWeapons;

// Battle Names
std::vector<std::string> NameGenerator::battleNouns;
std::vector<std::string> NameGenerator::battlePrepositions;

// Return a First (Or second/third) name for a Human
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

// Return a Human Surname
std::string NameGenerator::humanSurname() {
	if (!isGenerated) {
		setupNameLists();
	}

	return surNames[rand() % surNames.size()];
}

// Return a Rank for a security Person based on his or hers Rank
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

// Return a Job (just for flavor)
std::string NameGenerator::randomJob() {
	if (!isGenerated) {
		setupNameLists();
	}

	return previousJobs[rand() % previousJobs.size()];
}

// Return a Name for a ANARC Squad
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

// Return a Name for a Low Capacity Room
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

// Return a name for a medium / high capacity room
std::string NameGenerator::medCapRoomName() {
	if (!isGenerated) {
		setupNameLists();
	}

	std::string type = "";
	std::string name = "";
	std::string fullname = "";

	type = medCapLowPrioTypes[rand() % medCapLowPrioTypes.size()];
	if (type == "Brothel" || type == "Nightclub" || type == "Pub" || type == "Bar" || type == "Truckstop") {
		if (rand() % 100 < 33 || nightlifeWords.empty()) {
			name = surNames[rand() % surNames.size()];
			name += "'s";
		}
		else {
			int i = rand() % nightlifeWords.size();
			name = nightlifeWords[i];
			nightlifeWords.erase(nightlifeWords.begin() + i);
		}
		fullname = name + " " + type;
	}
	else if (type == "AsianRestaurant") {
		int i = rand() % asianWords.size();
		name = asianWords[i];
		asianWords.erase(asianWords.begin() + i);
		fullname = type + " " + name;
	}
	else if (type == "CapsuleHotel") {
		if (rand() % 100 < 75) {
			int i = rand() % asianWords.size();
			name = asianWords[i];
			asianWords.erase(asianWords.begin() + i);
			fullname = name + " " + type;
		}
		else {
			int i = rand() % streetNamesFirst.size();
			name = streetNamesFirst[i];
			streetNamesFirst.erase(streetNamesFirst.begin() + i);
			fullname = name + " " + type;
		}
	}
	else if (type == "Internetcafe") {
		int i = rand() % nerdWords.size();
		name = nerdWords[i];
		nerdWords.erase(nerdWords.begin() + i);
		fullname = name + " " + type;
	}
	else {
		if (rand() % 100 < 50) {
			int i = rand() % streetNamesFirst.size();
			name = streetNamesFirst[i];
			streetNamesFirst.erase(streetNamesFirst.begin() + i);
			fullname = name + " " + type;
		}
		else {
			name = surNames[rand() % surNames.size()];
			name += "'s";
			fullname = name + " " + type;
		}
	}
	return fullname;
}

// TODO: check if this is already obsolete
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
			name = medCapRoomName();
	}

	return name;
}

// Return a name for a street or living quarter
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

// Return a name for a weapon, based on it's type
std::string NameGenerator::weaponName(Enumerators::Weapontype t) {
	if (!isGenerated) {
		setupNameLists();
	}

	switch (t) {
	case (Enumerators::Weapontype::blunt):
		return bluntWeapons[rand() % bluntWeapons.size()];
		break;
	case (Enumerators::Weapontype::pierce):
		return pierceWeapons[rand() % pierceWeapons.size()];
		break;
	case (Enumerators::Weapontype::ranged):
		return rangedWeapons[rand() % rangedWeapons.size()];
		break;
	case (Enumerators::Weapontype::explosive):
		return explosiveWeapons[rand() % explosiveWeapons.size()];
		break;
	default:
		std::cerr << "Wrong Weapon Type" << std::endl;
		return "";
	}
}

// Return a name for a battle fought in the Base
std::string NameGenerator::battleName(std::string rN, int bc) {
	std::string name;
	if (bc <= 20) {
		name = battleNouns[rand() % 10] + " " 
			+ battlePrepositions[rand() % battlePrepositions.size()] + " " 
			+ rN;
	}
	else {
		name = rN + " " + battleNouns[(rand() % 10) + 10];
	}

	return name;
}

// Fill the Vectors with the words from the .csv files in the data Folder
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
	asianWords = fileToStringVector("./data/asianWords.csv");
	nerdWords = fileToStringVector("./data/nerdWords.csv");
	nightlifeWords = fileToStringVector("./data/nightlifeWords.csv");
	medCapLowPrioTypes = fileToStringVector("./data/medCapLowPrioType.csv");

	bluntWeapons = fileToStringVector("./data/bluntWeapons.csv");
	pierceWeapons = fileToStringVector("./data/pierceWeapons.csv");
	rangedWeapons = fileToStringVector("./data/rangedWeapons.csv");
	explosiveWeapons = fileToStringVector("./data/explosiveWeapons.csv");

	battleNouns = fileToStringVector("./data/battleNouns.csv");
	battlePrepositions = fileToStringVector("./data/battlePrepositions.csv");
	
	isGenerated = true;
}

// Return all the words from the .csv files as a vector of strings
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