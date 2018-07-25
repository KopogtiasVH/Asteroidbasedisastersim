// ABaDiS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	srand(time(NULL));
	
	BaseSystem s = BaseSystem();
	s.createRoom();
	s.printRooms();
	s.createMobLeader(s.getRandomRoom());
	for (int i = 0; i < 20; i++)
		s.recruit(0);
	s.printLeaders();

	s.createSecLeader(s.getRandomRoom());
	for (int i = 0; i < 20; i++)
		s.recruit(1);
	s.createFight(s.getLeader(0), s.getLeader(1), s.getRandomRoom());
	
	while (!s.getBattles().empty())
		s.fightAllBattles();

	s.printLeaders();

	return 0;
}

