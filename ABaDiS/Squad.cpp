#include "stdafx.h"
#include "Squad.h"

Squad::Squad() {

}

Squad::Squad(int ms, std::string f, std::string ln)
{
	if (f == "ANARC") {
		squadName = NameGenerator::militiaName(ln);
	}
	else if (f == "SEC") {
		squadName = ln + "'s Squad";
	}
	else {
		std::cerr << "wrong faction identifier" << std::endl;
	}
	members = std::vector<Being>();
	maxSize = ms;
	size = 0;
}

std::vector<Being> Squad::getMembers() const
{
	return members;
}

int Squad::getSize() const
{
	return size;
}

bool Squad::recruit(Being toRecruit)
{
	if (size < maxSize) {
		members.push_back(toRecruit);
		return true;
	}
	else {
		std::cerr << "Squad already full" << std::endl;
		return false;
	}
}

void Squad::printSquad() {
		std::cout << squadName << ": (" << size << "/" << maxSize << ")" << std::endl;
		for (int i = 0; i < size; i++) {
			std::cout << " - " << members[i].getName() << std::endl;
		}
		std::cout << std::endl;
}

void Squad::setMaxSize(int i) {
	maxSize = i;
}

