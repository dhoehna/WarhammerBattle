#include "BattleEngine.h"
#include "UnitCollection.h"
#include <iostream>
#include "Stats.h"
#include <string>
#include <algorithm>


int main(int argc, char** argv)
{
	//tinyxml2::XMLDocument doc;
	//doc.LoadFile("..\\WarhammerBattleGenerator\\bin\\Debug\\units.xml");
	
	UnitClasses::UnitCollection unitsAvalibleForBattle("..\\WarhammerBattleGenerator\\bin\\Debug\\units.xml");

	
	//const char* unitName = doc.FirstChildElement("units")->FirstChildElement("unit")->FirstChildElement("unitName")->GetText();
	std::cout << std::endl;




	/*
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
	*/

	/**
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

		What will need to happen?
		Attacks need to be organized by initiative
		All attacks need their own object
		All attacks need to be in a container for attacker and defender.
		If there is only an attacker than the attaker needs to attack and wounds need to be taken.
		If there is only a defender than the defender needs to attack and wounds need to be taken.
		If there are attakers and defenders than the attacks need to happen before any wounds are taken.

		so, the squad will need to be able to get all attacks, along with their initiaves.  So, map<int, attacks>
		int being in I value.  What is an attacks?  Or a list of attack object?

		Also a squad needs to keep track of it's average weapon skill, which should update and units are added, or killed.

		THe idea is to get all attacks for both squads and merge the two while knowing which attacks belong to the defender
		and which belong to the attacker.

		so, a squad can return a map of <int, attack> or, an object, which holds the initiave value and all attacks.
		or a map.  Make it easier.

		so, what is an attack?

		Well how will I use it?  WHy not just a pointer to the stats? so map<int, Stats*>?

		so, both squads return a map<int, List<Stats*>> this represents the attacks at each initiative

		Than the battle engine can take those and make a map, or an array use the subscripts for the initiave value
		and put object in there so in array 1 wil be all attacks that have inititave 1 and all attacker attacks and
		 defender attacks

		 How will I disguinguish between attacker and defender?  have an enum  {ATTACKER, DEFENDER}? or a string and
		 have const strings?  Maybe the enum is better.

		 So
			Side int;
			array of stat pointers

		than the battle engine can have something that has all atccker and defender

		well, or.

		Hmm.

		So I want to get all attackes from attacker and defender.
		Put them in one list organzed by initiative.

		go one by one and do the attacks from highest to lowest.

		To do attacks at initiative ten, what do I need?
		Which attacks belong to defenders.
		Which attacks belong to attackers
		the average weapon skill of

		Wait, what about this?

		have each squad keep track of the highest initiative and the average weapon skill.
		Then, when battle starts query both squads to get the highest initiative

		than, loop from the highest initiative to 1

		at each level get all attacks from defender and attacker

		do the attacks.  Boom.  WOnderful

		so, it would be this.  DO attacker attacker (if there is none, nothing should happen, get the wounds)
		Do defender attacks (If there are none, nothing should happen.  0 unsaved wounds should be returned)

		no that won't work

		yes it will.  These ar initiative based.

		so get highest
		count from there to 1
		do damage stuff
		the squad will recalculate the average WS and I when units die.

		what will we need to ask the squad?
		Get all attcks with Initiave blah
		get average weapon skill
		get highest initiave
		allocate wounds number

		Well, I can't just grab all attacks.  They need to be seperated by unit

		so, why not just grab all units that attack?

		So it will need to grab a list of units that need to attack.

		so, it can return an object
		average WS
		List Unit pointers that have that initiative

		What about Toughness?  majority.  So, the squad also needs to keep track of the majority of the toughness
		and will send that in with the attack thingie.

		How will it get the majority of it's toughness?

		well.  Have a dynamic array with the subscript being the toughness and keep track of how many there are of each.
		Than, when asked to get the toughness just query that array.

		Let's work on the average weapon skill.

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


		std::cout << "Attacker won: " << percentAttackerWon << "\nDefender won: " << percentDefenderWon << "\ntie: " << percentTie << std::endl;


	}
	*/
}

