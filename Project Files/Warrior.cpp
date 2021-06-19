#include "Warrior.h"
// Helper function for instantiating the stats when the object is created. Overrides the virtual function in Character class
void Warrior::initialize_base_stats()	
{
	HP = 10;
	ATK = 5;
	DEF = 10;
	MP = 0;
	level = 1;
	SP = 20;
}
// Constructor for when the character is retrieved when reading from the "accounts.txt" file
Warrior::Warrior(string name, string role, int level, int SP, int ATK, int DEF, int HP, int MP)
{
	this->name = name;
	this->role = role;
	this->level = level;
	this->SP = SP;
	this->ATK = ATK;
	this->DEF = DEF;
	this->HP = HP;
	this->MP = MP;

	StatsTemp::store_stats(*this);	// Temporarily stores the stats based off of initialization of the object that was read from the file.
}
// Constructor for creating a warrior
Warrior::Warrior(string name)
{
	this->name = name;
	this->role = "Warrior";

	initialize_base_stats();

	StatsTemp::store_stats(*this);	// Temporarily stores the stats based off of initialization of the object.
}
// Overrides virtual function declared in Character class, utilizes polymorphism
void Warrior::display_attacks() 
{
	cout << "1. " << basic_attack << " (SP cost = 1)" << '\n'
		<< "2. " << special_attack << " (SP cost = 5)" << '\n'
		<< "3. " << ultimate_attack << " (SP cost = 10)" << endl;
}
// Function modifies the boss health with a damage formula
void Warrior::attack(Boss& boss)
{
	int damage = ATK + (rand() % 6);	// Margin of random number is between 0 and 5
	boss.set_HP(boss.get_HP() - damage);
	this->SP -= 1;
	cout << "\nyou dealt " << damage << " damage" << endl;
}
// Function modifies the boss health with a damage formula
void Warrior::secondary_attack(Boss& boss) 
{
	int damage = (ATK + (rand() % 6)) * 1.2;	// Margin of random number is between 0 and 5
	boss.set_HP(boss.get_HP() - damage);
	this->SP -= 5;
	cout << "\nyou dealt " << damage << " damage" << endl;
}
// Function modifies the boss health with a damage formula
void Warrior::final_attack(Boss& boss) 
{
	int damage = (ATK + (rand() % 6)) * 1.5;	// Margin of random number is between 0 and 5
	boss.set_HP(boss.get_HP() - damage);
	this->SP -= 10;
	cout << "\nyou dealt " << damage << " damage" << endl;
}
