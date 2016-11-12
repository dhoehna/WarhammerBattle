#include "Squad.h"



Squad::Squad()
{
}


Squad::~Squad()
{
	
}

Squad::Squad(Squad& rightSide)
{

}

bool Squad::AddUnit(Unit unitToAdd)
{
	units.push_back(unitToAdd);
	return true;
}
