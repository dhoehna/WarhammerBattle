#include "Unit.h"



Unit::Unit(Stats* stats) : stats(stats)
{
	isDead = false;
	numberOfWounds = 0;
}

Unit::Unit( Unit&  rightSide)
{
	stats = rightSide.stats->Clone();
	isDead = rightSide.isDead;
	numberOfWounds = rightSide.numberOfWounds;
}


Unit::~Unit()
{
	delete stats;

	stats = nullptr;
}

void Unit::AllocateWounds(int numberOfUnSavedWounds)
{
	int woundCounter = 0;
	while (!isDead && woundCounter < numberOfUnSavedWounds)
	{
		numberOfWounds++;

		if (numberOfWounds == stats->Wounds())
		{
			isDead = true;
		}

		woundCounter++;
	}
}

bool Unit::IsDead()
{
	return isDead;
}