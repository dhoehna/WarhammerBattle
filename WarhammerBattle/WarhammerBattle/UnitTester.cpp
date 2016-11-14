#include "UnitTester.h"



UnitTester::UnitTester()
{
	std::cout << "Testing the unit class" << std::endl;
	stats = new BloodLetterStats();
	unit = new Unit(stats);
}


UnitTester::~UnitTester()
{
	delete unit;

	unit = nullptr;
}


void UnitTester::RunAllTests()
{
	TestOutput();
	std::cout << std::endl;

	std::cout << "Done testing the unit class" << std::endl;
}

void UnitTester::TestOutput()
{
	std::cout << "Testing the output" << std::endl;

	std::cout << "Expect 5 5 4 3 1 4 4 7 5" << std::endl;
	std::cout << "Result " << (*unit) << std::endl;
}