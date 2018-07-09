#pragma once
#include "Leader.h"

class SecOfficer : public Leader
{
public:

	enum OfficerClass {
		riotSpecialist,
		detective,
		commander,
		officer
	};

	SecOfficer(Room);

	bool recruit();
	bool recruit(SecTroop);

	OfficerClass oClass;

private:

	int maxSquadSize;

};

