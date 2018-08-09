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

	MobLeader(Room*);
	bool recruit();
	void enterRoom(Room*);
	LeaderClass lClass;

private:


};

