#include "KuGathStats.h"



KuGathStats::KuGathStats()
{
	Initilize();
}

KuGathStats::KuGathStats(KuGathStats & rightSide)
{
	Initilize();
}


KuGathStats::~KuGathStats()
{
}

KuGathStats* KuGathStats::Create()
{
	return new KuGathStats();
}

KuGathStats* KuGathStats::Clone()
{
	return new KuGathStats(*this);
}

void KuGathStats::Initilize()
{
	weaponSkill = 6;
	ballisticSkill = 3;
	strength = 6;
	toughness = 7;
	wounds = 7;
	initiative = 4;
	attacks = 6;
	leaderShip = 9;
	save = 5;
}
