#pragma once
#include "stdafx.h"
#include "Squad.h"

class Leader : public Being
{
public:

	Leader(Room*, Enumerators::Faction);

	virtual void printSquad();
	virtual bool recruit();
	virtual bool recruit(Being*);
	virtual void getNewDesire();
	virtual void enterRoom(Room*);

	Squad* getSquad() const;

	std::string getSquadName() const;

protected:
	Enumerators::Faction faction;

	int maxSquadSize;
	bool isFighting;

	Squad* squad;
	std::string squadName;
};