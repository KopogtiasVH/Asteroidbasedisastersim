// ABaDiS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	srand(time(NULL));

	Room r = Room();

	for (int i = 0; i < 10; i++) {
		SecTroop sec = SecTroop(r);
		sec.printBeing();
	}
	

	return 0;
}

