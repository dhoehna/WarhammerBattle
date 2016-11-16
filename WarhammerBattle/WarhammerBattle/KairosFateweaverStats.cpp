#include "KairosFateweaverStats.h"




KairosFateweaverStats::KairosFateweaverStats()
{
	Initilize();
}

KairosFateweaverStats::KairosFateweaverStats(KairosFateweaverStats & rightSide)
{
	Initilize();
}


KairosFateweaverStats::~KairosFateweaverStats()
{
}

KairosFateweaverStats* KairosFateweaverStats::Create()
{
	return new KairosFateweaverStats();
}

KairosFateweaverStats* KairosFateweaverStats::Clone()
{
	return new KairosFateweaverStats(*this);
}

void KairosFateweaverStats::Initilize()
{
	weaponSkill = 1;
	ballisticSkill = 6;
	strength = 5;
	toughness = 5;
	wounds = 5;
	initiative = 2;
	attacks = 1;
	leaderShip = 9;
	save = 5;
}
