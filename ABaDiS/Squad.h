#pragma once
#include "stdafx.h"

class Squad
{
public:
	Squad(int ms, Enumerators::Faction, std::string);
	Squad();

	std::vector<Being*> getMembers() const;
	int getSize() const;
	int getMaxSize() const;
	Being* getMember(int) const;

	bool recruit(Being*);

	void printSquad();
	void setMaxSize(int);

private:
	int size;
	int maxSize;
	std::vector<Being*> members;
	std::string squadName;
};

