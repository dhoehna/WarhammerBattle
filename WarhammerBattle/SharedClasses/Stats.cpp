#include "Stats.h"

namespace UnitClasses
{
	Stats::~Stats()
	{
		//nothing to do here.
	}

	Stats::Stats()
	{
		//Make a default stats
		weaponSkill = 1;
		ballisticSkill = 1;
		strength = 1;
		toughness = 1;
		wounds = 1;
		attacks = 1;
		initiative = 1;
		leaderShip = 1;
		save = 6;
	}

	Stats::Stats(int weaponSkill, int ballisticSkill, int strength, int toughness, int wounds, int attacks, int initiative, int leadership, int save) :
		weaponSkill(weaponSkill), ballisticSkill(ballisticSkill), strength(strength), toughness(toughness), wounds(wounds), attacks(attacks), initiative(initiative), leaderShip(leadership), save(save)
	{
		/* intentionally left blank*/
	}

	Stats::Stats(const Stats& statsToCopy)
	{
		this->weaponSkill = statsToCopy.weaponSkill;
		this->ballisticSkill = statsToCopy.ballisticSkill;
		this->strength = statsToCopy.strength;
		this->toughness = statsToCopy.toughness;
		this->wounds = statsToCopy.wounds;
		this->attacks = statsToCopy.attacks;
		this->initiative = statsToCopy.initiative;
		this->leaderShip = statsToCopy.leaderShip;
		this->save = statsToCopy.save;
	}

	/*-----------------------------------------------------------------------------
	 @name output operator
	 @description prints out the Stats object
	 @param os the output stream to print to
	 @param rightSide the Stats object to print.
	 @return a reference to the os stream.
	*/
	std::ostream& operator<<(std::ostream& os, const Stats& rightSide)
	{
		os << rightSide.weaponSkill << " ";
		os << rightSide.ballisticSkill << " ";
		os << rightSide.strength << " ";
		os << rightSide.toughness << " ";
		os << rightSide.wounds << " ";
		os << rightSide.attacks << " ";
		os << rightSide.initiative << " ";
		os << rightSide.leaderShip << " ";
		os << rightSide.save;
		return os;
	}

	/*-----------------------------------------------------------------------------
	 @name WeaponSkill
	 @description gets the weaponskill value of these stats
	 @return an int representation of the weaponskill
	*/
	int Stats::WeaponSkill()
	{
		return weaponSkill;
	}


	/*----------------------------------------------------------------------------
	 @name BallisticSkill
	 @description gets the ballistic skill value of these stats
	 @return an int representation of the ballistic skill.
	*/
	int Stats::BallisticSkill()
	{
		return ballisticSkill;
	}

	/*----------------------------------------------------------------------------
	 @name Strength
	 @description gets the strength value for these stats
	 @return an int representation of the strength value.
	*/
	int Stats::Strength()
	{
		return strength;
	}

	/*----------------------------------------------------------------------------
	 @name Toughness
	 @description gets the toughness value for these stats
	 @return an int representation of the toughness value.
	*/
	int Stats::Toughness()
	{
		return toughness;
	}

	/*----------------------------------------------------------------------------
	 @name Attacks
	 @description gets the attack value of these stats
	 @return an int representation of the attacks value
	*/
	int Stats::Attacks()
	{
		return attacks;
	}

	/*----------------------------------------------------------------------------
	 @name Wounds
	 @description gets the wound value for these stats
	 @return an int representation of the wound value
	*/
	int Stats::Wounds()
	{
		return wounds;
	}

	/*----------------------------------------------------------------------------
	 @name Save
	 @description gets the save value for these stats.
	 @return an int representation of the save value
	*/
	int Stats::Save()
	{
		return save;
	}

	/*----------------------------------------------------------------------------
	 @name Leadership
	 @description gets the leadership value for these stats
	 @return an in representation of the leadership value
	*/
	int Stats::LeaderShip()
	{
		return leaderShip;
	}

	/*----------------------------------------------------------------------------
	 @name Initiative
	 @description gets the initiave
	 @return an int representation of the initiative
	*/
	int Stats::Initiative()
	{
		return initiative;
	}
}