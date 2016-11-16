#include "LordOfChangeStats.h"



LordOfChangeStats::LordOfChangeStats()
{
	Initilize();
}

LordOfChangeStats::LordOfChangeStats(LordOfChangeStats & rightSide)
{
	Initilize();
}


LordOfChangeStats::~LordOfChangeStats()
{
}

LordOfChangeStats* LordOfChangeStats::Create()
{
	return new LordOfChangeStats();
}

LordOfChangeStats* LordOfChangeStats::Clone()
{
	return new LordOfChangeStats(*this);
}

void LordOfChangeStats::Initilize()
{
	weaponSkill = 6;
	ballisticSkill = 6;
	strength = 6;
	toughness = 6;
	wounds = 5;
	initiative = 6;
	attacks = 5;
	leaderShip = 9;
	save = 5;
}