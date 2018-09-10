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

void Inventory::updateInventory()
{
}

void Inventory::updateScrap(int i)
{
	
}

void Inventory::updateFood(int i)
{
}

void Inventory::updateMeds(int i)
{
}

int Inventory::getScrap() const
{
	return 0;
}

int Inventory::getFood() const
{
	return 0;
}

int Inventory::getMeds() const
{
	return 0;
}

