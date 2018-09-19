#pragma once
#include "stdafx.h"
#include "Squad.h"
#include "Quest.h"
#include "Client.h"
<<<<<<< HEAD
//#include "Map.h"
=======
>>>>>>> parent of 4a77918... mm

class Leader : public Being
{
public:

	Leader(Room*, Enumerators::Faction);

	virtual bool recruit();
	virtual bool recruit(Being*);
	virtual void getNewDesire();
	virtual void enterRoom(Room*);
	virtual void takeQuest(Client*);

	// Helpers
	void toggleFighting(bool);

	// Getters
	Squad* getSquad() const;
	Quest* getCurrentQuest() const;
<<<<<<< HEAD
	//Map* getMap();
=======
>>>>>>> parent of 4a77918... mm
	std::string getSquadName() const;
	Enumerators::Faction getFaction() const;

	// Printers
	virtual void printSquad();
	void printBeingTable();

protected:
	Enumerators::Faction faction;
<<<<<<< HEAD
	//Map map;
=======
>>>>>>> parent of 4a77918... mm

	int maxSquadSize;
	bool isFighting;

	Squad* squad;
	std::string squadName;

	Quest* currentQuest;
};