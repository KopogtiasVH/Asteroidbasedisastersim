#include "stdafx.h"
#include "Corridor.h"

Corridor::Corridor(Room* a, Room* b) : Room()
{
	kor = Enumerators::KindOfRoom::street;
	name = NameGenerator::streetName(kor);
	toFrom = std::vector<Room*>();
	toFrom.push_back(a);
	toFrom.push_back(b);

	maxCapacity = (rand() % 5 + 1) * 10;
	
	//set priority to be equal to the highest priority of rooms it connects
	int tempPrio = -INT32_MAX;
	for (Room* r : toFrom)
		if ((r)->getPriority() > tempPrio)
			tempPrio = (r)->getPriority();
	priority = tempPrio;

	maxCondition = maxCapacity * 4;
	currentCondition = maxCondition;
}

Corridor::Corridor() : Room() {};

void Corridor::printRoom() {
	std::cout << name << ":" << std::endl
		<< "	Capacity:  " << getCurrentCapacity() << " / " << getCapacity() << std::endl
		<< "	Condition: " << getCurrentCondition() << " / " << getMaxCondition() << std::endl
		<< "	Priority:  " << getPriority() << std::endl
		<< "	Connects " << (toFrom[0])->getName() << " and " << (toFrom[1])->getName() << "." << std::endl << std::endl;
}