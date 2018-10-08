// ABaDiS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	srand(time(nullptr));
	
	BaseSystem b = BaseSystem(300);
	Leader* l = b.getRandomLeader();
	l->printBeingTable();
	for (int i = 0; i < 50; i++)
		l->explore();
	l->getMap()->findNearestRoomWithRessource(Enumerators::Ressource::food, l->getCurrentLocation());

	return 0;
}