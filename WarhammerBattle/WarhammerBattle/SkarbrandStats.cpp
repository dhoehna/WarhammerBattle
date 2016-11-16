#include "SkarbrandStats.h"

SkarbrandStats::BloodLetterStats()
{
	Initilize();
}

SkarbrandStats::BloodLetterStats(SkarbrandStats & rightSide)
{
	Initilize();
}


BloodLetterStats::~BloodLetterStats()
{
}

SkarbrandStats* SkarbrandStats::Create()
{
	return new SkarbrandStats();
}

SkarbrandStats* SkarbrandStats::Clone()
{
	return new SkarbrandStats(*this);
}

void SkarbrandStats::Initilize()
{
	weaponSkill = 5;
	ballisticSkill = 5;
	strength = 4;
	toughness = 3;
	wounds = 1;
	initiative = 4;
	attacks = 4;
	leaderShip = 7;
	save = 5;
}