#pragma once
#include "stdafx.h"
#include "Squad.h"
#include "Quest.h"
#include "Client.h"
#include "Map.h"

class Leader : public Being
{
public:

	Leader(Room*, Enumerators::Faction);

	virtual bool recruit();
	virtual bool recruit(Being*);
	virtual void getNewDesire();
	virtual void enterRoom(Room*);
	virtual void takeQuest(Client*);

	void explore(int);

	// Helpers
	void toggleFighting(bool);
	bool knowsRoom(Room*);

	// Getters
	Squad* getSquad() const;
	Quest* getCurrentQuest() const;

	Map* getMap();

	std::string getSquadName() const;
	Enumerators::Faction getFaction() const;

	// Printers
	virtual void printSquad();
	void printBeingTable();

protected:
	Enumerators::Faction faction;

	Map map;

	int maxSquadSize;
	bool isFighting;

	Squad* squad;
	std::string squadName;

	Quest* currentQuest;
};