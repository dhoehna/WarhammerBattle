#ifndef UNITTESTER_H
#define UNITTESTER_H
#include <iostream>
#include "Stats.h"
#include "BloodLetterStats.h"
#include "Unit.h"
#include "ITester.h"
class UnitTester : public ITester
{
public:
	UnitTester();
	~UnitTester();

	void RunAllTests();
	void Initilize();
	void CleanUp();

private:
	void TestConstructorStatsNotNull();
	void TestOutput();

};

#endif

