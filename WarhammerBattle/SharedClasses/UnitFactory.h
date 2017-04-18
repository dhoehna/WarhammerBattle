#ifndef UNITFACTORY_H
#define UNITFACTORY_H

#include "Unit.h"
#include "Stats.h"
#include "tinyxml2.h"
#include <string>
#include <map>

namespace UnitClasses
{
	class UnitFactory
	{
	public:
		UnitFactory(const char* fileLocation);
		~UnitFactory();

		UnitClasses::Unit* CreateUnit(std::string unitName);

		void GetUnitNames(const char *names[100]);

	private:
		std::map<std::string, UnitClasses::Unit*> units;
		void Add(std::string name, std::string unitType, UnitClasses::Stats* stats);
	};
}

#endif