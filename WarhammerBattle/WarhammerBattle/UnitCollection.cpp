#include "UnitCollection.h"



UnitCollection::UnitCollection()
{
	units = new std::list<Unit*>();
}

void UnitCollection::Add(std::string name, std::string unitType, Unit* unit)
{

}

void UnitCollection::Add(std::string name, std::string unitType, Stats* stats)
{
	units->push_front(new Unit(name, unitType, stats));
}


UnitCollection::~UnitCollection()
{
	for (Unit* unit : (*units))
	{
		delete unit;
		unit = nullptr;
	}

	delete units;
	units = nullptr;
}
