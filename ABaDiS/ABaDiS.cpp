// ABaDiS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	srand(time(nullptr));
	
	BaseSystem b = BaseSystem(100);
	b.printClients();

	return 0;
}