// ABaDiS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	srand(time(NULL));
	
	for (int i=0; i<20; i++)
	std::cout << NameGenerator::companyName() << std::endl;

	return 0;
}