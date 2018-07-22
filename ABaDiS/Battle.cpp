#include "stdafx.h"
#include "Battle.h"


Battle::Battle(Leader* a, Leader* b, Room* r)
{
	attackingLeader = a;
	attackerFirstRow = std::vector<Being*>();
	attackerSecondRow = std::vector<Being*>();
	attackerReserve = &attackingLeader->getSquad();
	
	attackerMorale = attackingLeader->getCurrentMorale();
	for (Being* b : attackerReserve->getMembers())
		attackerMorale += b->getCurrentMorale();

	defendingLeader = b;
	defenderFirstRow = std::vector<Being*>();
	defenderSecondRow = std::vector<Being*>();
	defenderReserve = &defendingLeader->getSquad();

	defenderMorale = defendingLeader->getCurrentMorale();
	for (Being* b : defenderReserve->getMembers())
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