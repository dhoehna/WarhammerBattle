#ifndef SKARBRANDSTATS_H
#define SKARBRANDSTATS_H
#include "Stats.h"
class SkarbrandStats : public Stats
{
public:
	SkarbrandStats();
	SkarbrandStats(SkarbrandStats& rightSide);
	virtual ~SkarbrandStats();

	SkarbrandStats* SkarbrandStats::Create();
	SkarbrandStats* SkarbrandStats::Clone();

private:
	void Initilize();
};

#endif

