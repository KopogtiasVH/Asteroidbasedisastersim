#include "stdafx.h"
#include "Client.h"


Client::Client(Room* sL) : Being(sL)
{
	availableQuest = createQuest();
}

Quest * Client::getAvailableQuest() const
{
	return availableQuest;
}

Quest* Client::assignQuest(Being* reciever) {
	if (availableQuest == nullptr) {
		std::cerr << "Can't assign quest if it's not yet created" << std::endl;
		return nullptr;
	}
	else {
		availableQuest->activateQuest(reciever);
		return availableQuest;
	}
}

// Creates a new Quest to give a Leader based on it's Alignment
// TODO: Create a new Alignment solely for Clients i.e. Smugglers, Merchants, Stars, etc.
Quest* Client::createQuest() {
	switch (alignment) {
	case Enumerators::Alignment::neutral:
		switch (rand() % 4) {
		case 0:
			return new EscortingQuest(this, getValidRoom());
			break;
		case 1:
			return new GatheringQuest();
			break;
		case 2:
			return new HuntingQuest();
			break;
		case 3:
			return new SecureQuest();
			break;
		default:
			std::cerr << "Something went terribly wrong" << std::endl;
			break;
		}
		break;
	case Enumerators::Alignment::lawful:
		if (rand() % 2 == 0)
			return new EscortingQuest(this, getValidRoom());
		else
			return new GatheringQuest();
		break;
	case Enumerators::Alignment::chaotic:
		if (rand() % 2 == 0)
			return new HuntingQuest();
		else
			return new SecureQuest();
		break;
	default:
		std::cerr << "Wrong alignment assigned" << std::endl;
		break;
	}
}

Room* Client::getValidRoom() {
	Room * dest = BaseSystemHandler::getRandomRoom();
	while (dest != this->getCurrentLocation() && !dynamic_cast<Corridor*>(dest)) {
		dest = BaseSystemHandler::getRandomRoom();
	}
	return dest;
}