#include "DefaultStats.h"



DefaultStats::DefaultStats()
{
	Initilize();
}

DefaultStats::DefaultStats(DefaultStats & rightSide)
{
	Initilize();
}


DefaultStats::~DefaultStats()
{
}

DefaultStats* DefaultStats::Create()
{
	return new DefaultStats();
}

DefaultStats* DefaultStats::Clone()
{
	return new DefaultStats(*this);
}

void DefaultStats::Initilize()
{
	weaponSkill = 1;
	ballisticSkill = 1;
	strength = 1;
	toughness = 1;
	wounds = 1;
	initiative = 1;
	attacks = 1;
	leaderShip = 1;
	save = 6;
}