#pragma once
#include "stdafx.h"
#include "Squad.h"
#include "Quest.h"
#include "Client.h"
<<<<<<< HEAD
<<<<<<< HEAD
//#include "Map.h"
=======
>>>>>>> parent of 4a77918... mm
=======
#include "Map.h"
>>>>>>> parent of b0911a3... mmme

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
<<<<<<< HEAD
	//Map* getMap();
=======
>>>>>>> parent of 4a77918... mm
=======
	Map* getMap();
>>>>>>> parent of b0911a3... mmme
	std::string getSquadName() const;
	Enumerators::Faction getFaction() const;

	// Printers
	virtual void printSquad();
	void printBeingTable();

protected:
	Enumerators::Faction faction;
<<<<<<< HEAD
<<<<<<< HEAD
	//Map map;
=======
>>>>>>> parent of 4a77918... mm
=======
	Map map;
>>>>>>> parent of b0911a3... mmme

	int maxSquadSize;
	bool isFighting;

	Squad* squad;
	std::string squadName;

	Quest* currentQuest;
};