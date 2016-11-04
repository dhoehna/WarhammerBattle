/*
	WHAT IS THIS?
	This is a factory for making the stats for units.  SImple as that?

	WHAT IS IT FOR?
	So all the newing up of the stats will be kept in one spot.

	ANY ASSUMPTIONS?
	Not that I know of
*/

#ifndef STATSFACTORY_H
#define STATSFACTORY_H
#include <map>
#include "Stats.h"
#include <string>
#include "BloodLetterStats.h"
#include "Constants.h"
class StatsFactory
{
public:

	/*----------------------------------------------------------------------------
	 @name constructor
	 @description sets up the factory
	*/
	StatsFactory();

	/*----------------------------------------------------------------------------
	 @name copy constructor
	 @description makes a copy of this factory
	*/
	StatsFactory(StatsFactory& rightSide);

	/*----------------------------------------------------------------------------
	 @name destructor
	 @description destroys this factory
	*/
	virtual ~StatsFactory();

private:
	std::map<std::string, Stats*> stats;
};

#endif