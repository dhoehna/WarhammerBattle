#ifndef BLOODLETTERSTATSTESTER_H
#define BLOODLETTERSTATSTESTER_H
#include <iostream>
#include "Stats.h"
#include "BloodLetterStats.h"
class BloodLetterStatsTester
{
public:
	BloodLetterStatsTester();
	~BloodLetterStatsTester();

	void RunAllTests();

private:
	void TestConstructor();
	void TestCreateMethod();
	void TestCloneMethod();
};

#endif
