#ifndef UNITCOLLECTION_H
#define UNITCOLLECTION_H
#include <list>
#include "Unit.h"
#include <string>
class UnitCollection
{
public:
	UnitCollection();
	~UnitCollection();

	void Add(std::string name, std::string unitType, Unit* unit);
	void Add(std::string name, std::string unitType, Stats* stats);
private:
	std::list<Unit*>* units;
};

#endif
