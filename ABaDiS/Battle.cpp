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
	environmentalDamage = 0;
	frontWidth = battleground->getCapacity() / 10;

	// Additional Setup
	moraleCounter = 0;
	isOngoing = true;

	bodyCount = 0;
	memorial = std::vector<Being*>();
	title = "";

	prepareReserves();
}

// One Fighting Round
void Battle::fight() {
	prepareNextRound();
	calculateRound();
	endRound();
	if (!isOngoing)
		aftermath();
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
		int currentDamage = attackerFirstRow[i]->attack();
		if (currentDamage >= ENV_THRESHOLD || 
			(attackerFirstRow[i]->getWeapon()->getWeapontype() == Enumerators::Weapontype::ranged &&
			 attackerFirstRow[i]->getWeapon()->getNoOfUses() > 0))
			environmentalDamage++;
		if (attackerFirstRow[i]->getWeapon()->getWeapontype() == Enumerators::Weapontype::explosive &&
			attackerFirstRow[i]->getWeapon()->getNoOfUses() > 0)
			environmentalDamage += EXPLOSIVE_DAMAGE;
		if (attackerFirstRow.size() <= defenderFirstRow.size()) {
			defenderFirstRow[i]->doDamage(currentDamage);
		}
		else {
			defenderFirstRow[rand() % defenderFirstRow.size()]->doDamage(currentDamage);
		}
	}

	// Attackers Second Row Attacks if the have Ranged or Explosive Weapons
	for (int i = 0; i < attackerSecondRow.size(); i++) {
		if (attackerSecondRow[i]->getWeapon()->getWeapontype() == Enumerators::Weapontype::ranged &&
			attackerSecondRow[i]->getWeapon()->getNoOfUses() > 0)
			environmentalDamage++;
		if (attackerSecondRow[i]->getWeapon()->getWeapontype() == Enumerators::Weapontype::explosive &&
			attackerSecondRow[i]->getWeapon()->getNoOfUses() > 0)
			environmentalDamage += EXPLOSIVE_DAMAGE;
		if (attackerSecondRow[i]->getWeapon()->getWeapontype() == Enumerators::Weapontype::ranged ||
			attackerSecondRow[i]->getWeapon()->getWeapontype() == Enumerators::Weapontype::explosive) {
			defenderFirstRow[rand() % defenderFirstRow.size()]->doDamage(attackerSecondRow[i]->attack());
		}
		
	}

	// Defenders Front Row Attacks
	for (int i = 0; i < defenderFirstRow.size(); i++) {
		int currentDamage = defenderFirstRow[i]->attack();
		if (currentDamage >= ENV_THRESHOLD ||
			(defenderFirstRow[i]->getWeapon()->getWeapontype() == Enumerators::Weapontype::ranged &&
				defenderFirstRow[i]->getWeapon()->getNoOfUses() > 0))
			environmentalDamage++;
		if (defenderFirstRow[i]->getWeapon()->getWeapontype() == Enumerators::Weapontype::explosive &&
			defenderFirstRow[i]->getWeapon()->getNoOfUses() > 0)
			environmentalDamage += EXPLOSIVE_DAMAGE;
		if (defenderFirstRow.size() <= attackerFirstRow.size()) {
			attackerFirstRow[i]->doDamage(defenderFirstRow[i]->attack());
		}
		else {
			attackerFirstRow[rand() % attackerFirstRow.size()]->doDamage(defenderFirstRow[i]->attack());
		}
	}

	// Defenders Second Row Attacks if it has Ranged or Explosive Weapons
	for (int i = 0; i < defenderSecondRow.size(); i++) {
		if (defenderSecondRow[i]->getWeapon()->getWeapontype() == Enumerators::Weapontype::ranged &&
			defenderSecondRow[i]->getWeapon()->getNoOfUses() > 0)
			environmentalDamage++;
		if (defenderSecondRow[i]->getWeapon()->getWeapontype() == Enumerators::Weapontype::explosive &&
			defenderSecondRow[i]->getWeapon()->getNoOfUses() > 0)
			environmentalDamage += EXPLOSIVE_DAMAGE;
		if (defenderSecondRow[i]->getWeapon()->getWeapontype() == Enumerators::Weapontype::ranged ||
			defenderSecondRow[i]->getWeapon()->getWeapontype() == Enumerators::Weapontype::explosive) {
			attackerFirstRow[rand() % attackerFirstRow.size()]->doDamage(defenderSecondRow[i]->attack());
		}
	}

	return true;
}

// Empty out fallen and fleeing Units and check if the fight is going for another round
bool Battle::endRound() {
	// Clear Attacker First Row and apply Morale Hits
	std::vector<Being*>::iterator it = attackerFirstRow.begin();
	while (it != attackerFirstRow.end()) {
		Being* b = *it;
		if (b->getStatus() == Enumerators::BodyStatus::dead ||
			b->getStatus() == Enumerators::BodyStatus::severlyWounded ||
			b->getStatus() == Enumerators::BodyStatus::fleeing) {
			if (b->getStatus() == Enumerators::BodyStatus::dead) {
				bodyCount++;
				defenderMorale -= 3;
				memorial.push_back(b);
			}
			if (b->getStatus() == Enumerators::BodyStatus::severlyWounded) {
				woundedCount++;
				defenderMorale--;
			}
			if (b->getStatus() == Enumerators::BodyStatus::fleeing) {
				defenderMorale -= 2;
			}
			it = attackerFirstRow.erase(it);
		}
		else {
			++it;
		}
	}

	// Clear Attacker Second Row Completely
	it = attackerSecondRow.begin();
	while (it != attackerSecondRow.end()) {
		Being* b = *it;
		attackerReserve.push_back(b);
		++it;
	}
	attackerSecondRow = std::vector<Being*>();

	// Clear Defender First Row and apply Morale Hits
	it = defenderFirstRow.begin();
	while (it != defenderFirstRow.end()) {
		Being* b = *it;
		if (b->getStatus() == Enumerators::BodyStatus::dead ||
			b->getStatus() == Enumerators::BodyStatus::severlyWounded ||
			b->getStatus() == Enumerators::BodyStatus::fleeing) {
			if (b->getStatus() == Enumerators::BodyStatus::dead) {
				bodyCount++;
				attackerMorale -= 3;
				memorial.push_back(b);
			}
			if (b->getStatus() == Enumerators::BodyStatus::severlyWounded) {
				woundedCount++;
				attackerMorale--;
			}
			if (b->getStatus() == Enumerators::BodyStatus::fleeing) {
				attackerMorale -= 2;
			}
			it = defenderFirstRow.erase(it);
		}
		else {
			++it;
		}
	}
	// Clear out the Second Row Completely
	it = defenderSecondRow.begin();
	while (it != defenderSecondRow.end()) {
		Being* b = *it;
		defenderReserve.push_back(b);
		++it;
	}
	defenderSecondRow = std::vector<Being*>();

	// Apply Additional Morale Hits
	attackerMorale -= moraleCounter;
	defenderMorale -= moraleCounter;
	moraleCounter += 5;

	// Check if the Fight will continue another Round
	if (attackingLeader->getStatus() == Enumerators::BodyStatus::dead ||
		defendingLeader->getStatus() == Enumerators::BodyStatus::dead ||
		attackerMorale <= 0 ||
		defenderMorale <= 0 ||
		environmentalDamage >= currentCondition) {
		return false;
	}
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