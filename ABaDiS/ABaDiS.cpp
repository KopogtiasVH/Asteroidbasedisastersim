// ABaDiS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	srand(time(NULL));

	Room r = Room();
	r.printRoom();

	SecOfficer so = SecOfficer(r);
	so.recruit();
	so.recruit();
	so.recruit();

	so.printBeing();
	so.printSubordinates();

	return 0;
}

