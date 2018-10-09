#pragma once

class Squad
{
public:
	Squad(int ms, int iic, Enumerators::Faction, std::string);
	Squad();

	std::vector<Being*> getMembers() const;
	int getSize() const;
	int getMaxSize() const;
	Being* getMember(int) const;
	Inventory* getInventory() const;

	bool recruit(Being*);
	void kick(Being*);

	void printSquad();
	void setMaxSize(int);
	void cleanDead();
	void updateInventory();

	std::string getSquadName() const;

private:
	int size;
	int maxSize;
	std::vector<Being*> members;
	std::string squadName;
	Inventory* inventory;
};

