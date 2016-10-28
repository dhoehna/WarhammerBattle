# WarhammerBattle
Warhammer battle again.

This is a program to simulate an assult between two squads.  THat's about it.

Currently this only supports a 1v1 battle.  And only Bloodletters.

Current plans
1. Add more stats types
2. Add factory for unit stats types
3. Add support for squads
4. Add some kind of IO
5. Add logging
6. Add option rules
7. Allow user to choose what optional rules to use
8. Have the optional rules effect the battle
9. Mix unit types in a squad
10. Add Unit types (HQ, Troop, ELite, Fast Attack, and Heavy Support)
11. Add special rules, like when a monstrous creature fights regular sized troops.


What is a Warhammer?

Warhammer (I'm doing this based on Warhammer 40K) is a table top game by Games Workshop.  It's fun, but long.  Also expensive.

What is this battle simulator?
During the game of warhammer 40K, two squads can fight hand-to-hand.  I want to simulate that.

How does this hand-to-hand fight work?

The attacks are broken down by initiative.  THe higher the initiative the sooner they can attack.  
Each attack has the same structure
 1. Roll to hit
 2. All rolls that hit, roll them to wound
 3. All the rools that wounded, the other squad gets to roll to see if they save (ignore) any wounds
 4. All unsaved wounds are allocated.
 5. the defending squad removes any models that are dead.
 
 Now, if only one side is attacking the wounds are allocated to the other squad and casualties are removed.
 
 This changes if both sides have the same initiative. than all rolls are done at the same time.
 
 Let's say that both squads have some models with the same intiative.  Then all rolls are done at the same time.
