#pragma once
#include "Being.h"
class MobLeader :
	public Being
{
public:

	enum LeaderClass {
		crimeBoss,
		campaigner,
		exmilitary,
		leader
	};

	MobLeader(Room);
	bool recruit();
	void printMob();
	LeaderClass lClass;

	std::vector<MobGoon> getMob() const;

private:

	int maxMobSize;
	std::vector<MobGoon> mob;
	std::string mobName;

};

