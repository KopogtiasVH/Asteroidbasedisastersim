// ABaDiS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	srand(time(NULL));

	Room r = Room();
	r.printRoom();

	MobLeader so = MobLeader(r);
	so.recruit();
	so.recruit();
	so.recruit();

	so.printBeing();
	so.printMob();

	return 0;
}

