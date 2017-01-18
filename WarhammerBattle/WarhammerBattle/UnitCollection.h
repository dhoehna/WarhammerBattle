#ifndef UNITCOLLECTION_H
#define UNITCOLLECTION_H
#include <list>
#include "Unit.h"
class UnitCollection
{
public:
	UnitCollection();
	~UnitCollection();

	void Add(Unit* unit);
	void Add(Stats* stats);
private:
	std::list<Unit*>* units;
};

#endif
