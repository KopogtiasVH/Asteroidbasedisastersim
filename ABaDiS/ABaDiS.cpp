// ABaDiS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	srand(time(NULL));
	std::vector<Room> rooms;
	for (int i = 0; i < 39; i++) {
		rooms.push_back(Room());
	}
	for (Room r : rooms)
		r.printRoom();


	return 0;
}

