#include "Stats.h"

Stats::~Stats()
{
	//nothing to do here.
}

/*-----------------------------------------------------------------------------
 @name Equals operator
 @description compares two stats for equality by comparing each value.
 @return false if one value does not match, otherwise true.
*/
bool Stats::operator==(Stats& rightSide)
{
	if (this->weaponSkill != rightSide.weaponSkill)
	{
		return false;
	}
	
	if (this->ballisticSkill != rightSide.ballisticSkill)
	{
		return false;
	}

	if (this->attacks != rightSide.attacks)
	{
		return false;
	}

	if (this->initiative != rightSide.initiative)
	{
		return false;
	}

	if (this->leaderShip != rightSide.leaderShip)
	{
		return false;
	}

	if (this->save != rightSide.save)
	{
		return false;
	}

	if (this->strength != rightSide.strength)
	{
		return false;
	}

	if (this->toughness != rightSide.toughness)
	{
		return false;
	}

	if (this->wounds != rightSide.wounds)
	{
		return false;
	}

	return true;
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
