#ifndef BLOODTHIRSTERSTATS_H
#define BLOODTHIRSTERSTATS_H
#include "Stats.h"
class BloodThirsterStats :
	public Stats
{
public:
	BloodThirsterStats();
	BloodThirsterStats(BloodThirsterStats& rightSide);
	virtual ~BloodThirsterStats();

	BloodThirsterStats* BloodThirsterStats::Create();
	BloodThirsterStats* BloodThirsterStats::Clone();

private:
	void Initilize();
};

#endif

