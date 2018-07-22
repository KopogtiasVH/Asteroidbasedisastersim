#pragma once
#include "stdafx.h"
#include "Squad.h"

class Leader : public Being
{
public:

	Leader(Room, Enumerators::Faction);

	virtual void printSquad();
	virtual bool recruit();
	virtual bool recruit(Being);

	Squad getSquad() const;

protected:
	Enumerators::Faction faction;

	int maxSquadSize;
	bool isFighting;

	Squad squad;
	
	
};