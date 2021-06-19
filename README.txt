----------AUTO BOSS GENERATOR------------

1. Make sure you are using a linux SSH (e.g: Student Cluster) to run this program.

2. Make sure that the input file that the program will read from is named "Accounts.txt" in order to function properly,
   Also make sure that it's in the working directory of your SSH.

3. If there are no entries in the "Accounts.txt" please register an account before logging in, as it will endlessly keep prompting for
   a username and password that exists in the file.

The program is a turn-based game where the program generates a boss based on the player's level.
For each boss defeated, you will be able to update your character's stats and continue fighting bosses.

These stats are:

	1. Health Points (HP) 	- "It's literally in the name"
	2. Attack Points (ATK) 	- Deal damage based on your ATK, useful for Warrior and Archer. USELESS with Mage
	3. Defense Points (DEF) - Defense reduces the damage dealt by the boss.
	4. Mana Points 	(MP) 	- Mana points deal damage based on MP, USELESS with Warrior and Archer
	5. Skill Points (SP) 	- Skill points are essentialy a requirement to perform certain attacks

You will be prompted to enter 3 different types of attacks:

	1. Basic attack 	(Requires 1 SP)		- Deals normal damage
	2. Secondary attack 	(Requires 5 SP)		- Deals more damage
	3. Final attack		(Requires 10 SP)	- Deals even more damage  

The 3 roles you can play as are:
	
	1. Warrior - Initial high DEF, attacks have average damage. Attacks are based on ATK stat

	2. Mage - Initial high MP, attacks deal more damage but Mages also have lower DEF. Attacks are based on MP stat

	3. Archer Initial high ATK, attacks deal more damage but Archers also have lower DEF. Attacks are based on ATK stat

Each time it's your turn, there will be a random integer value that adds to your SP stat so that you can regenerate your SP to use your skills.

---The program finally ends when the player is defeated. For testing purposes, if you want to end the program early, you can apply skill points to the USELESS
---stat that pertains to your character so that the program can finally end and write the contents of the account to the output file

That's about it! When you've finished you can check the file and it should have account info on there and correctly update the file.

Thanks for checking it out, hope you enjoy!
