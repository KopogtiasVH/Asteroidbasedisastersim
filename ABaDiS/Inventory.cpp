#include "stdafx.h"
#include "Inventory.h"


Inventory::Inventory(int i)
{
	maxInventorySpace = i;
	currentInventorySpace = 0;
	
	scrap = 0;
	food = 0;
	meds = 0;
}

#pragma region Main
int Inventory::returnRessource(Enumerators::Ressource ressource) {
	switch (ressource) {
	case Enumerators::Ressource::food:
		return food;
		break;
	case Enumerators::Ressource::meds:
		return meds;
		break;
	case Enumerators::Ressource::scrap:
		return scrap;
		break;
	default:
		return 0;
		break;
	}
}
#pragma endregion

#pragma region HELPERS
void Inventory::updateInventory()
{
	currentInventorySpace = scrap + food + meds;
}

void Inventory::updateInventoryDimension(int newDim) {
	if (newDim < currentInventorySpace) {
		tidyInventory(currentInventorySpace - newDim);
	}
	maxInventorySpace = newDim;
}

bool Inventory::addToInventory(Enumerators::Ressource ressource, int toAdd) {
	if (currentInventorySpace + toAdd <= maxInventorySpace) {
		switch (ressource) {
		case Enumerators::Ressource::food:
			food += toAdd;
			break;
		case Enumerators::Ressource::meds:
			meds += toAdd;
			break;
		case Enumerators::Ressource::scrap:
			scrap += toAdd;
			break;
		default:
			std::cerr << "Wrong ressource" << std::endl;
			break;
		}
		return true;
	}
	else {
		return false;
	}
}
void Inventory::tidyInventory(int toRemove)
{
	for (int i = 0; i < toRemove; i++) {
		if (scrap > 0) {
			scrap--;
		}
		else if (food > 0) {
			food--;
		}
		else {
			meds--;
		}
	}
	updateInventory();
}

#pragma endregion

#pragma region GETTERS
int Inventory::getScrap() const
{
	return scrap;
}

int Inventory::getFood() const
{
	return food;
}

int Inventory::getMeds() const
{
	return meds;
}
#pragma endregion






