// ABaDiS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	srand(time(NULL));

	Room r = Room();

	for (int i = 0; i < 1; i++) {
		SecTroop sectroop = SecTroop(r);
		MobGoon mobgoon = MobGoon(r);
		Being being = Being(r);

		being.printBeing();
		sectroop.printBeing();
		mobgoon.printBeing();
	
	}
	

	return 0;
}

