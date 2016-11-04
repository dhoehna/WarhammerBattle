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
	for (std::map<std::string, Stats*>::const_iterator it = stats.begin(); it != stats.end(); ++it)
	{
		stats[(*it).first] = (*it).second->Clone();
	}
}


/*-----------------------------------------------------------------------------
 @name desctructor
 @description destroys this.  Also goes through the map and deletes all Stats.
*/
StatsFactory::~StatsFactory()
{
	for (std::map<std::string, Stats*>::const_iterator it = stats.begin(); it != stats.end(); ++it)
	{
		delete  ((*it).second);
	}
}
