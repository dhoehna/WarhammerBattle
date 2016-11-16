/*
	WHAT IS THIS?
	This is a squad.  Basically a container of units.  These will have information for battles.

	ANY ASSUMPTIONS?
	No.

	ANYTHING ELSE I SHOULD KNOW?
	Yes.  This will handle the deleting of all the units.
*/


#include "Squad.h"

Squad::Squad()
{
	name = "nothing";
}

Squad::Squad(std::string name) : name(name)
{
	//Intentionally left blank
}


/*-----------------------------------------------------------------------------
 @name destructor
 @description delets al units in this squad.
*/
Squad::~Squad()
{
	for (Unit* unit : units)
	{
		delete unit;

		unit = nullptr;
	}
}

/*-----------------------------------------------------------------------------
 @name copy constructor
 @description makes a copy of this Squad
 @param rightSide the Squad to make a copy of.
 @return a new Squad that is a deep copy of the passed in Squad.
*/
Squad::Squad(Squad& rightSide)
{
	for (Unit* unit : rightSide.units)
	{
		units.push_back(new Unit(*unit));
	}

	name = rightSide.name;
}

/*-----------------------------------------------------------------------------
 @name Size
 @description gets the number of units in the squad
 @return an int representation of the number of units in the squad
*/
int Squad::Size()
{
	return units.size();
}

/*-----------------------------------------------------------------------------
 @name Name
 @Description gets then ame of this squad
*/
std::string Squad::Name()
{
	return name;
}


/*-----------------------------------------------------------------------------
 @name output operator
 @description output the squad to os
 @param os the stream to output to
 @param rightSide the Squad to print
 @return a reference to the output stream
*/
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
