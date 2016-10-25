#include "Stats.h"

Stats::~Stats()
{
	//nothing to do here.
}

bool Stats::operator==(ITestable& rightSide)
{
	return true;
}

 int Stats::WeaponSkill()
{
	return weaponSkill;
}


 int Stats::BallisticSkill()
{
	return ballisticSkill;
}

 int Stats::Strength()
{
	return strength;
}

 int Stats::Toughness()
{
	return toughness;
}

 int Stats::Attacks()
{
	return attacks;
}

 int Stats::Wounds()
{
	return wounds;
}


 int Stats::Save()
{
	return save;
}

 int Stats::LeaderShip()
{
	return leaderShip;
}

 int Stats::Initiative() 
{
	return initiative;
}
