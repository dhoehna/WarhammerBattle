#ifndef KAIROSFATEWEAVERSTATS_H
#define KAIROSFATEWEAVERSTATS_H
#include "Stats.h"
class KairosFateweaverStats :
	public Stats
{
public:
	KairosFateweaverStats();
	KairosFateweaverStats(KairosFateweaverStats& rightSide);
	virtual ~KairosFateweaverStats();

	KairosFateweaverStats* KairosFateweaverStats::Create();
	KairosFateweaverStats* KairosFateweaverStats::Clone();

private:
	void Initilize();
};

#endif

