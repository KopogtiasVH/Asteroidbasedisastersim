#pragma once
#include "MobGoon.h"
#include "SecTroop.h"
class Room
{
public:

	// Constructors
	Room();
	Room(int);

	// Helpers
	bool connectTo(Room*);
	bool enterRoom(int);
	bool isConnectedTo(Room*);
	bool enteringBeings(int);
	void addWaitingGoons(MobGoon*);
	void addWaitingTroops(SecTroop*);
	void setPresence(Enumerators::Faction);

	// Getters
	int getCapacity() const;
	int getCurrentCapacity() const;
	int getPriority() const;
	int getCurrentCondition() const;
	int getMaxCondition() const;

	bool isIntact() const;
	bool isEmpty() const;
	bool isPresent(Enumerators::Faction) const;
	bool hasWaitingGoons() const;
	bool hasWaitingTroops() const;

	std::string getName() const;
	std::vector<Room*> getConnections() const;
	Enumerators::KindOfRoom getKor() const;

	// Printers
	virtual void printRoom();

protected:

	// Statistics
	int maxCapacity;
	int currentCapacity;
	int population;
	int priority;
	int maxCondition;
	int currentCondition;

	bool intact;
	bool inSystem;
	Enumerators::Faction presence;

	std::vector<Room*> connectedTo;
	std::vector<MobGoon*> waitingGoons;
	std::vector<SecTroop*> waitingTroops;

	std::string name;

	Enumerators::KindOfRoom kor;
};

