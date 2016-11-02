#include "BloodLetterStatsTester.h"



BloodLetterStatsTester::BloodLetterStatsTester()
{
	std::cout << "Testing Bloodletter Stats" << std::endl;
}


BloodLetterStatsTester::~BloodLetterStatsTester()
{
	std::cout << "Done testing Bloodletter stats" << std::endl;
}

void BloodLetterStatsTester::RunAllTests()
{
	TestConstructor();
	TestCreateMethod();
	TestCloneMethod();
	TestOutput();
	TestEquality();
}

void BloodLetterStatsTester::TestConstructor()
{
	std::cout << "Testing the constructor. This is just to test for memory leaks" << std::endl;

	Stats* hello = new BloodLetterStats();

	delete hello;

	hello = nullptr;
}

void BloodLetterStatsTester::TestCreateMethod()
{
	std::cout << "Testing the Create method.  This is to just test for memory leaks" << std::endl;

	Stats* hi1 = new BloodLetterStats();

	Stats* hi2 = hi1->Create();

	delete hi1;
	delete hi2;

	hi1 = nullptr;
	hi2 = nullptr;
}

void BloodLetterStatsTester::TestCloneMethod()
{
	std::cout << "Testing the Clone method.  This is just used for memory leaks" << std::endl;

	Stats* hi1 = new BloodLetterStats();

	Stats* hi2 = hi1->Clone();

	delete hi1;
	delete hi2;

	hi1 = nullptr;
	hi2 = nullptr;
}

void BloodLetterStatsTester::TestOutput()
{
	std::cout << "Testing output" << std::endl;

	Stats* hi1 = new BloodLetterStats();

	std::cout << "Expect 5 5 4 3 1 4 4 7 5" << std::endl;
	std::cout << "result " << (*hi1) << std::endl;

	delete hi1;

	hi1 = nullptr;
}

void BloodLetterStatsTester::TestEquality()
{
	std::cout << "Testing to make sure equality works" << std::endl;

	Stats* hi1 = new BloodLetterStats();
	Stats* hi2 = new BloodLetterStats();

	std::cout << "Expect true" << std::endl;
	std::cout << "Result " << ((*hi1) == (*hi2)) << std::endl;

	Stats* hi3 = new DefaultStats();

	std::cout << "Expect false" << std::endl;
	std::cout << "Result " << ((*hi1) == (*hi3)) << std::endl;

	delete hi1;
	delete hi2;
	delete hi3;

	hi1 = nullptr;
	hi2 = nullptr;
	hi3 = nullptr;
}