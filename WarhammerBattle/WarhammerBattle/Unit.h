#ifndef UNIT_H
#define UNIT_H
#include "Stats.h"
#include "DefaultStats.h"
#include <iostream>
class Unit
{
public:

	/*----------------------------------------------------------------------------
	 @name output operator
	 @description prints this unit to the screen
	 @param os the output stream to print to 
	 @rightSide the unit to print to the output stream
	 @return the reference to the output stream.
	*/
	friend std::ostream& operator<<(std::ostream& os, const Unit& rightSide);

	 /*---------------------------------------------------------------------------
	  @name constructor
	  @description makes a ne unit object with the passed in stats.
	  @param stats the stats for the unit
	 */
	Unit(Stats* stats);

	/*----------------------------------------------------------------------------
	 @name copy constructor
	 @description makes a new Unit based on the passed in unit
	 @param rightSide the unit to make a copy of.
	*/
	Unit(Unit&  rightSide);

	/*----------------------------------------------------------------------------
	 @name destructor
	 @description destroys this unit
	*/
	~Unit();

	/*----------------------------------------------------------------------------
	 @name AllocateWounds
	 @description allocates the number of unsaved wounds.
	 @param numberOfUnsavedWounds the number of wounds to allocate
	 @return the number of wounds that still need to be allocated
	*/
	int AllocateWounds(int numberOfUnSavedWounds);

	/*----------------------------------------------------------------------------
	 @name IsDead
	 @description checks to see if the unit is dead or not
	 @return true if the unit is dead, otherwise false.
	*/
	bool IsDead();
	
	/*----------------------------------------------------------------------------
	 @name Reset
	 @description resets this  unit to being alive.
	*/
	void Reset();

	int WeaponSkill();
	int BallisticSkill();
	int Strength();
	int Toughness();
	int Attacks();
	int Wounds();
	int Save();
	int LeaderShip();
	int Initiative();

private:
	int numberOfUnsavedWounds;
	bool isDead;
	Stats* stats;
};

#endif