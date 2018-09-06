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

Quest* Client::createQuest() {
	switch (alignment) {
	case Enumerators::Alignment::neutral:
		switch (rand() % 4) {
		case 0:
			return new EscortingQuest();
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
			return new EscortingQuest();
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