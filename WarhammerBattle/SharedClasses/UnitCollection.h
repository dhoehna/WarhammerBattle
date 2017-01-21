#ifndef UNITCOLLECTION_H
#define UNITCOLLECTION_H
#include <list>
#include "Unit.h"
#include <string>
#include "tinyxml2.h"

namespace UnitClasses
{
	class UnitCollection
	{
	public:
		UnitCollection(const char* fileLocation);
		~UnitCollection();

		void Add(std::string name, std::string unitType, Unit* unit);
		void Add(std::string name, std::string unitType, Stats* stats);
	private:
		std::list<Unit*>* units;
	};
}

#endif
