// ABaDiS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	srand(time(NULL));
	
	BaseSystem b = BaseSystem(100);
	b.printRooms();

	return 0;
}