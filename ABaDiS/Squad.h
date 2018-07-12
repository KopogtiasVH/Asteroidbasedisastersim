#pragma once
#include "stdafx.h"

class Squad
{
public:
	Squad(int ms, std::string, std::string);
	Squad();

	std::vector<Being> getMembers() const;
	int getSize() const;
	int getMaxSize() const;

	bool recruit(Being);

	void printSquad();
	void setMaxSize(int);

private:
	int size;
	int maxSize;
	std::vector<Being> members;
	std::string squadName;
};

