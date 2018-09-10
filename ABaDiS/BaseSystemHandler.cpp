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