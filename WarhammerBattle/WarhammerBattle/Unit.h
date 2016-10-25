#ifndef UNIT_H
#define UNIT_H
#include "Stats.h"
#include "DefaultStats.h"
class Unit
{
public:
	 Stats * stats; //Don't edit this yet.  Please don't edit it.  Just wait until the class is more defined.
	 //THen I'll add consts' everywhere.

	Unit(Stats* stats);
	Unit(Unit&  rightSide);
	~Unit();

	void AllocateWounds(int numberOfUnSavedWounds);
	bool IsDead();

private:
	int numberOfUnsavedWounds;
	bool isDead;
};

#endif