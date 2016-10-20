#ifndef ISTATS_H
#define ISTATS_H
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
	int Initiative();

private:

	Stats();
	Stats(Stats& rightSide);



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
