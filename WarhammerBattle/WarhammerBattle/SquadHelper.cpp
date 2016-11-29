#include "SquadHelper.h"



SquadHelper::SquadHelper()
{
}


SquadHelper::~SquadHelper()
{
}

/*-----------------------------------------------------------------------------
 @name CalculateMajority
 @description goes through the vector and sees what index has the highest number.
 @param numbers the vector to look through.
*/
int SquadHelper::CalculateMajority(const std::vector<int>& numbers)
{
	int maxNumberOfUnitsWithACertainToughness = 0;
	int index = 1;

	for (int numbersIndex = numbers.size() - 1; numbersIndex > 0; numbersIndex--)
	{
		if (numbers[numbersIndex] > maxNumberOfUnitsWithACertainToughness)
		{
			maxNumberOfUnitsWithACertainToughness = numbers[numbersIndex];
			index = numbersIndex;
		}
	}
	return index;
}
