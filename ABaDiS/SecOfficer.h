#pragma once
#include "Being.h"
class SecOfficer : public Being
{
public:
	SecOfficer(Room);
	void recruit();
	void printSubordinates();

private:
	std::vector<SecTroop> subordinates;
};

