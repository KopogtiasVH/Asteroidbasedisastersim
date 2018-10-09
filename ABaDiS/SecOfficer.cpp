#include "stdafx.h"
#include "SecOfficer.h"

/*
	Security Officers are better versions of SecTroops. They are stronger, braver and can lead squads.
	TODO: They can get orders from an allknowing security system which monitors the whole base.
*/

SecOfficer::SecOfficer(Room* startingLocation) : Leader(startingLocation, Enumerators::Faction::SEC)
{

	kob = Enumerators::KindOfBeing::secofficer;

	// Add a random rank to the name.
	fullName = NameGenerator::randomRank(kob) + " " + fullName;

	// Get a Random class
	switch (rand() % 4) {
	case 0:
		oClass = Enumerators::OfficerClass::riotSpecialist;
		occupation = "Riot_Specialist";
		break;
	case 1:
		oClass = Enumerators::OfficerClass::detective;
		occupation = "Detective";
		break;
	case 2:
		oClass = Enumerators::OfficerClass::commander;
		occupation = "Security_Commander";
		break;
	case 3:
		oClass = Enumerators::OfficerClass::officer;
		occupation = "Security_Officer";
		break;
	default:
		break;
	}

	// SecOfficers recieve their weapon based on their class
	weapon = new Weapon(oClass);

	// Riot Specialists have more armor and always carry an Energy Baton
	if (oClass == Enumerators::OfficerClass::riotSpecialist)
		armor++;

	// Commanders can command a bigger squad
	if (oClass == Enumerators::OfficerClass::commander)
		maxSquadSize += 5;
}

// Generate a new SecTroop and add it to the squad
bool SecOfficer::recruit() {
	return squad->recruit(new SecTroop(this));
}

 // Add an existing SecTroop to the squad
bool SecOfficer::recruit(SecTroop newRecruit) {
	if ((dynamic_cast<HiPRoom*>(currentLocation) && dynamic_cast<HiPRoom*>(currentLocation)->getKor() == Enumerators::KindOfRoom::security) || currentLocation->)
	return squad->recruit(&newRecruit);
}

/*
	If the Squadsize is smaller than the maximum capacity of the room which should
	enter the squad enters it, else it leaves one behind and tries again
*/
void SecOfficer::enterRoom(Room* toEnter) {
	if (squad->getSize() + 1 < toEnter->getCapacity()) {
		toEnter->enteringBeings(squad->getSize() + 1);
		currentLocation->enteringBeings((squad->getSize() + 1)*-1);
		currentLocation->setPresence(Enumerators::Faction::NONE);
		currentLocation = toEnter;
		map.addRoom(currentLocation);
		if (toEnter->isPresent(Enumerators::Faction::NONE)) {
			toEnter->setPresence(faction);
		}
	}
	else {
		Being* toLeave = squad->getMember(0);
		squad->kick(toLeave);
		toEnter->addWaitingGoons(1);
		enterRoom(toEnter);
	}
}