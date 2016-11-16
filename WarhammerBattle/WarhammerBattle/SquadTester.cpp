#include "SquadTester.h"



SquadTester::SquadTester()
{
}


SquadTester::~SquadTester()
{
}


void SquadTester::RunAllTests()
{
	std::cout << "Testing the Squad class" << std::endl;
	TestAddUnit();
	std::cout << std::endl;
	TestAddUnitPassInNull();
	std::cout << std::endl;
	TestOutput();
	std::cout << std::endl;
	TestSize();
	std::cout << std::endl;
	TestCopyConstructor();
}

void SquadTester::TestAddUnit()
{
	std::cout << "Testing adding units" << std::endl;

	StatsFactory factory;
	Squad squad;
	
	Stats* stats = factory.GetStats(BLOODLETTER);
	Unit* unit = new Unit(stats);
	
	Stats* stats2 = factory.GetStats(DEFAULT);
	Unit* unit2 = new Unit(stats2);

	std::cout << "Adding first unit" << std::endl;
	std::cout << "expect true" << std::endl;
	std::cout << "result " << squad.AddUnit(unit) << std::endl;

	std::cout << "Adding second unit" << std::endl;
	std::cout << "Expect true" << std::endl;
	std::cout << "Result " << squad.AddUnit(unit2) << std::endl;
}

void SquadTester::TestAddUnitPassInNull()
{

	Squad squad;

	std::cout << "Testing adding a null unit" << std::endl;
	std::cout << "Expect false" << std::endl;
	std::cout << "Result " << squad.AddUnit(nullptr) << std::endl;
}

void SquadTester::TestOutput()
{
	std::cout << "Testing output operator" << std::endl;
	StatsFactory factory;
	Squad squad;

	Stats* stats = factory.GetStats(BLOODLETTER);
	Unit* unit = new Unit(stats);

	Stats* stats2 = factory.GetStats(DEFAULT);
	Unit* unit2 = new Unit(stats2);

	std::cout << "Printing an empty squad" << std::endl;
	std::cout << "Expect" << std::endl;
	std::cout << "Result" << squad << std::endl << std::endl;

	std::cout << "Printing squad with one unit" << std::endl;
	squad.AddUnit(unit);
	std::cout << "Expect 5 5 4 3 1 4 4 7 5" << std::endl;
	std::cout << "Result " << squad << std::endl;

	std::cout << "Printing squad with two units" << std::endl;
	squad.AddUnit(unit2);
	std::cout << "Expect 5 5 4 3 1 4 4 7 5\n1 1 1 1 1 1 1 1 6" << std::endl;
	std::cout << "Result " << squad << std::endl;
}

void SquadTester::TestSize()
{
	std::cout << "Testing size()" << std::endl;

	StatsFactory factory;
	Squad squad;

	Stats* stats = factory.GetStats(BLOODLETTER);
	Unit* unit = new Unit(stats);

	Stats* stats2 = factory.GetStats(DEFAULT);
	Unit* unit2 = new Unit(stats2);

	std::cout << "Printing a size of 0" << std::endl;
	std::cout << "Expect 0" << std::endl;
	std::cout << "Result " << squad.Size() << std::endl;

	std::cout << "Printing a size of 1" << std::endl;
	squad.AddUnit(unit);
	std::cout << "Expect 1" << std::endl;
	std::cout << "Result " << squad.Size() << std::endl;

	std::cout << "Printing a size of 2" << std::endl;
	squad.AddUnit(unit2);
	std::cout << "Expect 2" << std::endl;
	std::cout << "Result " << squad.Size() << std::endl;

	
}

void SquadTester::TestCopyConstructor()
{
	std::cout << "Testing the copy constructor" << std::endl;

	StatsFactory factory;
	Squad squad;

	Stats* stats = factory.GetStats(BLOODLETTER);
	Unit* unit = new Unit(stats);

	Stats* stats2 = factory.GetStats(DEFAULT);
	Unit* unit2 = new Unit(stats2);

	std::cout << "Copying an empty squad" << std::endl;
	Squad squad1(squad);

	std::cout << "Size of copied squad" << std::endl;
	std::cout << "Expect 0" << std::endl;
	std::cout << "Result " << squad1.Size() << std::endl << std::endl;

	std::cout << "Printing empty squad" << std::endl;
	std::cout << "Expect" << std::endl;
	std::cout << "Result" << squad1 << std::endl << std::endl;

	std::cout << "Making a copy of a size 1 squad" << std::endl;
	squad.AddUnit(unit);
	Squad squad2(squad);
	std::cout << "Size of copied squad" << std::endl;
	std::cout << "Expect 1" << std::endl;
	std::cout << "Result " << squad2.Size() << std::endl << std::endl;

	std::cout << "Printing copied squad" << std::endl;
	std::cout << "Expect 5 5 4 3 1 4 4 7 5" << std::endl;
	std::cout << "Result " << squad2 << std::endl;

	std::cout << "Making a copy of a squad with 2 units" << std::endl;
	squad.AddUnit(unit2);
	Squad squad3(squad);
	std::cout << "Size of copied squad" << std::endl;
	std::cout << "Expect 2" << std::endl;
	std::cout << "result " << squad3.Size() << std::endl << std::endl;

	std::cout << "Printing copied squad" << std::endl;
	std::cout << "Expect 5 5 4 3 1 4 4 7 5\n1 1 1 1 1 1 1 1 6" << std::endl;
	std::cout << "Result " << squad << std::endl;
}