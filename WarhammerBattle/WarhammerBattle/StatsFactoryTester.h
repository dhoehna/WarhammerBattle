#ifndef STATSFACTORYTESTER_H
#define STATSFACTORYTESTER_H
#include <iostream>
#include "StatsFactory.h"
#include "ITester.h"
class StatsFactoryTester : ITester
{
public:
	StatsFactoryTester();
	~StatsFactoryTester();
	void RunAllTests();

private:
	void TestCopyConstructor();
	void TestGetStatsPassingExistingStats();
	void TestGetStatsPassingInNonExistingStats();

	StatsFactory* factory;
};

#endif
