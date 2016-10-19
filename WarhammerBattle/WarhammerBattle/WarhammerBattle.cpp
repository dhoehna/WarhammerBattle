#include "BloodLetter.h"
#include "BattleEngine.h"
#include <iostream>
#include "vld.h"
int main(int argc, char* argv)
{
	BloodLetter first;
	BloodLetter second;

	BattleEngine engine;

	int counter = 0;

	int attackerWonCounter = 0;
	int defenderWonCounter = 0;
	int tieCounter = 0;

	while (counter < 1000)
	{
		int winner = engine.Battle(first, second);

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
	}

	std::cout << "Attacker won: " << attackerWonCounter << "\nDefender won: " << defenderWonCounter << "\ntie: " << tieCounter << std::endl;
}

