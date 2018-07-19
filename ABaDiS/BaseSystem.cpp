#include "stdafx.h"
#include "BaseSystem.h"


BaseSystem::BaseSystem()
{
	rooms = std::vector<Room>();
	corridors = std::vector<Corridor>();
	leaders = std::vector<Leader>();

	tension = 0;
}

bool BaseSystem::connectRooms(Room a, Room b) {
	if (&a != &b) {
		if (a.connectTo(&b) && b.connectTo(&a)) {
			Corridor newCorridor = Corridor(&a, &b);
			rooms.push_back(newCorridor);

			return true;
		} else {
			std::cerr << "Something went wrong" << std::endl;
			return false;
		}
	}
	else {
		std::cerr << "You can't connect a Room to itself" << std::endl;
		return false;
	}
}

bool BaseSystem::connectRooms(int a, int b) {
	if (a <= rooms.size() &&
		b <= rooms.size() &&
		a != b) {
		connectRooms(rooms[a], rooms[b]);
	}
	else {
		std::cerr << "One of the Indices is out of bounds" << std::endl;
		return false;
	}
}

void BaseSystem::printRooms() {
	for (Room room : rooms) {
		if (typeid(room) == typeid(Corridor)) {
			Corridor *cr = dynamic_cast<Corridor*>(&room);
			cr->printRoom();
		} else 
			room.printRoom();
	}
}

bool BaseSystem::createRoom() {
	Room newRoom = Room();
	rooms.push_back(newRoom);
	return true;
}
