// ABaDiS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	srand(time(NULL));

	Room r = Room();

	for (int i = 0; i < 5; i++) {
		SecTroop sectroop = SecTroop(r);
		sectroop.printBeingFlavor();
	}
	for (int i = 0; i < 5; i++) {
		SecOfficer sectroop = SecOfficer(r);
		sectroop.printBeingFlavor();
	}

	return 0;
}

