#include "SquadTester.h"



SquadTester::SquadTester()
{
	squad = new Squad();
	factory = new StatsFactory();

	stats = factory->GetStats(BLOODLETTER);
	unit = new Unit(stats);
}


SquadTester::~SquadTester()
{
	delete squad;
	delete factory;

	squad = nullptr;
	factory = nullptr;
}


void SquadTester::RunAllTests()
{
	std::cout << "Testing the Squad class" << std::endl;
	TestAddUnit();
}

void SquadTester::TestAddUnit()
{
	std::cout << "Testing adding a unit" << std::endl;

	std::cout << "ecpect true" << std::endl;
	std::cout << "result " << ((bool)squad->AddUnit(unit)) << std::endl;
}