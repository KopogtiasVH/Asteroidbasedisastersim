// ABaDiS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	srand(time(NULL));
	
	Room a = Room();
	Room b = Room();
	Corridor c = Corridor(&a, &b);
	a.printRoom();
	b.printRoom();
	c.printRoom();

	return 0;
}

