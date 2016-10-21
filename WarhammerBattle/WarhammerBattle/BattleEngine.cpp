/*

	WHAT IS THIS?	
	This is a battle engine.  This will take two troops and put them to battle until one, or both of them dies.
	When someone dies an int will be returned that says who died.
	THere is no state here.  SO call Battle as many times as you want.

*/

#include "BattleEngine.h"



/*-----------------------------------------------------------------------------
 @name default ructor
 @description sets up the Battle Engine.
*/
BattleEngine::BattleEngine()
{
	Initilize();
}

/*-----------------------------------------------------------------------------
 @name copy ructor
 @description sets up a BattleEngine based on an existing one.
 */
BattleEngine::BattleEngine(BattleEngine& rightSide)
{
	Initilize();
}

/*-----------------------------------------------------------------------------
 @name destructor
 @description destorys the game engine.  Deletes the number generator and number distributor
*/
BattleEngine::~BattleEngine()
{
	delete numberGenerator;
	delete numberDistributor;

	numberGenerator = nullptr;
	numberDistributor = nullptr;

}

/*-----------------------------------------------------------------------------
 @name Battle
 @description runs battle by battle until one team has won or both teams are dead
 @param attacker The attacker
 @param defender The defender
 @return an int representing who won. Either TIE, ATTACKER, or DEFENDER
*/
int BattleEngine::Battle( Unit* attacker, Unit* defender)
{

	bool isAttackerDead = false;
	bool isDefenderDead = false;
	int round = 1;

	while (!isAttackerDead && !isDefenderDead)
	{
		int attackersInitiave = attacker->stats->Initiative();
		int defendersInitiave = defender->stats->Initiative();

		/* Ugh.  This whole thing can be moved to a different method.  I just don't know what to call it */
		if (attackersInitiave == defendersInitiave) //both attack at the same time
		{
			int numberOfWoundsAgainstDefender = GetWoundsInflicted(attacker->stats->WeaponSkill(), defender->stats->WeaponSkill(), attacker->stats->Strength(), defender->stats->Toughness(), attacker->stats->Attacks(), defender->stats->Save());
			int numberOfWoundsAgainstAttacker = GetWoundsInflicted(defender->stats->WeaponSkill(), attacker->stats->WeaponSkill(), defender->stats->Strength(), attacker->stats->Toughness(), defender->stats->Attacks(), attacker->stats->Save());

			defender->AllocateWounds(numberOfWoundsAgainstDefender);
			attacker->AllocateWounds(numberOfWoundsAgainstAttacker);

			isAttackerDead = attacker->IsDead();
			isDefenderDead = defender->IsDead();
		}
		else if (attackersInitiave > defendersInitiave) //attacker attackes first
		{
			int numberOfWoundsAgainstDefender = GetWoundsInflicted(attacker->stats->WeaponSkill(), defender->stats->WeaponSkill(), attacker->stats->Strength(), defender->stats->Toughness(), attacker->stats->Attacks(), defender->stats->Save());
			defender->AllocateWounds(numberOfWoundsAgainstDefender);

			isDefenderDead = defender->IsDead();

			if (!isDefenderDead)
			{
				int numberOfWoundsAgainstAttacker = GetWoundsInflicted(defender->stats->WeaponSkill(), attacker->stats->WeaponSkill(), defender->stats->Strength(), attacker->stats->Toughness(), defender->stats->Attacks(), attacker->stats->Save());
				attacker->AllocateWounds(numberOfWoundsAgainstAttacker);
				
				isAttackerDead = attacker->IsDead();
			}

		}
		else //defender attackes first
		{

			int numberOfWoundsAgainstAttacker = GetWoundsInflicted(defender->stats->WeaponSkill(), attacker->stats->WeaponSkill(), defender->stats->Strength(), attacker->stats->Toughness(), defender->stats->Attacks(), attacker->stats->Save());
			attacker->AllocateWounds(numberOfWoundsAgainstAttacker);

			isAttackerDead = attacker->IsDead();


			if (!isAttackerDead)
			{
				int numberOfWoundsAgainstDefender = GetWoundsInflicted(attacker->stats->WeaponSkill(), defender->stats->WeaponSkill(), attacker->stats->Strength(), defender->stats->Toughness(), attacker->stats->Attacks(), defender->stats->Save());
				defender->AllocateWounds(numberOfWoundsAgainstDefender);

				isDefenderDead = defender->IsDead();
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



/*-----------------------------------------------------------------------------
 @name GetWoundsInflicted
 @description Runs through the toHit, toWound, and toSave rolls to get the number of wounds to allocate
 @param attackersWeaponSkill the weaponskill of the attacker. Used to get the number of hits
 @param defendersWeaponSkill the weapon skill of the defender, used to get the number of hits
 @param attackersStrength the strength of the attacker.  THis is used to get the number of wounds
 @param defendersToughness the toughness of the defender.  This is used to get the number of wounds
 @param attackerAttacks the number of times the attacker attacks.  Used to get the number of hits.
 @param defenderSave the save value of the defender.  THis is used to see how manyu wounds the defender ignores.
 @return int representing the number of unsaved wounds the defender needs to take
*/
int BattleEngine::GetWoundsInflicted(int attackersWeaponSKill, int defendersWeaponSkill, int attackersStrength, int defendersToughness, int attackerAttacks, int defendersSave)
{
	int numberOfHits = 0;

	for (int attacks = 0; attacks < attackerAttacks; attacks++)
	{
		int didAttackerHitDefender = numberDistributor->operator()(*numberGenerator);
		if (didAttackerHitDefender >= toHit[attackersWeaponSKill - 1][defendersWeaponSkill - 1])
		{
			numberOfHits++;
		}
	}

	int numberOfWounds = 0;

	for (int attack = 0; attack < numberOfHits; attack++)
	{
		int didAttackWound = numberDistributor->operator()(*numberGenerator);
		if (didAttackWound >= toWound[attackersStrength - 1][defendersToughness - 1])
		{
			numberOfWounds++;
		}
	}

	int numberOfUnsavedWounds = numberOfWounds;

	for (int wound = 0; wound < numberOfWounds; wound++)
	{
		int didDefenderSave = numberDistributor->operator()(*numberGenerator);
		if (didDefenderSave >= defendersSave)
		{
			numberOfUnsavedWounds--;
		}
	}

	return numberOfUnsavedWounds;
}




/*-----------------------------------------------------------------------------
 @name Initilize
 @description Sets up the BattleEngine
*/
void BattleEngine::Initilize()
{
	numberGenerator = new std::mt19937(time(0));
	numberDistributor = new std::uniform_int_distribution<int>(1, 6);
}
