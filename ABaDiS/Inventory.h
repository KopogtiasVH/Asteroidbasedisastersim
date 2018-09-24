#pragma once
class Inventory
{
public:
	Inventory(int);

	// Main Functions
	int returnRessource(Enumerators::Ressource);
	void updateInventoryDimension(int);
	bool addToInventory(Enumerators::Ressource, int);
	void tidyInventory(int);

	// Helpers
	void updateInventory();
	void printInventory();
	bool isFull();


	// Getters
	int getScrap() const;
	int getFood() const;
	int getMeds() const;

private:
	int scrap;
	int food;
	int meds;

	int maxInventorySpace;
	int minInventorySpace;
	int currentInventorySpace;
};

