#ifndef STATS_H
#define STATS_H
#include <iostream>
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

	/*----------------------------------------------------------------------------
	 @name Initiative
	 @description gets the initiative
	 @return the initiative.
	*/
	int Initiative();

	/*----------------------------------------------------------------------------
	 @name Create
	 @description makes a new Stats object.  Used in the virtual constructor idiom
		https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Virtual_Constructor
	 @return a pointer to the newly created Stats object.
	*/
	virtual Stats* Create() = 0;

	/*----------------------------------------------------------------------------
	 @name Clone
	 @description makes a deep copy of this Stats object.  Used for virtual constructor idiom
		https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Virtual_Constructor
	 @return a pointer to the newly created copy.
	*/
	virtual Stats* Clone() = 0;

	/*----------------------------------------------------------------------------
	 @name destructor
	 @description destroys this object.
	*/
	virtual ~Stats();

	/*----------------------------------------------------------------------------
	 @name equals operator
	 @description compares two Stats for equality
	 @return true if the Stats are equal, otherwise false.
	*/
	virtual bool operator==(Stats& rightSide);

	/*----------------------------------------------------------------------------
	 @name output operator
	 @description prints the stats.
	 @param os the output stream to print to
	 @param rightSide the Stats to print
	*/
	friend std::ostream& operator<<(std::ostream& os, const Stats& rightSide);

protected:
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
#endif
