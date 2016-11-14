#ifndef SQUADTESTER_H
#define SQUADTESTER_H
#include <iostream>
#include "Unit.h"
#include "Squad.h"
#include "Stats.h"
#include "Constants.h"
#include "StatsFactory.h"
#include "ITester.h"
class SquadTester : public ITester
{
public:
	SquadTester();
	~SquadTester();

	void RunAllTests();

private:
	void TestAddUnit();

	Squad* squad;
	Stats* stats;
	StatsFactory* factory;
	Unit* unit;
};

#endif