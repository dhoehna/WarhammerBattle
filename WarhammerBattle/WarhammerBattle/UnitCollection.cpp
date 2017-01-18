#include "UnitCollection.h"



UnitCollection::UnitCollection()
{
	units = new std::list<Unit*>();
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
