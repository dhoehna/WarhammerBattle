#include "UnitCollection.h"



UnitCollection::UnitCollection()
{
	units = new std::list<Unit*>();
}

void UnitCollection::Add(Unit* unit)
{

}

void UnitCollection::Add(Stats* stats)
{

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
