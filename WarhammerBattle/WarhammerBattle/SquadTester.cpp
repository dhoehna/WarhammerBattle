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
	std::cout << std::endl;
	TestGetMajorityToughness();
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

void SquadTester::TestGetMajorityToughness()
{
	std::cout << "Testing getting the majority toughness" << std::endl;

	Squad squad;

	std::cout << "Getting majority toughness with no units" << std::endl;
	int majorityToughness = squad.MajorityToughness();
	std::cout << "Expect 1" << std::endl;
	std::cout << "Result " << majorityToughness << std::endl << std::endl;

	StatsFactory factory;

	Stats* stats = factory.GetStats(BLOODLETTER);
	Unit* unit = new Unit(stats);
	squad.AddUnit(unit);

	std::cout << "Getting majroity toughness with one unit" << std::endl;
	std::cout << "Expect 3" << std::endl;
	std::cout << "Result " << squad.MajorityToughness() << std::endl;

	Unit* unit2 = new Unit(*unit);

	squad.AddUnit(unit2);

	std::cout << "Getting majority toughness after adding the same unit a second time" << std::endl;
	std::cout << "Expect 3" << std::endl;
	std::cout << "Result " << squad.MajorityToughness() << std::endl << std::endl;

	Stats* stats3 = factory.GetStats(BLOODTHIRSTER);
	Unit* unit3 = new Unit(stats3);
	squad.AddUnit(unit3);

	std::cout << "Getting majority toughness after adding a different unit" << std::endl;
	std::cout << "Expect 3" << std::endl;
	std::cout << "Result " << squad.MajorityToughness() << std::endl << std::endl;

	Unit* unit4 = new Unit(*unit3);
	squad.AddUnit(unit4);

	std::cout << "Getting the majroty toughness after adding another unit of the same toughness" << std::endl;
	std::cout << "Expect 6" << std::endl;
	std::cout << "Result " << squad.MajorityToughness() << std::endl << std::endl;

	Unit* unit5 = new Unit(*unit);
	squad.AddUnit(unit5);
	std::cout << "Getting the majority toughness after adding another type of the first unit" << std::endl;
	std::cout << "Expect 3" << std::endl;
	std::cout << "Result " << squad.MajorityToughness() << std::endl << std::endl;

	Stats* stats6 = factory.GetStats(KU_GATH);
	Unit* unit6 = new Unit(stats6);

	squad.AddUnit(unit6);
	std::cout << "Getting the majority toughness after adding a third type of stats" << std::endl;
	std::cout << "Expect 3" << std::endl;
	std::cout << "Result " << squad.MajorityToughness() << std::endl;
}