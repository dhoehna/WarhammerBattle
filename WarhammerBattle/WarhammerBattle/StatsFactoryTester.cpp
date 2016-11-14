#include "StatsFactoryTester.h"



StatsFactoryTester::StatsFactoryTester()
{
	std::cout << "Testing the Stats Factory" << std::endl;

	factory = new StatsFactory();
}


StatsFactoryTester::~StatsFactoryTester()
{
	delete factory;

	factory = nullptr;
}

void StatsFactoryTester::RunAllTests()
{
	TestCopyConstructor();
	std::cout << std::endl;
	TestGetStatsPassingInNonExistingStats();
	std::cout << std::endl;
	TestGetStatsPassingExistingStats();
	std::cout << std::endl;

	std::cout << "Done testing stats factory" << std::endl;
}

void StatsFactoryTester::TestCopyConstructor()
{
	std::cout << "Testing the copy constructor.  Used to test for memory leaks" << std::endl;

	StatsFactory factory2(*factory);
}

void StatsFactoryTester::TestGetStatsPassingExistingStats()
{
	std::cout << "Testing Get Stats and passing in Bloodletter which exists" << std::endl;


	Stats* bloodLetter = factory->GetStats(BLOODLETTER);

	std::cout << "Expect 5 5 4 3 1 4 4 7 5" << std::endl;
	std::cout << "result " << (*bloodLetter) << std::endl;

	delete bloodLetter;
	bloodLetter = nullptr;
}

void StatsFactoryTester::TestGetStatsPassingInNonExistingStats()
{
	std::cout << "Testing get stats and passing in a non-existing stats" << std::endl;


	Stats* YOLO = factory->GetStats("BLARG");

	std::cout << "Expect 1 1 1 1 1 1 1 1 6" << std::endl;
	std::cout << "Result " << (*YOLO) << std::endl;

	delete YOLO;
	YOLO = nullptr;
}