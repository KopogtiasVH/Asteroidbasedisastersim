// ABaDiS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	srand(time(NULL));
	
	BaseSystem s = BaseSystem();
	s.createBase(100);
	s.printRooms();
	std::cout << s.getRooms().size() << std::endl;

	return 0;
}

