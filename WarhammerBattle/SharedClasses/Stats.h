#ifndef STATS_H
#define STATS_H
#include <iostream>
namespace UnitClasses
{
	class Stats {

	public:
		int WeaponSkill();
		int BallisticSkill();
		int Strength();
		int Toughness();
		int Attacks();
		int Wounds();
		int Save();
		int LeaderShip();


		Stats();

		Stats(int weaponSkill, int ballisticSkill, int strength, int toughness, int wounds, int attacks, int initiative, int leadership, int save);

		Stats(const Stats& statsToCopy);

		/*----------------------------------------------------------------------------
		 @name Initiative
		 @description gets the initiative
		 @return the initiative.
		*/
		int Initiative();

		/*----------------------------------------------------------------------------
		 @name destructor
		 @description destroys this object.
		*/
		virtual ~Stats();

		/*----------------------------------------------------------------------------
		 @name output operator
		 @description prints the stats.
		 @param os the output stream to print to
		 @param rightSide the Stats to print
		*/
		friend std::ostream& operator<<(std::ostream& os, const Stats& rightSide);

	private:
		int weaponSkill;
		int ballisticSkill;
		int strength;
		int toughness;
		int attacks;
		int wounds;
		int save;
		int leaderShip;
		int initiative;
	};
}
#endif
