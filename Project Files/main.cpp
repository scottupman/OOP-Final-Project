/*	Author: Scott Upman
* 
*	Program Description: The project was inspired by MMORPG's to create a login system, a "database" to save progress, and to implement
*						 battle mechanics that are similar to turn-based combat. The program prompts the user to enter an account or to register an account.
*						 The program searches for the account within a text file that stores data about the account. Exceptions, such as logging into nonexisting accounts,
*						 are handled by prompting the user to enter valid input. When the user successfully logs in, they are able to select a character or create a new character
						 to add to their account. Whether the user made an account or has an existing account, the user is brought to the battle phase where there is a boss to defeat.
						 A user interface shows the boss's health points and the character's stats in order to keep track of the player's stats that will be modified.
*						 The boss scales with the player level, therefore the boss's stats are updated each time the player defeats the boss in order to increase complexity and difficulty
*						 When the user has finally been defeated, an output file is written to with the player's account info and is opened as the input file for the next time
*						 the program is ran.
* 
*/

#include <fstream>
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"
#include "Boss.h"
#include "Account.h"
#include "FileManager.h"
#include "GameManager.h"
#include <stdlib.h>
#include "Helper.h"

using namespace std;
const vector<int> SP_COSTS{ 1,5,10 };	// Constant vector that holds the SP cost for each attack (basic, secondary, final)

int main()
{	
	srand(time(nullptr));

	// Initialize pointers for an account and a character
	Account* account = NULL;	
	Character* character = NULL;
	ifstream infile("Accounts.txt");	// Input file to read from
	ofstream outfile("AccountsTemp.txt");	// Temporary file that will be written to and then renamed back to the name of the input file
		
	cout << "-----------AUTO BOSS GENERATOR-----------" << '\n' << endl;
	cout << "1. Login" << "\t2. Register\n" << endl;
	cout << "Select your choice (1-2): ";
	int selection;
	cin >> selection;
	Helper::validate_menu_select(selection);
	system("clear");

	if (selection == 1) // If user wants to login
	{
		string username, password;
		
		// User input
		Helper::prompt_user(username, password);

		// Search for the account
		bool account_exists = FileManager::search_account(infile, username, password);
		infile.seekg(0);	// Sets streampos back to beginning of file
		while (!account_exists)
		{
			cout << "The username or password is incorrect\n" << endl;
			Helper::prompt_user(username, password);
			account_exists = FileManager::search_account(infile, username, password);
			infile.seekg(0);								// Set streampos
		}
		account = new Account();							// Dynamically allocates memory block and stores account object in memory
		FileManager::set_file_position(infile, username);	// Sets the streampos back to the beginning of the line with the inputted username and password.
		infile >> *account;									// Read the contents of the file into the account object
		system("clear");

		// Prompt an option to select or create a character
		cout << "1. Select a character\t" << "2. Create a character\n" << endl;
		cout << "Select your choice: ";
		int choice;
		cin >> choice;
		Helper::validate_character_prompt(choice);

		if (choice == 1)		// User selects a character
		{
			account->display_characters();
			character = Helper::select_character(account);
			
		}
		else if (choice == 2)	// User creates a character with an existing account
		{
			system("clear");
			Helper::create_character(character, account);
		}		
	}
	else if (selection == 2)	// If user wants to register
	{
		cout << "\nWelcome to the game! Please create your credentials" << endl;
		string username, password;
		Helper::prompt_user(username, password);

		// Search for username
		bool is_taken = FileManager::search_username(infile, username);
		infile.seekg(0);		// Set streampos back to beginning
		while (is_taken)
		{
			cout << "Username is taken, please enter a different username\n";
			Helper::prompt_user(username, password);
			is_taken = FileManager::search_username(infile, username);
			infile.seekg(0);
		}	
		account = new Account(username, password);	// Dynamically allocate memory passing username and password into the constructor of Account class
		system("clear");
		Helper::create_character(character, account);
	}
	system("clear");
	
	// Game
	while(GameManager::get_game_over() == false)	// Loop as long as it's not game over
	{
		// Each iteration, instantiate a boss
		Boss boss(*character);
		while(boss.get_HP() > 0)
		{
			GameManager::display_combat(*character, boss);	// Displays User Interface
			int selection;
			cin >> selection;
			Helper::validate_attack_selection(selection);

			while (character->get_SP() < SP_COSTS[selection - 1]) // Determines if the player has enough SP to use the skill
			{
				cout << "\nNot enough SP!\n" << endl;
				cout << "Enter a different attack: ";
				cin >> selection;
				Helper::validate_attack_selection(selection);
			} 
			
			system("clear");
			if (selection == 1) { character->attack(boss); }					// Performs basic attack
			else if (selection == 2) { character->secondary_attack(boss); }		// Performs secondary attack
			else if (selection == 3) { character->final_attack(boss); }			// Performs final attack
			GameManager::regen_SP(*character);									// Generates a random value from 2-5 and adds the value to character's SP stat.
			
			if (boss.get_HP() <= 0)		// When boss's hp is at or below 0 (dead)
			{				
				GameManager::level_up(*character);
				continue;
			}			
			// Boss attacks
			boss.attack(*character);
			if (character->get_HP() <= 0)	// When character's hp is at or below 0 (dead)
			{
				system("clear");
				cout << "\nYou died! Game Over!" << endl;
				GameManager::set_game_over(true);	
				break;
			}
		}
	}
	// End of game
	infile.seekg(0); // Sets streampos back to beginning of file
	bool account_exists = FileManager::search_username(infile, account->get_username());
	infile.seekg(0);
	string line;
	StatsTemp::load_stats(*character);	// Load the stats into the character object
	if (account_exists)
	{
		// Replace the line in the file with the modified account
		while (getline(infile, line))
		{
			stringstream ss;
			string user_temp;
			ss.str(line);
			ss.clear();
			ss >> user_temp;
			if (user_temp == account->get_username())	// Writes entire account info to the output file
			{
				outfile << *account;
			}
			else  // Writes entire existing line from input file to the output file
			{
				outfile << line;	
				outfile << '\n';
			}				
		}		
	}	
	else // When account doesn't exist
	{
		while (getline(infile, line))
		{			
			// Write entire existing data to output file
			outfile << line;	
			outfile << '\n';
		}		
		// Add the account info to the bottom of output file
		outfile << *account;
	} 	
	infile.close();
	remove("Accounts.txt");	// Delete the initial input file
	outfile.close();
	rename("AccountsTemp.txt", "Accounts.txt");	// Temp file is now the input file for next time program runs.

	// Free the memory allocated in account pointer
	delete account;
}



