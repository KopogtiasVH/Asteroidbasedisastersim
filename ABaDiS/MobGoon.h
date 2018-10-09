#pragma once

class MobGoon : public Being
{
public:
	MobGoon(Room*);
	MobGoon(Leader*);

	void printBeingTable();
	void printBeingFlavor();

private:
	Leader* currentLeader;
};

