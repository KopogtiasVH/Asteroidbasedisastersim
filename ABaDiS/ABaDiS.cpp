// ABaDiS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	srand(time(nullptr));
	
	BaseSystem b = BaseSystem(300);
	Leader* l = b.getRandomLeader();
	l->printBeingTable();

	return 0;
}