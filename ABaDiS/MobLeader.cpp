#include "stdafx.h"
#include "MobLeader.h"

/*
	MobLeaders are the most important asset of the ANARC. Without them the raging mob has no coordination and is doomed to fail.
*/

MobLeader::MobLeader(Room* startingLocation) : Leader(startingLocation, Enumerators::Faction::ANARC)
{

	kob = Enumerators::KindOfBeing::mobleader;

	// Get a Random class
	switch (rand() % 4) {
	case 0:
		lClass = MobLeader::crimeBoss;
		occupation = "Crime_Boss";
		break;
	case 1:
		lClass = MobLeader::campaigner;
		occupation = "Campaigner";
		break;
	case 2:
		lClass = MobLeader::leader;
		occupation = "Leader";
		break;
	case 3:
		lClass = MobLeader::exmilitary;
		occupation = "Veteran";
	default:
		break;
	}

	// MobLeaders always carry a ranged weapon.
	weapon = new Weapon(Enumerators::Weapontype::ranged);


	// Crime Bosses have a bigger squad
	if (lClass == MobLeader::crimeBoss) {
		maxSquadSize += 5;
		squad->setMaxSize(maxSquadSize);
	}

	if (lClass == MobLeader::campaigner) {
		charisma += 2;
	}

}

// Generate a new Goon and add it to the mob
bool MobLeader::recruit() {
	if (((dynamic_cast<HiPRoom*>(currentLocation) && (dynamic_cast<HiPRoom*>(currentLocation)->getKor() == Enumerators::KindOfRoom::livingQuarter))
		&& (dynamic_cast<HiPRoom*>(currentLocation)->getPopulation() > 0))
		|| currentLocation->hasWaitingGoons()) {
		if (currentLocation->hasWaitingGoons()) {
			recruit(currentLocation->draftWaitingGoons());
		}
		else {
			Being* newRecruit = dynamic_cast<HiPRoom*>(currentLocation)->draftPop(charisma);
			if (newRecruit != nullptr) {
				recruit(dynamic_cast<MobGoon*>(newRecruit));
				return true;
			}
			else {
				// Charisma and or Tension too low to recruit in this Room.
				return false;
			}
		}
	}
	else {
		// Wrong or Empty Room => not suitable for recruiting
		return false;
	}
}

bool MobLeader::recruit(MobGoon* newRecruit) {
	return squad->recruit(newRecruit);
}

void MobLeader::enterRoom(Room* toEnter) {
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
		toEnter->addWaitingGoons(dynamic_cast<MobGoon*>(squad->getMember(0)));
		squad->kick(toLeave);
		enterRoom(toEnter);
	}
}