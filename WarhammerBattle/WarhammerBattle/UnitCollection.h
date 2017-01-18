#ifndef UNITCOLLECTION_H
#define UNITCOLLECTION_H
#include <list>
#include "Unit.h"
class UnitCollection
{
public:
	UnitCollection();
	~UnitCollection();

private:
	std::list<Unit*>* units;
};

#endif
