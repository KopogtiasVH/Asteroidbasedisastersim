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
	void printSubordinates();
	OfficerClass oClass;

private:

	int maxSubordinates;
	std::vector<SecTroop> subordinates;

};

