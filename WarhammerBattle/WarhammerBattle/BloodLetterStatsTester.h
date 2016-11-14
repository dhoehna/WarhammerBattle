#ifndef BLOODLETTERSTATSTESTER_H
#define BLOODLETTERSTATSTESTER_H
#include <iostream>
#include "Stats.h"
#include "BloodLetterStats.h"
#include "DefaultStats.h"
#include "ITester.h"
class BloodLetterStatsTester : public ITester
{
public:
	BloodLetterStatsTester();
	~BloodLetterStatsTester();

	void RunAllTests();

private:
	void TestCreateMethod();
	void TestCloneMethod();
	void TestOutput();
	void TestEquality();

	BloodLetterStats* testingStats;
	BloodLetterStats* test2;
	DefaultStats* defaultStats;
};

#endif
