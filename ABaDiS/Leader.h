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

	void printSquad();

	Squad getSquad() const;

protected:
	Faction faction;

	int maxSquadSize;

	Squad squad;
	
	bool recruit(Being);
};

