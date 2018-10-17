#pragma once
#include "Room.h"
#include <set>

class HiPRoom :
	public Room
{
public:
	HiPRoom(int);

	// Other
	void setName();
	void printRoom();

	// Population
	void addPop(Being*);
	Being* draftPop(int);

	// Clients
	void setClient(Client*);
	Client* getClient();

	// Getters
	int getFood();
	int getScrap();
	int getWeapons();
	int getPopulation();
	int getMeds();

	bool hasRessource(Enumerators::Ressource);

	bool takeFood(int);
	bool takeScrap(int);
	bool takeWeapon(int);
	bool takePopulation(int);
	bool takeMeds(int);

	bool hasPopulation();

private:

	// Ressources
	int food;
	int scrap;
	int weapons;
	int meds;

	// Population
	int population;
	std::set<Being*> populationList;

	// Clients
	Client* client;

	// Other
};

