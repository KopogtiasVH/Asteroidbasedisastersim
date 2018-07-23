#include "stdafx.h"
#include "Battle.h"
#include <iterator>


Battle::Battle(Leader* a, Leader* b, Room* r)
{
	// Prepare Attackers Vectors and Morale.
	attackingLeader = a;
	defenderFirstRow = std::vector<Being*>();
	attackerSecondRow = std::vector<Being*>();
	attackerReserve = attackingLeader->getSquad()->getMembers();
	
	attackerMorale = attackingLeader->getCurrentMorale();
	for (Being* b : attackerReserve)
		attackerMorale += b->getCurrentMorale();

	// Prepare Defenders Vectors and Morale.
	defendingLeader = b;
	defenderFirstRow = std::vector<Being*>();
	defenderSecondRow = std::vector<Being*>();
	defenderReserve = defendingLeader->getSquad()->getMembers();

	defenderMorale = defendingLeader->getCurrentMorale();
	for (Being* b : defenderReserve)
		defenderMorale += b->getCurrentMorale();

	// Prepare the Battlefield
	battleground = r;
	currentCondition = battleground->getCurrentCondition();
	frontWidth = battleground->getCapacity() / 10;

	// Additional Setup
	moraleCounter = 0;
	isOngoing = true;

	bodyCount = 0;
	memorial = std::vector<Being*>();
	title = "";

	std::cout << "Attackers Morale: " << attackerMorale << std::endl;
	std::cout << "Defenders Morale: " << defenderMorale << std::endl;
}
// Fill the Row Vectors with new Units to max out the frontWidth
bool Battle::prepareNextRound() {

	// Fill the Front Row, preferably with Closed Range Units
	std::vector<Being*>::iterator it = attackerReserve.begin();
	while (it != attackerReserve.end()) {
		Being* b = *it;
		if ((b->getWeapon()->getWeapontype() == Enumerators::Weapontype::blunt ||
			b->getWeapon()->getWeapontype() == Enumerators::Weapontype::pierce) &&
			attackerFirstRow.size() < frontWidth) {
			attackerFirstRow.push_back(b);
			it = attackerReserve.erase(it);
		}
		else {
			++it;
		}
	}
	// If there is still space in the front row, fill it with other units
	if (attackerFirstRow.size() < frontWidth &&
		attackerReserve.size() > 0) {
		it = attackerReserve.begin();
		while (it != attackerReserve.end()) {
			Being* b = *it;
			if (attackerFirstRow.size() < frontWidth) {
				attackerFirstRow.push_back(b);
				it = attackerReserve.erase(it);
			}
			else {
				++it;
			}
		}
	}
	// Fill the second Row, preferably with ranged or explosive weapons.
	it = attackerReserve.begin();
	while (it != attackerReserve.end()) {
		Being* b = *it;
		if ((b->getWeapon()->getWeapontype() == Enumerators::Weapontype::ranged ||
			b->getWeapon()->getWeapontype() == Enumerators::Weapontype::explosive) &&
			attackerSecondRow.size() < frontWidth) {
			attackerSecondRow.push_back(b);
			it = attackerReserve.erase(it);
		}
		else {
			++it;
		}
	}
	// If there is still space in the second row, fill it with other units
	if (attackerSecondRow.size() < frontWidth &&
		attackerReserve.size() > 0) {
		it = attackerReserve.begin();
		while (it != attackerReserve.end()) {
			Being* b = *it;
			if (attackerSecondRow.size() < frontWidth) {
				attackerSecondRow.push_back(b);
				it = attackerReserve.erase(it);
			}
			else {
				++it;
			}
		}
	}

	// Repeat this for the defender.
	// Fill the Front Row, preferably with Closed Range Units
	it = defenderReserve.begin();
	while (it != defenderReserve.end()) {
		Being* b = *it;
		if ((b->getWeapon()->getWeapontype() == Enumerators::Weapontype::blunt ||
			b->getWeapon()->getWeapontype() == Enumerators::Weapontype::pierce) &&
			defenderFirstRow.size() < frontWidth) {
			defenderFirstRow.push_back(b);
			it = defenderReserve.erase(it);
		}
		else {
			++it;
		}
	}
	// If there is still space in the front row, fill it with other units
	if (defenderFirstRow.size() < frontWidth &&
		defenderReserve.size() > 0) {
		it = defenderReserve.begin();
		while (it != defenderReserve.end()) {
			Being* b = *it;
			if (defenderFirstRow.size() < frontWidth) {
				defenderFirstRow.push_back(b);
				it = defenderReserve.erase(it);
			}
			else {
				++it;
			}
		}
	}
	// Fill the second Row, preferably with ranged or explosive weapons.
	it = defenderReserve.begin();
	while (it != defenderReserve.end()) {
		Being* b = *it;
		if ((b->getWeapon()->getWeapontype() == Enumerators::Weapontype::ranged ||
			b->getWeapon()->getWeapontype() == Enumerators::Weapontype::explosive) &&
			defenderSecondRow.size() < frontWidth) {
			defenderSecondRow.push_back(b);
			it = defenderReserve.erase(it);
		}
		else {
			++it;
		}
	}
	// If there is still space in the second row, fill it with other units
	if (defenderSecondRow.size() < frontWidth &&
		defenderReserve.size() > 0) {
		it = defenderReserve.begin();
		while (it != defenderReserve.end()) {
			Being* b = *it;
			if (defenderSecondRow.size() < frontWidth) {
				defenderSecondRow.push_back(b);
				it = defenderReserve.erase(it);
			}
			else {
				++it;
			}
		}
	}

	return true;
}

