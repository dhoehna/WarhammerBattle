#ifndef LORDOFCHANGESTATS_H
#define LORDOFCHANGESTATS_H
#include "Stats.h"
class LordOfChangeStats :
	public Stats
{
public:
	LordOfChangeStats();
	LordOfChangeStats(LordOfChangeStats& rightSide);
	virtual ~LordOfChangeStats();

	LordOfChangeStats* LordOfChangeStats::Create();
	LordOfChangeStats* LordOfChangeStats::Clone();

private:
	void Initilize();
};

#endif