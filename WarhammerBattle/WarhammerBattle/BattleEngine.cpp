#include "BattleEngine.h"



BattleEngine::BattleEngine()
{
	Initilize();
}

BattleEngine::BattleEngine(BattleEngine& rightSide)
{
	Initilize();
}

BattleEngine::~BattleEngine()
{
	delete numberGenerator;
	delete numberDistributor;

	numberGenerator = nullptr;
	numberDistributor = nullptr;
	
}

int BattleEngine::Battle(BloodLetter attacker, BloodLetter defender)
{

	bool isAttackerDead = false;
	bool isDefenderDead = false;
	int round = 1;

	int attackersWeaponSkill = attacker.getWeaponSkill();
	int defendersWeaponSkill = defender.getWeaponSkill();

	int attackersStrength = attacker.getStrength();
	int defendersStrength = defender.getStrength();

	int attackersToughness = attacker.getToughness();
	int defendersToughness = defender.getToughness();

	int attackersSave = attacker.getSave();
	int defendersSave = defender.getSave();

	while (!isAttackerDead && !isDefenderDead)
	{		
		int didAttackerHitDefender = numberDistributor->operator()(*numberGenerator);

		isDefenderDead = false;
		if (didAttackerHitDefender >= toHit[attackersWeaponSkill - 1][defendersWeaponSkill - 1])
		{
			int didAttackWound = numberDistributor->operator()(*numberGenerator);
			if (didAttackWound >= toWound[attackersStrength - 1][defendersToughness - 1])
			{
				int didDefenderSave = numberDistributor->operator()(*numberGenerator);
				if (didDefenderSave >= defender.getSave())
				{
					defender.AllocateWounds(1);

					isDefenderDead = defender.getIsDead();
				}
			}
		}

		isAttackerDead = false;
		int didDefenderHitAttacker = numberDistributor->operator()(*numberGenerator);
		if (didDefenderHitAttacker >= toHit[defendersWeaponSkill - 1][attackersWeaponSkill - 1])
		{
			int didDefenderWound = numberDistributor->operator()(*numberGenerator);
			if (didDefenderWound >= toWound[defendersStrength - 1][attackersToughness - 1])
			{
				int didAttackerSave = numberDistributor->operator()(*numberGenerator);
				if (didAttackerSave >= attacker.getSave())
				{
					attacker.AllocateWounds(1);

					isAttackerDead = attacker.getIsDead();
				}
			}
		}
		round++;
	}

	//Once we get here one unit, or both are dead
	if (isAttackerDead && isDefenderDead)
	{
		return TIE;
	}
	else if (isAttackerDead)
	{
		return DEFENDER;
	}
	else
	{
		return ATTACKER;
	}
}

void BattleEngine::Initilize()
{
	numberGenerator = new std::mt19937(time(0));
	numberDistributor = new std::uniform_int_distribution<int>(1, 6);
}

bool BattleEngine::didAHitOccur(int attackersWeaponSkill, int defendersWeaponSkill)
{
	return false;
}

bool BattleEngine::didWoundOccur(int attackersStrength, int defendersToughness)
{
	return false;
}

bool BattleEngine::didSaveOccur(int defendersSave)
{
	return false;
}