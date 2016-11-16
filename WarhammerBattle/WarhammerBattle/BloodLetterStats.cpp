#include "BloodLetterStats.h"

BloodLetterStats::BloodLetterStats()
{
	Initilize();
}

BloodLetterStats::BloodLetterStats(BloodLetterStats & rightSide)
{
	Initilize();
}


BloodLetterStats::~BloodLetterStats()
{
}

BloodLetterStats* BloodLetterStats::Create()
{
	return new BloodLetterStats();
}

BloodLetterStats* BloodLetterStats::Clone() 
{
	return new BloodLetterStats(*this);
}

void BloodLetterStats::Initilize()
{
	weaponSkill = 10;
	ballisticSkill = 10;
	strength = 6;
	toughness = 6;
	wounds = 5;
	initiative = 10;
	attacks = 6;
	leaderShip = 9;
	save = 3;
}