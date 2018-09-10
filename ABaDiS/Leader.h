#pragma once
#include "stdafx.h"
#include "Squad.h"
#include "Quest.h"
#include "Client.h"

class Leader : public Being
{
public:

	Leader(Room*, Enumerators::Faction);

	virtual bool recruit();
	virtual bool recruit(Being*);
	virtual void getNewDesire();
	virtual void enterRoom(Room*);
	virtual void takeQuest(Client*);

	// Getters
	Squad* getSquad() const;
	Quest* getCurrentQuest() const;
	std::string getSquadName() const;

	// Printers
	virtual void printSquad();
	void printBeingTable();

protected:
	Enumerators::Faction faction;

	int maxSquadSize;
	bool isFighting;

	Squad* squad;
	std::string squadName;

	Quest* currentQuest;
};