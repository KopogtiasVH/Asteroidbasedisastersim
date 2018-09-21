// ABaDiS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	srand(time(nullptr));
	
	BaseSystem b = BaseSystem(300);
	b.printRooms();
	Leader* l = b.getRandomLeader();
	l->printBeingTable();
	for (int i = 0; i < 50; i++)
		l->explore();
	l->getMap()->printMap();
	Room* testRoom = BaseSystemHandler::getRandomRoom();
	while (!l->knowsRoom(testRoom) && testRoom != l->getCurrentLocation()) {
		testRoom = BaseSystemHandler::getRandomRoom();
	}
	std::cout << "Current Location = " << l->getCurrentLocation()->getName() << std::endl;
	std::cout << "Destination = " << testRoom->getName() << std::endl;

	l->getMap()->findShortestRoute(l->getCurrentLocation(), testRoom);
	l->getMap()->printRoute();

	return 0;
}