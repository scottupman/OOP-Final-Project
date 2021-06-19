#include "Account.h"

// Destructor deallocates the pointers in the vector
Account::~Account()
{
	for (Character* character : characters)
		delete character;
}
// Displays each object stored in vector of pointers
void Account::display_characters()
{
	int count = 0;
	for (Character* character : characters)
	{
		count++;
		cout << count << ".\t" << character->get_name() << '\t';
		cout << "Role: " << character->get_role() << '\t';
		cout << "Level: " << character->get_level() << endl;
	}	
}
// Overload operator write the contents in the account object to the output file
ostream& operator<< (ostream& out, Account& account)
{
	out << account.get_username() << '\t' << account.get_password();
	// Iterates through each character pointer and uses -> member access operator to accesss data members
	for (Character* character : account.characters)
		out << '\t' << character->get_name() << '\t' << character->get_role() << '\t' << character->get_level() << '\t'
		<< character->get_SP() << '\t' << character->get_ATK() << '\t' << character->get_DEF() << '\t' << character->get_HP()
		<< '\t' << character->get_MP();

	out << endl;
	return out;
}
// Overload operator stores contents from accounts.txt file into account object
istream& operator>> (istream& in, Account& account)
{
	//in >> account.username >> account.password;
	string line;
	stringstream ss;
	//while (getline(in, line, '\n'))
	//{
	getline(in, line);
	ss.str(line);
	ss.clear();
	
	// Variables will hold the data read from the file
	string name, role;
	int HP, ATK, DEF, MP, level, SP;
	ss >> account.username >> account.password;	// Get the username and password and store them
	while (ss >> name >> role >> level >> SP >> ATK >> DEF >> HP >> MP)	// These are the data members that will be stored into a vector that the Account class contains
	{
		// Instantiate a new pointer for every character that is read from the file and store it into the vector
		Character* character;
		if (role == "Warrior")
		{			
			character = new Warrior(name, role, level, SP, ATK, DEF, HP, MP);
			account.characters.push_back(character);
		}
		else if (role == "Mage")
		{
			character = new Mage(name, role, level, SP, ATK, DEF, HP, MP);
			account.characters.push_back(character);
		}
		else if (role == "Archer")
		{
			character = new Archer(name, role, level, SP, ATK, DEF, HP, MP);
			account.characters.push_back(character);
		}
	}
	
	return in;
}
