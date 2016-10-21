#include "BloodLetter.h"
#include "BattleEngine.h"
#include <iostream>
#include "vld.h"
#include "Stats.h"
#include "BloodLetterStats.h"
#include "Unit.h"
int main(int argc, char* argv)
{
	Stats* bloodLetterStats = new BloodLetterStats();
	Unit* attacker = new Unit(bloodLetterStats);

	Unit* defender = new Unit(*attacker);



	delete attacker;
	delete defender;
	//BloodLetter first;
	//BloodLetter second;

	//BattleEngine engine;

	//int counter = 0;

	//int attackerWonCounter = 0;
	//int defenderWonCounter = 0;
	//int tieCounter = 0;

	//while (counter < 100000)
	//{
	//	int winner = engine.Battle(first, second);

	//	if (BattleEngine::TIE == winner)
	//	{
	//		tieCounter++;
	//	}
	//	else if (BattleEngine::ATTACKER == winner)
	//	{
	//		attackerWonCounter++;
	//	}
	//	else
	//	{
	//		defenderWonCounter++;
	//	}
	//	counter++;
	//}

	//std::cout << "Attacker won: " << attackerWonCounter << "\nDefender won: " << defenderWonCounter << "\ntie: " << tieCounter << std::endl;
}

