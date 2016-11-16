#include "BattleEngine.h"
#include <iostream>
#include "vld.h"
#include "Stats.h"
#include "Unit.h"
#include "StatsFactory.h"
#include <string>
#include <algorithm>

//Tests
#include "BloodLetterStatsTester.h"
#include "UnitTester.h"
#include "StatsFactoryTester.h"
#include "SquadTester.h"

int main(int argc, char** argv)
{
	bool shouldWeTest = false;
	if (argc >= 2)
	{
		std::string test(argv[1]);

		std::transform(test.begin(), test.end(), test.begin(), ::tolower);

		if (test.compare("test") == 0)
		{
			shouldWeTest = true;
		}
	}

	if (shouldWeTest)
	{
		BloodLetterStatsTester bloodletterStatsTester;
		bloodletterStatsTester.RunAllTests();

		UnitTester tester;
		tester.RunAllTests();

		StatsFactoryTester statsFactoryTester;
		statsFactoryTester.RunAllTests();

		SquadTester squadTester;
		squadTester.RunAllTests();
	}
	else

	{
		/*
		Alright, down to the meat of things two squads fighting each other.
		*/


		/*StatsFactory statsFactory;

		BattleEngine battleEngine;


		int counter = 0;

		int attackerWonCounter = 0;
		int defenderWonCounter = 0;
		int tieCounter = 0;

		Stats* bloodLetterStats = statsFactory.GetStats(BLOODLETTER);
		Stats* secondStats = statsFactory.GetStats(DEFAULT);

		Unit attacker(bloodLetterStats);
		Unit defender(secondStats);
		int totalRounds = 100000;

		while (counter < totalRounds)
		{

			int winner = battleEngine.Battle(attacker, defender);

			if (BattleEngine::TIE == winner)
			{
				tieCounter++;
			}
			else if (BattleEngine::ATTACKER == winner)
			{
				attackerWonCounter++;
			}
			else
			{
				defenderWonCounter++;
			}
			counter++;

			attacker.Reset();
			defender.Reset();
		}


		double percentAttackerWon = 100 * (((double)attackerWonCounter) / ((double)totalRounds));
		double percentDefenderWon = 100 * (((double)defenderWonCounter) / ((double)totalRounds));
		double percentTie = 100 - (percentAttackerWon + percentDefenderWon);


		std::cout << "Attacker won: " << percentAttackerWon << "\nDefender won: " << percentDefenderWon << "\ntie: " << percentTie << std::endl;*/
	}
}

