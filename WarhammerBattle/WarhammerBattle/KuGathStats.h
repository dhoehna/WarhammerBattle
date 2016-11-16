#ifndef KUGATHSTATS_H
#define KUGATHSTATS_H
#include "Stats.h"
class KuGathStats :
	public Stats
{
public:
	KuGathStats();
	KuGathStats(KuGathStats& rightSide);
	virtual ~KuGathStats();

	KuGathStats* KuGathStats::Create();
	KuGathStats* KuGathStats::Clone();

private:
	void Initilize();
};

#endif