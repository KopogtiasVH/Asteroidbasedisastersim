#include "stdafx.h"
#include "Squad.h"
#include <iterator>

Squad::Squad() {

}

Squad::Squad(int ms, int iic, Enumerators::Faction f, std::string ln)
{
	switch (f) {
	case Enumerators::Faction::ANARC:
		squadName = NameGenerator::militiaName(ln);
		break;
	case Enumerators::Faction::SEC:
		squadName = ln + "'s Squad";
		break;
	default:
		std::cerr << "Wrong faction identifier" << std::endl;
	}

	members = std::vector<Being*>();
	maxSize = ms;
	size = 0;

	inventory = new Inventory(iic);
}

std::vector<Being*> Squad::getMembers() const
{
	return members;
}

int Squad::getSize() const
{
	return size;
}

int Squad::getMaxSize() const
{
	return maxSize;
}

Being* Squad::getMember(int i) const{
		return members[i];
}

Inventory* Squad::getInventory() const
{
	return inventory;
}

bool Squad::recruit(Being* toRecruit)
{
	if (size < maxSize) {
		members.push_back(toRecruit);
		size++;
		toRecruit->setSquadAffiliation(true);
		return true;
	}
	else {
		std::cerr << "Squad already full" << std::endl;
		return false;
	}
}

void Squad::kick(Being* toKick) {
	toKick->setSquadAffiliation(false);
	std::vector<Being*>::iterator it = members.begin();
	while (it != members.end()) {
		Being* b = *it;
		if (b == toKick) {
			it = members.erase(it);
			break;
		}
		else {
			++it;
		}
	}
}

void Squad::printSquad() {
		std::cout << "Squad: " << squadName << ": (" << members.size() << "/" << maxSize << ")" << std::endl;
		for (int i = 0; i < members.size(); i++) {
			std::cout << "	- " << members[i] -> getName() << std::endl;
		}
		std::cout << std::endl;
}

std::string Squad::getSquadName() const{
	return squadName;
}

void Squad::setMaxSize(int i) {
	maxSize = i;
}

void Squad::cleanDead() {
	std::vector<Being*>::iterator it = members.begin();
	while (it != members.end()) {
		Being* b = *it;
		if (b->getStatus() == Enumerators::BodyStatus::dead) {
			it = members.erase(it);
			delete b;
		}
		else {
			++it;
		}
	}
}

void Squad::updateInventory() {
	int newInventorySize = 0;
	for (int i = 0; i < members.size(); i++) {
		newInventorySize += members[i]->getStrength();
	}
}