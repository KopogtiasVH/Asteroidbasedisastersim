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

	return 0;
}

