#include "BloodLetter.h"



BloodLetter::BloodLetter()
{
	Initilize();
	isDead = false;
	numberOfWounds = 0;
}

BloodLetter::BloodLetter(BloodLetter& rightSide)
{
	Initilize();
	this->isDead = rightSide.isDead;
	this->numberOfWounds = rightSide.numberOfWounds;
}


BloodLetter::~BloodLetter()
{
}

bool BloodLetter::getIsDead()
{
	return isDead;
}

int BloodLetter::getWeaponSkill()
{
	return weaponSkill;
}

int BloodLetter::getStrength()
{
	return strength;
}

int BloodLetter::getToughness()
{
	return toughness;
}

int BloodLetter::getSave()
{
	return save;
}

int BloodLetter::getInitiative()
{
	return initiative;
}

void BloodLetter::AllocateWounds(int numberOfUnSavedWounds)
{
	int woundCounter = 0;
	while (!isDead && woundCounter < numberOfUnSavedWounds)
	{
		numberOfWounds++;

		if (numberOfWounds == wounds)
		{
			isDead = true;
		}

		woundCounter++;
	}
}

void BloodLetter::Initilize()
{
	weaponSkill = 5;
	ballisticSkill = 5;
	strength = 5;
	toughness = 5;
	leaderShip = 5;
	attacks = 1;
	wounds = 1;
	save = 5;
	leaderShip = 9;
	initiative = 5;
}