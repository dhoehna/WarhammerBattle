#ifndef BLOODLETTERSTATS_H
#define BLOODLETTERSTATS_H
#include "Stats.h"
class BloodLetterStats : public Stats
{
public:
	BloodLetterStats();
	BloodLetterStats(BloodLetterStats& rightSide);
	virtual ~BloodLetterStats();

	BloodLetterStats* BloodLetterStats::Create();
	BloodLetterStats* BloodLetterStats::Clone();

private:
	void Initilize();
};

#endif

