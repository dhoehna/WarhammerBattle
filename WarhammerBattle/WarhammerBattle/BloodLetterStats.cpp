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