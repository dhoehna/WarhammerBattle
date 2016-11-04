#include "StatsFactory.h"


/*-----------------------------------------------------------------------------
 @name constructor
 @description sets up the factory by making a new version of each stats class.
*/
StatsFactory::StatsFactory()
{
	stats[BLOODLETTER] = new BloodLetterStats();
}

/*-----------------------------------------------------------------------------
 @name copy constructor
 @description makes a deep copy of the passed in factory
 @param rightSide the factory to make a copy of.
*/
StatsFactory::StatsFactory(StatsFactory& rightSide)
{
	for (auto &foo : rightSide.stats)
	{
		stats[foo.first] = foo.second->Clone();
	}
}


/*-----------------------------------------------------------------------------
 @name desctructor
 @description destroys this.  Also goes through the map and deletes all Stats.
*/
StatsFactory::~StatsFactory()
{
	for (auto &foo : stats)
	{
		delete foo.second;
	}
}
