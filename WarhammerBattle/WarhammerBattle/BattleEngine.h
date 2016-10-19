#ifndef BATTLE_ENGINE_H
#define BATTLE_ENGINE_H
#include "BloodLetter.h"
#include <time.h> 
#include <iostream>
#include <random>
class BattleEngine
{
public:
	BattleEngine();
	BattleEngine(BattleEngine& rightSide);
	~BattleEngine();

	int Battle(BloodLetter attacker, BloodLetter defender);

	enum { TIE, ATTACKER, DEFENDER };

private:

	int toHit[10][10] = 
	{
		{4, 4, 5, 5, 5, 5, 5, 5, 5, 5},
		{3, 4, 4, 4, 5, 5, 5, 5, 5, 5},
		{3, 3, 4, 4, 4, 4, 5, 5, 5, 5},
		{3, 3, 3, 4, 4, 4, 4, 4, 5, 5},
		{3, 3, 3, 3, 4, 4, 4, 4, 4, 4},
		{3, 3, 3, 3, 3, 4, 4, 4, 4, 4},
		{3, 3, 3, 3, 3, 3, 4, 4, 4, 4},
		{3, 3, 3, 3, 3, 3, 3, 4, 4, 4},
		{3, 3, 3, 3, 3, 3, 3, 3, 3, 4},
		{3, 3, 3, 3, 3, 3, 3, 3, 3, 4}
	};

	int toWound[10][10] = 
	{
		{4, 5, 6, 6, 7, 7, 7, 7, 7, 7},
		{3, 4, 5, 6, 6, 7, 7, 7, 7, 7},
		{2, 3, 4, 5, 6, 6, 7, 7, 7, 7},
		{2, 2, 3, 4, 5, 6, 6, 7, 7, 7},
		{2, 2, 2, 3, 4, 5, 6, 6, 7, 7},
		{2, 2, 2, 2, 3, 4, 5, 6, 6, 7},
		{2, 2, 2, 2, 2, 3, 4, 5, 6, 6},
		{2, 2, 2, 2, 2, 2, 3, 4, 5, 6},
		{2, 2, 2, 2, 2, 2, 2, 3, 4, 5},
		{2, 2, 2, 2, 2, 2, 2, 2, 3, 4}
	};

	enum { HIT, MISS };
	enum { WOUND, NOT_WOUND };
	enum { SAVE, NOT_SAVE };

	std::mt19937* numberGenerator;
	std::uniform_int_distribution<int>* numberDistributor;

	void Initilize();

	bool didAHitOccur(int attackersWeaponSkill, int defendersWeaponSkill);
	bool didWoundOccur(int attackersStrength, int defendersToughness);
	bool didSaveOccur(int defendersSave);
};

#endif