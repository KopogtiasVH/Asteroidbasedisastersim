#pragma once
#include "Being.h"
class SecOfficer : public Being
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
	void printSubordinates();
	OfficerClass oClass;

private:

	int maxSquadSize;
	std::vector<SecTroop> squad;

};

