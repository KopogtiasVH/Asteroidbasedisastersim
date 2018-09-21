#include "stdafx.h"
#include "BaseSystemHandler.h"

// A static class to handle static things for the BaseSystem
bool BaseSystemHandler::isGenerated = false;
BaseSystem* BaseSystemHandler::baseSystem;

void BaseSystemHandler::setupBaseSystemHandler(BaseSystem* bs) {
	baseSystem = bs;
	isGenerated = true;
}

Room* BaseSystemHandler::getRandomRoom() {
	if (isGenerated)
		return baseSystem->getRandomRoom();
}

Leader * BaseSystemHandler::getRandomLeader()
{
	return baseSystem->getRandomLeader();
}

MobLeader * BaseSystemHandler::getRandomMobLeader()
{
	return baseSystem->getRandomMob();
}

SecOfficer * BaseSystemHandler::getRandomSecOfficer()
{
	return baseSystem->getRandomSec();
}

std::vector<Leader*>* BaseSystemHandler::getAllLeaders() {
	return baseSystem->getLeaders();
}

Leader* BaseSystemHandler::spawnTarget(Room* location, Enumerators::Faction faction, int lackeys) {
	return baseSystem->spawnTargetLeader(location, faction, lackeys);
}
