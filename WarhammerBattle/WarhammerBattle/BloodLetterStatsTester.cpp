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