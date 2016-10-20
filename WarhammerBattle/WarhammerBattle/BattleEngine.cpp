/*

	WHAT IS THIS?	
	This is a battle engine.  This will take two troops and put them to battle until one, or both of them dies.
	When someone dies an int will be returned that says who died.
	THere is no state here.  SO call Battle as many times as you want.

*/

#include "BattleEngine.h"



/*-----------------------------------------------------------------------------
 @name default constructor
 @description sets up the Battle Engine.
*/
BattleEngine::BattleEngine()
{
	Initilize();
}

/*-----------------------------------------------------------------------------
 @name copy constructor
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
int BattleEngine::Battle(BloodLetter attacker, BloodLetter defender)
{

	bool isAttackerDead = false;
	bool isDefenderDead = false;
	int round = 1;

	while (!isAttackerDead && !isDefenderDead)
	{
		int attackersInitiave = attacker.getInitiative();
		int defendersInitiave = defender.getInitiative();

		/* Ugh.  This whole thing can be moved to a different method.  I just don't know what to call it */
		if (attackersInitiave == defendersInitiave) //both attack at the same time
		{
			int numberOfWoundsAgainstDefender = GetWoundsInflicted(attacker.getWeaponSkill(), defender.getWeaponSkill(), attacker.getStrength(), defender.getToughness(), defender.getSave());
			int numberOfWoundsAgainstAttacker = GetWoundsInflicted(defender.getWeaponSkill(), attacker.getWeaponSkill(), defender.getStrength(), attacker.getToughness(), attacker.getSave());

			defender.AllocateWounds(numberOfWoundsAgainstDefender);
			attacker.AllocateWounds(numberOfWoundsAgainstAttacker);

			isAttackerDead = attacker.getIsDead();
			isDefenderDead = defender.getIsDead();
		}
		else if (attackersInitiave > defendersInitiave) //attacker attackes first
		{
			int numberOfWoundsAgainstDefender = GetWoundsInflicted(attacker.getWeaponSkill(), defender.getWeaponSkill(), attacker.getStrength(), defender.getToughness(), defender.getSave());
			defender.AllocateWounds(numberOfWoundsAgainstDefender);

			isDefenderDead = defender.getIsDead();

			if (!isDefenderDead)
			{
				int numberOfWoundsAgainstAttacker = GetWoundsInflicted(defender.getWeaponSkill(), attacker.getWeaponSkill(), defender.getStrength(), attacker.getToughness(), attacker.getSave());
				attacker.AllocateWounds(numberOfWoundsAgainstAttacker);
				
				isAttackerDead = attacker.getIsDead();
			}

		}
		else //defender attackes first
		{

			int numberOfWoundsAgainstAttacker = GetWoundsInflicted(defender.getWeaponSkill(), attacker.getWeaponSkill(), defender.getStrength(), attacker.getToughness(), attacker.getSave());
			attacker.AllocateWounds(numberOfWoundsAgainstAttacker);

			isAttackerDead = attacker.getIsDead();


			if (!isAttackerDead)
			{
				int numberOfWoundsAgainstDefender = GetWoundsInflicted(attacker.getWeaponSkill(), defender.getWeaponSkill(), attacker.getStrength(), defender.getToughness(), defender.getSave());
				defender.AllocateWounds(numberOfWoundsAgainstDefender);

				isDefenderDead = defender.getIsDead();
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
 @param defenderSave the save value of the defender.  THis is used to see how manyu wounds the defender ignores.
 @return int representing the number of unsaved wounds the defender needs to take
*/
int BattleEngine::GetWoundsInflicted(int attackersWeaponSKill, int defendersWeaponSkill, int attackersStrength, int defendersToughness, int defendersSave)
{
	int numberOfWoundInflicted = 0;

	int didAttackerHitDefender = numberDistributor->operator()(*numberGenerator);
	if (didAttackerHitDefender >= toHit[attackersWeaponSKill - 1][defendersWeaponSkill - 1])
	{
		int didAttackWound = numberDistributor->operator()(*numberGenerator);
		if (didAttackWound >= toWound[attackersStrength - 1][defendersToughness - 1])
		{
			int didDefenderSave = numberDistributor->operator()(*numberGenerator);
			if (didDefenderSave >= defendersSave)
			{
				numberOfWoundInflicted = 1;
			}
		}
	}

	return numberOfWoundInflicted;
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