// Calculate and distribute the Damage
bool Battle::calculateRound() {
	// Attackers Front Row Attacks
	for (int i = 0; i < attackerFirstRow.size(); i++) {
		if (attackerFirstRow.size() <= defenderFirstRow.size()) {
			defenderFirstRow[i]->doDamage(attackerFirstRow[i]->attack());
		}
		else {
			defenderFirstRow[rand() % defenderFirstRow.size()]->doDamage(attackerFirstRow[i]->attack());
		}
	}

	// Attackers Second Row Attacks if the have Ranged or Explosive Weapons
	for (int i = 0; i < attackerSecondRow.size(); i++) {
		if (attackerSecondRow[i]->getWeapon()->getWeapontype() == Enumerators::Weapontype::ranged ||
			attackerSecondRow[i]->getWeapon()->getWeapontype() == Enumerators::Weapontype::explosive) {
			defenderFirstRow[rand() % defenderFirstRow.size()]->doDamage(attackerSecondRow[i]->attack());
		}
	}

	// Defenders Front Row Attacks
	for (int i = 0; i < defenderFirstRow.size(); i++) {
		if (defenderFirstRow.size() <= attackerFirstRow.size()) {
			attackerFirstRow[i]->doDamage(defenderFirstRow[i]->attack());
		}
		else {
			attackerFirstRow[rand() % attackerFirstRow.size()]->doDamage(defenderFirstRow[i]->attack());
		}
	}

	// Defenders Second Row Attacks if it has Ranged or Explosive Weapons
	for (int i = 0; i < defenderSecondRow.size(); i++) {
		if (defenderSecondRow[i]->getWeapon()->getWeapontype() == Enumerators::Weapontype::ranged ||
			defenderSecondRow[i]->getWeapon()->getWeapontype() == Enumerators::Weapontype::explosive) {
			attackerFirstRow[rand() % attackerFirstRow.size()]->doDamage(defenderSecondRow[i]->attack());
		}
	}

	return true;
}

bool Battle::endRound() {
	// Empty out fallen and fleeing Units and check if the fight is going for another round
	return true;
}

bool Battle::aftermath() {
	// Tell the Basesystem and the participating Leaders the outcome of the battle
	return true;
}

// Remove the Severly Wounded from the reserves
bool Battle::prepareReserves() {
	std::vector<Being*>::iterator it = attackerReserve.begin();
	while (it != attackerReserve.end()) {
		Being* b = *it;
		if (b->getStatus() == Enumerators::BodyStatus::severlyWounded) {
			it = attackerReserve.erase(it);
		}
		else {
			++it;
		}
	}
	it = defenderReserve.begin();
	while (it != defenderReserve.end()) {
		Being* b = *it;
		if (b->getStatus() == Enumerators::BodyStatus::severlyWounded) {
			it = defenderReserve.erase(it);
		}
		else {
			++it;
		}
	}
	return true;
}