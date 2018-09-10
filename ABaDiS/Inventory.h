#pragma once
class Inventory
{
public:
	Inventory(int);

	// Helpers
	void updateInventory();
	void updateScrap(int);
	void updateFood(int);
	void updateMeds(int);

	// Getters
	int getScrap() const;
	int getFood() const;
	int getMeds() const;

private:
	int scrap;
	int food;
	int meds;

	int maxInventorySpace;
	int currentInventorySpace;
};

