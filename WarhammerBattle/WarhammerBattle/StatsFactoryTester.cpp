#include "StatsFactoryTester.h"



StatsFactoryTester::StatsFactoryTester()
{
	std::cout << "Testing the Stats Factory" << std::endl;
}


StatsFactoryTester::~StatsFactoryTester()
{
}

void StatsFactoryTester::RunAllTests()
{
	TestConstructor();
	TestCopyConstructor();

	std::cout << "Done testing stats factory" << std::endl;
}

void StatsFactoryTester::TestConstructor()
{
	std::cout << "Testing the constructor to see if there are memoery leaks" << std::endl;

	StatsFactory hi1;
	StatsFactory* hi2 = new StatsFactory();

	delete hi2;

	hi2 = nullptr;

}

void StatsFactoryTester::TestCopyConstructor()
{
	std::cout << "Testing the copy constructor.  Used to test for memory leaks" << std::endl;

	StatsFactory hi1;
	StatsFactory hi2(hi1);
}