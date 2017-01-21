#ifndef SQUAD_H
#define SQUAD_H
#include <string>
#include <vector>
#include "Unit.h"

namespace UnitClasses
{
	class Squad
	{
	public:
		Squad();
		Squad(std::string name);
		~Squad();
		Squad(Squad& rightSide);

		friend std::ostream& operator<<(std::ostream& os, const Squad& rightSide);

		bool AddUnit(Unit* unitToAdd);
		int Size();
		std::string Name();
		int MajorityToughness();


	private:
		std::string name;
		std::vector<Unit*> units;
		int majorityWeaponSkill;
		int majorityToughness;

		std::vector<int> weaponSkills;
		std::vector<int> toughnesses;

		void CalculateMajorityToughness();
		void Initilize();
		int CalculateMajority(std::vector<int>& numbers);
	};
}

#endif
