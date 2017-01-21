/*
	WHAT IS THIS?
	This is a squad.  Basically a container of units.  These will have information for battles.

	ANY ASSUMPTIONS?
	No.

	ANYTHING ELSE I SHOULD KNOW?
	Yes.  This will handle the deleting of all the units.
*/


#include "Squad.h"

namespace UnitClasses
{
	Squad::Squad()
	{
		name = "nothing";
		Initilize();
	}

	Squad::Squad(std::string name) : name(name)
	{
		Initilize();
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

		Initilize();
	}

	void Squad::Initilize()
	{
		toughnesses.resize(20);
		weaponSkills.resize(20);
		for (size_t toughnessIndex = 0; toughnessIndex < toughnesses.size(); toughnessIndex++)
		{
			toughnesses[toughnessIndex] = 0;
		}

		for (size_t weaponSkillIndex = 0; weaponSkillIndex < weaponSkills.size(); weaponSkillIndex++)
		{
			weaponSkills[weaponSkillIndex] = 0;
		}

		majorityToughness = 1;
		majorityWeaponSkill = 1;
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

	int Squad::MajorityToughness()
	{
		return majorityToughness;
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
			weaponSkills[unitToAdd->WeaponSkill()]++;
			toughnesses[unitToAdd->Toughness()]++;
			CalculateMajorityToughness();
			return true;
		}
		else
		{
			return false;
		}
	}


	void Squad::CalculateMajorityToughness()
	{
		majorityToughness = CalculateMajority(toughnesses);
	}

	int Squad::CalculateMajority(std::vector<int>& numbers)
	{
		int maxNumberOfUnitsWithACertainToughness = 0;
		int index = 1;

		for (int numbersIndex = numbers.size() - 1; numbersIndex > 0; numbersIndex--)
		{
			if (numbers[numbersIndex] > maxNumberOfUnitsWithACertainToughness)
			{
				maxNumberOfUnitsWithACertainToughness = toughnesses[numbersIndex];
				index = numbersIndex;
			}
		}

		if (index > 1)
		{
			majorityToughness = index;
		}

		return index;
	}
}