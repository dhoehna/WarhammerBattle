#ifndef DEFAULTSTATS_H
#define DEFAULTSTATS_H
#include "Stats.h"
class DefaultStats : public Stats
{
public:
	DefaultStats();
	DefaultStats(DefaultStats& rightSide);
	virtual ~DefaultStats();

	DefaultStats* DefaultStats::Create();
	DefaultStats* DefaultStats::Clone();

private:
	void Initilize();
};

#endif

