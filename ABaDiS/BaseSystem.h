#pragma once
class BaseSystem
{
public:
	BaseSystem();
	
	void step();

	bool allowRecruitment();
	
private:
	std::vector<Room> rooms;
	std::vector<MobLeader> leaders;
	std::vector<SecOfficer> officers;

	float tension;
};

