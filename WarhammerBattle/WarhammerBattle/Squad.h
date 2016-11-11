#ifndef SQUAD_H
#define SQUAD_H
#include <string>
#include <vector>
#include "Unit.h"
class Squad
{
public:
	Squad();
	~Squad();

	bool AddUnit(Unit& unitToAdd);

private:
	std::string name;
	std::vector<Unit> units;

};

#endif
