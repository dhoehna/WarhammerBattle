#ifndef STATSFACTORYTESTER_H
#define STATSFACTORYTESTER_H
#include <iostream>
#include "StatsFactory.h"
class StatsFactoryTester
{
public:
	StatsFactoryTester();
	~StatsFactoryTester();
	void RunAllTests();

private:
	void TestConstructor();
	void TestCopyConstructor();
	void TestGetStatsPassingExistingStats();
	void TestGetStatsPassingInNonExistingStats();
};

#endif
