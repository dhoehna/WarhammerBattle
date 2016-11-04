#ifndef UNITTESTER_H
#define UNITTESTER_H
#include <iostream>
#include "Stats.h"
#include "BloodLetterStats.h"
#include "Unit.h"
class UnitTester
{
public:
	UnitTester();
	~UnitTester();

	void RunAllTests();

private:
	void TestConstructorStatsNotNull();
	void TestConstructorStatsNull();
	void TestOutput();

};

#endif

