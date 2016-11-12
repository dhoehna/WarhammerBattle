#include "BloodLetterStatsTester.h"



BloodLetterStatsTester::BloodLetterStatsTester()
{
	std::cout << "Testing Bloodletter Stats" << std::endl;
	Initilize();
}


BloodLetterStatsTester::~BloodLetterStatsTester()
{
	CleanUp();
}

void BloodLetterStatsTester::RunAllTests()
{
	TestCreateMethod();
	TestCloneMethod();
	TestOutput();
	TestEquality();
	std::cout << "Done testing Bloodletter stats" << std::endl;
}

void BloodLetterStatsTester::Initilize()
{
	testingStats = new BloodLetterStats();
	test2 = new BloodLetterStats();
	defaultStats = new DefaultStats();
}

void BloodLetterStatsTester::CleanUp()
{
	delete testingStats;
	delete test2;
	delete defaultStats;

	testingStats = nullptr;
	test2 = nullptr;
	defaultStats = nullptr;
}

void BloodLetterStatsTester::TestCreateMethod()
{
	std::cout << "Testing the Create method.  This is to just test for memory leaks" << std::endl;

	Stats* hi2 = testingStats->Create();

	delete hi2;

	hi2 = nullptr;
}

void BloodLetterStatsTester::TestCloneMethod()
{
	std::cout << "Testing the Clone method.  This is just used for memory leaks" << std::endl;

	Stats* hi2 = testingStats->Clone();

	delete hi2;

	hi2 = nullptr;
}

void BloodLetterStatsTester::TestOutput()
{
	std::cout << "Testing output" << std::endl;

	std::cout << "Expect 5 5 4 3 1 4 4 7 5" << std::endl;
	std::cout << "result " << (*testingStats) << std::endl;
}

void BloodLetterStatsTester::TestEquality()
{
	std::cout << "Testing to make sure equality works" << std::endl;

	std::cout << "Expect true" << std::endl;
	std::cout << "Result " << ((*testingStats) == (*testingStats)) << std::endl;

	std::cout << "Expect false" << std::endl;
	std::cout << "Result " << ((*testingStats) == (*defaultStats)) << std::endl;
}