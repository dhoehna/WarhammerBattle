#include "UnitTester.h"



UnitTester::UnitTester()
{
	std::cout << "Testing the unit class" << std::endl;
}


UnitTester::~UnitTester()
{
}

void UnitTester::RunAllTests()
{
	TestConstructorStatsNotNull();
	TestOutput();
	std::cout << std::endl;

	std::cout << "Done testing the unit class" << std::endl;
}

void UnitTester::TestConstructorStatsNotNull()
{
	std::cout << "Testing the constructor with a non-null stat class.  This is for memory leak check" << std::endl;

	BloodLetterStats* hi1 = new BloodLetterStats();

	Unit hello1(hi1);

	BloodLetterStats* hi2 = new BloodLetterStats();

	Unit* hello2 = new Unit(hi2);

	delete hello2;

	hello2 = nullptr;
}

void UnitTester::TestOutput()
{
	std::cout << "Testing the output" << std::endl;

	BloodLetterStats* hi = new BloodLetterStats();
	Unit hello1(hi);

	std::cout << "Expect 5 5 4 3 1 4 4 7 5" << std::endl;
	std::cout << "Result " << hello1 << std::endl;
}