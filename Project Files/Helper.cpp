#include "Helper.h"
void Helper::validate_attack_selection(int& selection)
{
	while (selection < 1 || selection > 3) // Validate selection
	{
		cout << "\nEnter an attack from 1-3: ";
		cin >> selection;
	}
}
void Helper::validate_role_selection(int& selection)
{
	while (selection < 1 || selection > 3) // Validate selection
	{
		cout << "\nEnter a role from 1-3: ";
		cin >> selection;
	}
}
// Function takes in a character pointer and account pointer to add the dynamically allocated character to the account
void Helper::create_character(Character*& character, Account* account)
{
	cout << "\nCreate your character!\n" << endl;
	cout << "Character name: ";
	string character_name;
	cin >> character_name;
	cout << "\nRoles" << endl;
	cout << "1. Warrior\n" << "2. Mage\n" << "3. Archer" << endl;
	cout << "\nSelect your role: ";

	int role;
	cin >> role;
	validate_role_selection(role);
	// Dynamically allocates the character pointer to a derived object
	if (role == 1) { character = new Warrior(character_name); }
	else if (role == 2) { character = new Mage(character_name); }
	else if (role == 3) { character = new Archer(character_name); }
	
	// Add the character to the account using the account's overload operator
	account->operator+(character);
}
void Helper::prompt_user(string& username, string& password)
{
	cout << "\nUsername: ";
	cin >> username;
	cout << "\nPassword: ";
	cin >> password;
}
// Function returns a pointer that is stored in the vector based on the user selection
Character* Helper::select_character(Account* account)
{
	cout << "\nSelect a character: ";
	int num;
	cin >> num;
	while (num < 1 || num > account->get_characters().size())	// Validate selection
	{
		cout << "\nInvalid entry, please try again: ";
		cin >> num;
	}
	vector<Character*> characters = account->get_characters();
	return characters[num - 1]; // num - 1 for index purposes
}
void Helper::validate_menu_select(int& selection)
{
	while (selection < 1 || selection > 2) // Validate selection
	{
		cout << "\nEnter 1. for login or 2 for register: ";
		cin >> selection;
	}
}
void Helper::validate_character_prompt(int& choice)
{
	while (choice < 1 || choice > 2)	// Validate selection
	{
		cout << "\nEnter either 1 to select a character or 2 to create a character: ";
		cin >> choice;
	}
}