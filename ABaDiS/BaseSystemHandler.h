#pragma once
class BaseSystemHandler
{
public:
	static void setupBaseSystemHandler(BaseSystem*);
	static Room* getRandomRoom();
	static Leader* getRandomLeader();
	static MobLeader* getRandomMobLeader();
	static SecOfficer* getRandomSecOfficer();
	static std::vector<Leader*>* getAllLeaders();
	static Leader* spawnTarget(Room*, Enumerators::Faction, int);
	static int getTension();
	static int getNoOfRooms();

private:
	static BaseSystem* baseSystem;
	static bool isGenerated;
};