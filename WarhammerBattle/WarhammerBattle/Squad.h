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
	Squad(Squad& rightSide);

	friend std::ostream& operator<<(std::ostream& os, const Squad& rightSide);

	bool AddUnit(Unit* unitToAdd);
	int Size();


private:
	std::string name;
	std::vector<Unit*> units;

};

#endif
