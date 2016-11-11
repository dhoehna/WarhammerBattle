#ifndef SQUADTESTER_H
#define SQUADTESTER_H
#include <iostream>
#include "Unit.h"
#include "Squad.h"
#include "Stats.h"
#include "Constants.h"
#include "StatsFactory.h"
class SquadTester
{
public:
	SquadTester();
	~SquadTester();

	void RunAllTests();

private:
	void TestAddUnit();
};

#endif