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
	TestConstructorStatsNull();

	std::cout << "Done testing the unit class" << std::endl;
}

void UnitTester::TestConstructorStatsNotNull()
{
	std::cout << "Testing the constructor with a non-null stat class.  This is for memory leak check" << std::endl;

	Stats* hi1 = new BloodLetterStats();

	Unit hello1(hi1);

	Stats* hi2 = new BloodLetterStats();

	Unit* hello2 = new Unit(hi2);

	delete hello2;

	hello2 = nullptr;
}

void UnitTester::TestOutput()
{
	std::cout << "Testing the output" << std::endl;

	Stats* hi = new BloodLetterStats();
	Unit hello1(hi);

	std::cout << "Expect 5 5 4 3 1 4 4 7 5" << std::endl;
	std::cout << "Result " << hello1 << std::endl;
}

void UnitTester::TestConstructorStatsNull()
{
	std::cout << "Testing the constructor with NULL and nullptr.  This  is for memory leaks." << std::endl;

	Stats* hi1 = NULL;
	Stats* hi2 = nullptr;

	Unit hello1(hi1);
	Unit* hello2 = new Unit(hi2);

	std::cout << "Expect 1 1 1 1 1 1 1 1 1" << std::endl;
	std::cout << "Result " << hello1 << std::endl;

	delete hi1;
	delete hi2;
	delete hello2;

	hi1 = nullptr;
	hi2 = nullptr;
	hello2 = nullptr;


}