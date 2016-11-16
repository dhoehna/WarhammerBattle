#include "BloodThirsterStats.h"



BloodThirsterStats::BloodThirsterStats()
{
	Initilize();
}

BloodThirsterStats::BloodThirsterStats(BloodThirsterStats & rightSide)
{
	Initilize();
}


BloodThirsterStats::~BloodThirsterStats()
{
}

BloodThirsterStats* BloodThirsterStats::Create()
{
	return new BloodThirsterStats();
}

BloodThirsterStats* BloodThirsterStats::Clone()
{
	return new BloodThirsterStats(*this);
}

void BloodThirsterStats::Initilize()
{
	weaponSkill = 10;
	ballisticSkill = 10;
	strength = 6;
	toughness = 6;
	wounds = 5;
	initiative = 9;
	attacks = 6;
	leaderShip = 9;
	save = 5;
}