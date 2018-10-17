#pragma once
#include "stdafx.h"
#include "Squad.h"
#include "Quest.h"
#include "Client.h"
#include "Map.h"

class Leader : public Being
{
public:

	Leader(Room*, Enumerators::Faction);

	virtual bool recruit();
	virtual bool recruit(Being*);
	virtual Enumerators::Desire getNewDesire();
	virtual void enterRoom(Room*);
	virtual bool takeQuest(Client*);
	virtual void explore();
	virtual void recieveReward(Quest::questReward);
	virtual void interpretDesire(Enumerators::Desire);

	// TODO LIST
	bool isRecruitingPossible();
	bool takeNewQuest();
	void takePersonalQuest();
	bool scavenge(Enumerators::Ressource);

	// Helpers
	void toggleFighting(bool);
	bool knowsRoom(Room*);

	// Getters
	Squad* getSquad() const;
	Quest* getCurrentQuest() const;
	Map* getMap();
	std::string getSquadName() const;
	Enumerators::Faction getFaction() const;

	// Printers
	virtual void printSquad();
	void printBeingTable();

protected:
	Enumerators::Faction faction;

	Map map;

	int maxSquadSize;
	bool isFighting;

	Squad* squad;
	std::string squadName;

	int finishedQuests;
	bool explored;
	bool recruited;
	Quest* currentQuest;
	Enumerators::Desire currentDesire;
};