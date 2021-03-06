// ABaDiS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	srand(time(nullptr));
	
	BaseSystem b = BaseSystem(300);
	Leader* l = b.getRandomLeader();
	l->printBeingTable();
	for (int i = 0; i < 3000; i++)
		l->explore();
	l->printBeingTable();
	l->getMap()->findNearestRoomWithRessource(Enumerators::Ressource::food, l->getCurrentLocation());
	std::cout << l->getMap()->getSize() << std::endl;
	l->getMap()->printMap();
	l->getMap()->printRoute();

	return 0;
}