// ABaDiS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	srand(time(NULL));
	
	Room r = Room();
	SecOfficer so = SecOfficer(r);
	so.recruit();

	r.printRoom();
	so.printBeingTable();

	return 0;
}

