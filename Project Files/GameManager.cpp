#include "GameManager.h"

bool GameManager::game_over = false;

// Sets the level of the character up 1 and modifies the stats of the character object
void GameManager::level_up(Character& character)
{
	character.set_level(character.get_level() + 1);
	cout << "\nYou are now level " << character.get_level() << "!" << endl;

	update_stats(character);
	system("clear");
}
// Helper function to level_up() function. 
void GameManager::update_stats(Character& character)
{
	// Set the stats of the character back to what the stats were during the battle.
	StatsTemp::load_stats(character);	

	int points = 10;	// points acquired everytime character levels up
	
	// Loop until the amount of points to assign is 0.
	while (points > 0)
	{
		cout << "\nYou have " << points << " points to assign to your skills" << endl;
		character.display_stats();
		int num;
		cout << "\nHow many points do you want to assign to your skills?: ";
		cin >> num;
		if (num > points || num <= 0)
		{
			cout << "Please input a number that is less than " << points << " and more than 0" << endl;
			continue;
		}
		points -= num;

		// Update stats
		character.display_stats();
		cout << "\nPick which skill to upgrade: ";
		int selection;
		cin >> selection;
		while (selection < 1 || selection > 5)	// Input validation
		{
			cout << "Please Enter a number in the range 1-5: " << endl;
			cin >> selection;
		}
		if (selection == 1) { character.set_HP(character.get_HP() + num); }
		else if (selection == 2) { character.set_ATK(character.get_ATK() + num); }
		else if (selection == 3) { character.set_DEF(character.get_DEF() + num); }
		else if (selection == 4) { character.set_MP(character.get_MP() + num); }
		else if (selection == 5) { character.set_SP(character.get_SP() + num); }
	}
	// Show the updated stats
	character.display_stats();
	StatsTemp::store_stats(character);	// Store the updated stats into temporary data members
}
// Every time it's the character's turn, a random number is generated and is added to the SP data member within Character class
void GameManager::regen_SP(Character& character)
{
	int rand_num = (rand() % 4) + 2;	// Generates a random value from 2-5
	character.set_SP(character.get_SP() + rand_num);

	if (character.get_SP() >= StatsTemp::get_SP())	
		character.set_SP(StatsTemp::get_SP());	// Validates that the SP value doesn't exceed the value stored in the temp variable in StatsTemp class
}
// User interface
void GameManager::display_combat(Character& character, Boss& boss)
{
	cout << '\n' << right << setw(30) << "Level " << character.get_level() << "\n\n\n";
	cout << character.get_name() << '\t' << character.get_role() << right << setw(40) << "Boss: " << boss.get_HP() <<  '\n' << endl;
	character.display_stats();
	
	cout << '\n' << "Attacks" << '\n' << endl;
	character.display_attacks();
	cout << "\nChoose an attack (1-3): ";	
}




