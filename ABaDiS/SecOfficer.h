#pragma once
#include "Leader.h"
#include "Enumerators.h"

class SecOfficer : public Leader
{
public:

	SecOfficer(Room*);

	bool recruit();
	bool recruit(SecTroop*);
	void enterRoom(Room*);

	Enumerators::OfficerClass oClass;

private:

	int maxSquadSize;

};

