#pragma once
class Battle
{
public:
	Battle(Leader*, Leader*, Room*);

	// Important Methods
	void fight();
	bool prepareNextRound();
	bool calculateRound();
	bool endRound();
	bool aftermath();

	// Helping Methods
	bool prepareReserves();

private:
	// Attacker Data
	Leader * attackingLeader;
	std::vector<Being*> attackerFirstRow;
	std::vector<Being*> attackerSecondRow;
	std::vector<Being*> attackerReserve;
	int attackerMorale;

	// Defender Data
	Leader* defendingLeader;
	std::vector<Being*> defenderFirstRow;
	std::vector<Being*> defenderSecondRow;
	std::vector<Being*> defenderReserve;
	int defenderMorale;

	// Theater Data
	Room* battleground;
	int currentCondition;
	int environmentalDamage;
	int frontWidth;

	// Important Data
	int moraleCounter;
	bool isOngoing;


	// Additional Data
	int bodyCount;
	int woundedCount;
	std::vector<Being*> memorial;
	std::string title;

	// Constants
	int ENV_THRESHOLD = 5;
	int EXPLOSIVE_DAMAGE = 5;
};

