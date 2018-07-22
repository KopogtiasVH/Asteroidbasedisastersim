#pragma once
class Battle
{
public:
	Battle(Leader*, Leader*, Room*);

	bool prepareNextRound();
	bool calculateRound();
	bool endRound();
	bool aftermath();


private:
	// Attacker Data
	Leader * attackingLeader;
	std::vector<Being*> attackerFirstRow;
	std::vector<Being*> attackerSecondRow;
	Squad* attackerReserve;
	int attackerMorale;

	// Defender Data
	Leader* defendingLeader;
	std::vector<Being*> defenderFirstRow;
	std::vector<Being*> defenderSecondRow;
	Squad* defenderReserve;
	int defenderMorale;

	// Theater Data
	Room* battleground;
	int currentCondition;
	int frontWidth;

	// Important Data
	int moraleCounter;
	bool isOngoing;


	// Additional Data
	int bodyCount;
	std::vector<Being*> memorial;
	std::string title;
};

