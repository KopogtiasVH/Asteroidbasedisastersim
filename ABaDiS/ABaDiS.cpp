// ABaDiS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	srand(time(NULL));
	
	BaseSystem s = BaseSystem();
	s.createRoom();
	s.createRoom();
	s.connectRooms(0, 1);
	s.printRooms();
	s.createMobLeader(*s.getRandomRoom());
	for (int i = 0; i < 5; i++)
		s.recruit(0);
	s.printLeaders();

	return 0;
}

