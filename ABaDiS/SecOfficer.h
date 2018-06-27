#pragma once
#include "Being.h"
class SecOfficer : public Being
{
public:
	SecOfficer(Room);

private:
	std::vector<SecTroop> subordinates;
};

