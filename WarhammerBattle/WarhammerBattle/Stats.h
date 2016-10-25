#ifndef STATS_H
#define STATS_H
#include "ITestable.h"

class Stats : public ITestable {

public:
	int WeaponSkill();
	int BallisticSkill();
	int Strength();
	int Toughness();
	int Attacks();
	int Wounds();
	int Save();
	int LeaderShip();
	int Initiative();

	virtual Stats* Create() = 0;
	virtual Stats* Clone() = 0;
	virtual ~Stats();
	virtual bool operator==(ITestable& rightSide);

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
