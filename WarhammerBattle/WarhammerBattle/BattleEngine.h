/*-----------------------------------------------------------------------------
	WHAT IS THIS?
	This is a battle engine and is used for making two units fight to the death.

	HOW DO I USE IT?
	Make two units and call battle.

	CAN I BATTLE MORE THAN ONCE?
	Yes you can.  BattleEngine has no state so you can call battle as many times as you want.
*/

#ifndef BATTLE_ENGINE_H
#define BATTLE_ENGINE_H
#include "BloodLetter.h"
#include <time.h> 
#include <random>
#include "Unit.h"
class BattleEngine
{
public:

	/*----------------------------------------------------------------------------
	 @name default ructor
	 @description makes a new BattleEngine
	*/
	BattleEngine();

	/*----------------------------------------------------------------------------
	 @name Copy ructor
	 @description make a copy of the passed in BattleEngine
	 @param rightSide the BattleEngine to copy
	*/
	BattleEngine(BattleEngine& rightSide);

	/*----------------------------------------------------------------------------
	 @name destructor
	 @description destroys the battle engine
	*/
	~BattleEngine();

	/*----------------------------------------------------------------------------
	 @name Battle
	 @Description puts the two units to the battle to the death!
	 @param attacker the attacker
	 @param defender the defender
	 @return an int representation of who won.
	*/
	int Battle( Unit* attacker,  Unit* defender);

	enum { TIE, ATTACKER, DEFENDER }; //represents who won in the battle.

private:

	//Table to see if the attacker wounds the defender
	//Use it like this [attackersStrength][defendersToughness]
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

	//Represents the ToHit table.  Use it like this
	//[AttackersWeaponSkill][defendersWeaponSkill]
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

	std::mt19937* numberGenerator; //gets the dice roll


	std::uniform_int_distribution<int>* numberDistributor; //puts the roll into a nice distribution

	/*----------------------------------------------------------------------------
	 @name Initilize
	 @description sets up the battle engine
	*/
	void Initilize();

	/*----------------------------------------------------------------------------
	 @name GetWoundsInflicted
	 @description Calculates the number of unsaved wounds that the attacker dealt to the defender.
	 @param attackersWeaponSkill the weapon skill of the attacker.
	 @param defendersWeaponSkill the weapon skill of the defender
	 @param attackersStrength the strength of the attacker
	 @param defendersToughness the toughness of the defender
	 @param attackerAttacks the number of attacks the attacker has
	 @param defendersSave the save of the defender.
	*/
	int GetWoundsInflicted(int attackersWeaponSkill, int defendersWeaponSkill, int attackersStrength, int defendersToughness,int attackerAttacks, int defendersSave);

};

#endif