#include "stdafx.h"
#include "Corridor.h"

Corridor::Corridor(Room* a, Room* b) : Room()
{
	kor = Enumerators::KindOfRoom::street;
	name = NameGenerator::streetName(kor);
	connectedTo.push_back(a);
	connectedTo.push_back(b);

	maxCapacity = (rand() % 5 + 1) * 10;
	
	//set priority to be equal to the highest priority of rooms it connects
	int tempPrio = -INT32_MAX;
	for (Room* r : connectedTo)
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
		<< "	Priority:  " << getPriority() << std::endl;
	if (connectedTo.size() == 2)
		std::cout << "	Connects " << (connectedTo[0])->getName() << " and " << (connectedTo[1])->getName() << "." << std::endl << std::endl;
	else {
		std::cout << "	Connects " << connectedTo[0]->getName();
		std::vector<Room*>::iterator it = connectedTo.begin();
		++it;
		while (it != connectedTo.end()-1) {
			Room* r = *it;
			std::cout << ", " << r->getName();
			++it;
		}
		it = connectedTo.end()-1;
		Room* r = *it;
		std::cout << " and " << r->getName() << std::endl << std::endl;
	}
}