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
	bool recruit(MobGoon*);
	void enterRoom(Room*);
	LeaderClass lClass;

private:


};

