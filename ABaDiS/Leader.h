#pragma once
#include "stdafx.h"
#include "Squad.h"

class Leader : public Being
{
public:

	enum Faction {
		ANARC,
		SEC
	};

	Leader(Room, Leader::Faction);

	virtual void printSquad();
	virtual bool recruit();
	virtual bool recruit(Being);

	Squad getSquad() const;

protected:
	Faction faction;

	int maxSquadSize;

	Squad squad;
	
	
};