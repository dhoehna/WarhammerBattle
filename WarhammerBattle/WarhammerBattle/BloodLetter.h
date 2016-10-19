#ifndef BLOOD_LETTER_H
#define BLOOD_LETTER_H
class BloodLetter
{
public:
	BloodLetter();
	BloodLetter(BloodLetter& rightSide);
	~BloodLetter();

	void AllocateWounds(int numberOfUnSavedWounds);

	bool getIsDead();
	int getWeaponSkill();
	int getStrength();
	int getToughness();
	int getSave();

private:
	int weaponSkill;
	int ballisticSkill;
	int strength;
	int toughness;
	int attacks;
	int wounds;
	int save;
	int leaderShip;

	int numberOfWounds;
	bool isDead;

	void Initilize();
};

#endif