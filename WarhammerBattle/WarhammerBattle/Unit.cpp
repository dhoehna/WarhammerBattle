/*
	WHAT IS THIS?
	This is a unit.  A unit represents one of something, be it HQ, Troop, Elite, or anything without
		armor values.

	WHAT IS INJECTED INTO THE UNIT?
	Stats.  Each unit has stats.  This are the Weapon SKills and Ballistic Skills and those numbers.
		Each unit has them. So, we pass in the stats the unit will use.

	ANY ASSUMPTIONS?
	If stats is null in the constructor, the unit will be given default stats (all 1)

	HOW DOES THIS CLASS HANDLE THE PASSED IN STUFF TO THE CONSTRUCTORS?
	This class will free up the stats that was passed in.
*/

#include "Unit.h"


/*-----------------------------------------------------------------------------
 @name Default constructor
 @description Makes a new unit with the passed in stats.
 @remark this class will delete stats when this object is dosposed of.
 @param stats the stats that the unit should use.
*/
Unit::Unit(Stats* stats)
{
	if (stats == nullptr)
	{
		this->stats = new DefaultStats();
	}
	else
	{
		this->stats = stats;
	}

	isDead = false;
	numberOfUnsavedWounds = 0;
}

/*-----------------------------------------------------------------------------
 @name copy constructor
 @description makes a new Unit based on the unit passed in.  This is a deep copy.
*/
Unit::Unit(Unit& rightSide)
{
	stats = rightSide.stats->Clone();
	isDead = rightSide.isDead;
	numberOfUnsavedWounds = rightSide.numberOfUnsavedWounds;
}

/*-----------------------------------------------------------------------------
 @name destructor
 @description destroys the injected stats.
*/
Unit::~Unit()
{
	delete stats;

	stats = nullptr;
}

std::ostream& operator<<(std::ostream& os, const Unit& rightSide)
{
	os << (*rightSide.stats);
	return os;
}

/*-----------------------------------------------------------------------------
 @name AllocateWounds
 @description gives this unit a number of wounds equal to numberOfUnSavedWounds
 @sideeffect this will turn isDead to true if the unit has reached the max number of unsaved wounds.
 @param numberOfUnsavedWounds the number of unsaved wounds to give to the unit
 @return the number of wounds that still need to be allocated
*/
int Unit::AllocateWounds(int numberOfUnSavedWounds)
{
	while (!isDead && numberOfUnSavedWounds > 0)
	{
		numberOfUnsavedWounds++;

		if (numberOfUnsavedWounds == stats->Wounds())
		{
			isDead = true;
		}

		numberOfUnSavedWounds--;
	}

	int tempNumberOfUnsavedWounds = numberOfUnsavedWounds;

	return tempNumberOfUnsavedWounds;
}

/*-----------------------------------------------------------------------------
 @name IsDead
 @description sees if the number of unsaved wounds is equal to the total number 
	of wounds.
 @return boolean
*/
bool Unit::IsDead()
{
	return isDead;
}