#include "Squad.h"



Squad::Squad()
{
}


Squad::~Squad()
{
	for (Unit* unit : units)
	{
		delete unit;

		unit = nullptr;
	}
}

Squad::Squad(Squad& rightSide)
{
	for (Unit* unit : rightSide.units)
	{
		units.push_back(new Unit(*unit));
	}
}

int Squad::Size()
{
	return units.size();
}


std::ostream& operator<<(std::ostream& os, const Squad& rightSide)
{
	for (Unit* unit : rightSide.units)
	{
		os << (*unit) << "\n";
	}

	return os;
}

/*-----------------------------------------------------------------------------
 @name AddUnit
 @description adds the passed in Unit to the squad
 @param the unit to add
 @return true if the insertion was successful, otherwise false.
*/
bool Squad::AddUnit(Unit* unitToAdd)
{
	if (unitToAdd != nullptr)
	{
		units.push_back(unitToAdd);
		return true;
	}
	else
	{
		return false;
	}
}
