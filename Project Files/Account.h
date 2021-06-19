#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <vector>
#include <sstream>
#include "Character.h"
#include "Warrior.h"
#include "Archer.h"
#include "Mage.h"
class Account
{
private:
	string username, password;
	vector<Character*> characters;	// Holds character pointers associated with the username and password inputted from the user
public:
	~Account();
	Account() {}
	Account(string username, string password) 
	{
		this->username = username;
		this->password = password;
	};
	void operator+ (Character* character){ characters.push_back(character); }	// Overload operator that adds the character pointer to the vector

	string get_username() { return username; }
	string get_password() { return password; }
	vector<Character*> get_characters(){ return characters; }
	
	void display_characters();
	friend ostream& operator<< (ostream& out, Account& account);
	friend istream& operator>> (istream& in, Account& account);

};
#endif

