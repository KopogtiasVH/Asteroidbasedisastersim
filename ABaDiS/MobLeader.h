#pragma once
#include "Leader.h"
class MobLeader : public Leader
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
	LeaderClass lClass;

private:


};

