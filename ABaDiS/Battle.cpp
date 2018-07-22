#include "stdafx.h"
#include "Battle.h"
#include <iterator>


Battle::Battle(Leader* a, Leader* b, Room* r)
{
	attackingLeader = a;
	defenderFirstRow = std::vector<Being*>();
	attackerSecondRow = std::vector<Being*>();
	attackerReserve = attackingLeader->getSquad()->getMembers();
	
	attackerMorale = attackingLeader->getCurrentMorale();
	for (Being* b : attackerReserve)
		attackerMorale += b->getCurrentMorale();

	defendingLeader = b;
	defenderFirstRow = std::vector<Being*>();
	defenderSecondRow = std::vector<Being*>();
	defenderReserve = defendingLeader->getSquad()->getMembers();

	defenderMorale = defendingLeader->getCurrentMorale();
	for (Being* b : defenderReserve)
		defenderMorale += b->getCurrentMorale();

	battleground = r;
	currentCondition = battleground->getCurrentCondition();
	frontWidth = battleground->getCapacity() / 10;

	moraleCounter = 0;
	isOngoing = true;

	bodyCount = 0;
	memorial = std::vector<Being*>();
	title = "";
}

bool Battle::prepareNextRound() {
	// Fill the Row Vectors with new Units to max out the frontWidth

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
		std::vector<Being*>::iterator itii = attackerReserve.begin();
		while (itii != attackerReserve.end()) {
			Being* b = *itii;
			if (attackerFirstRow.size() < frontWidth) {
				attackerFirstRow.push_back(b);
				itii = attackerReserve.erase(itii);
			}
			else {
				++itii;
			}
		}
	}
	// Fill the second Row, preferably with ranged or explosive weapons.
	std::vector<Being*>::iterator itiii = attackerReserve.begin();
	while (itiii != attackerReserve.end()) {
		Being* b = *itiii;
		if ((b->getWeapon()->getWeapontype() == Enumerators::Weapontype::ranged ||
			b->getWeapon()->getWeapontype() == Enumerators::Weapontype::explosive) &&
			attackerSecondRow.size() < frontWidth) {
			attackerSecondRow.push_back(b);
			itiii = attackerReserve.erase(itiii);
		}
		else {
			++itiii;
		}
	}
	// If there is still space in the second row, fill it with other units
	if (attackerSecondRow.size() < frontWidth &&
		attackerReserve.size() > 0) {
		std::vector<Being*>::iterator itiv = attackerReserve.begin();
		while (itiv != attackerReserve.end()) {
			Being* b = *itiv;
			if (attackerSecondRow.size() < frontWidth) {
				attackerSecondRow.push_back(b);
				itiv = attackerReserve.erase(itiv);
			}
			else {
				++itiv;
			}
		}
	}

	// Repeat this for the defender.
	// Fill the Front Row, preferably with Closed Range Units
	std::vector<Being*>::iterator itv = defenderReserve.begin();
	while (itv != defenderReserve.end()) {
		Being* b = *itv;
		if ((b->getWeapon()->getWeapontype() == Enumerators::Weapontype::blunt ||
			b->getWeapon()->getWeapontype() == Enumerators::Weapontype::pierce) &&
			defenderFirstRow.size() < frontWidth) {
			defenderFirstRow.push_back(b);
			itv = defenderReserve.erase(itv);
		}
		else {
			++itv;
		}
	}
	// If there is still space in the front row, fill it with other units
	if (defenderFirstRow.size() < frontWidth &&
		defenderReserve.size() > 0) {
		std::vector<Being*>::iterator itvi = defenderReserve.begin();
		while (itvi != defenderReserve.end()) {
			Being* b = *itvi;
			if (defenderFirstRow.size() < frontWidth) {
				defenderFirstRow.push_back(b);
				itvi = defenderReserve.erase(itvi);
			}
			else {
				++itvi;
			}
		}
	}
	// Fill the second Row, preferably with ranged or explosive weapons.
	std::vector<Being*>::iterator itvii = defenderReserve.begin();
	while (itvii != defenderReserve.end()) {
		Being* b = *itvii;
		if ((b->getWeapon()->getWeapontype() == Enumerators::Weapontype::ranged ||
			b->getWeapon()->getWeapontype() == Enumerators::Weapontype::explosive) &&
			defenderSecondRow.size() < frontWidth) {
			defenderSecondRow.push_back(b);
			itvii = defenderReserve.erase(itvii);
		}
		else {
			++itvii;
		}
	}
	// If there is still space in the second row, fill it with other units
	if (defenderSecondRow.size() < frontWidth &&
		defenderReserve.size() > 0) {
		std::vector<Being*>::iterator itviii = defenderReserve.begin();
		while (itviii != defenderReserve.end()) {
			Being* b = *itviii;
			if (defenderSecondRow.size() < frontWidth) {
				defenderSecondRow.push_back(b);
				itviii = defenderReserve.erase(itviii);
			}
			else {
				++itviii;
			}
		}
	}

	std::cout << "frontline: " << std::endl << std::endl;
	for (Being* b : attackerFirstRow)
		std::cout << "	" << b->getName() << std::endl;


	return true;
}

bool Battle::calculateRound() {
	// Calculate and distribute the Damage
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