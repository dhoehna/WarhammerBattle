#include "StatsFactory.h"


/*-----------------------------------------------------------------------------
 @name constructor
 @description sets up the factory by making a new version of each stats class.
*/
StatsFactory::StatsFactory()
{
	stats[BLOODLETTER] = new BloodLetterStats();
	stats[DEFAULT] = new DefaultStats();
	stats[KAIROS_FATEWEAVER] = new KairosFateweaverStats();
	stats[SKARBRAND] = new SkarbrandStats();
	stats[KU_GATH] = new KuGathStats();
	stats[BLOODTHIRSTER] = new BloodThirsterStats();
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


/*-----------------------------------------------------------------------------
 @name GetStats
 @description Gets the specified stats.
 @param statsName the name of the stats to get
 @return a pointer to the newly created Stats.  Returns default if the stats type does not exist.
*/
Stats* StatsFactory::GetStats(std::string statsName)
{
	std::map<std::string, Stats*>::iterator it = stats.find(statsName);

	if (it != stats.end())
	{
		return stats[statsName]->Create();
	}
	else
	{
		return stats[DEFAULT]->Create();
	}
}