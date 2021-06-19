#include "Archer.h"
// Helper function for instantiating the stats when the object is created. Overrides the virtual function in Character class
void Archer::initialize_base_stats() 
{
	HP = 10;
	ATK = 10;
	DEF = 2;
	MP = 0;
	level = 1;
	SP = 20;
}
// Constructor for when the character is retrieved when reading from the "accounts.txt" file
Archer::Archer(string name, string role, int level, int SP, int ATK, int DEF, int HP, int MP)
{
	this->name = name;
	this->role = role;
	this->level = level;
	this->SP = SP;
	this->ATK = ATK;
	this->DEF = DEF;
	this->HP = HP;
	this->MP = MP;

	StatsTemp::store_stats(*this);	// Temporarily stores the stats based off of initialization of the object read from the file.
}
// Constructor for creating an Archer
Archer::Archer(string name)
{
	this->name = name;
	this->role = "Archer";

	initialize_base_stats();

	StatsTemp::store_stats(*this);	// Temporarily stores the stats based off of initialization of the object.
}
// Overrides virtual function declared in Character class, utilizes polymorphism
void Archer::display_attacks() 
{
	cout << "1. " << basic_attack << " (SP cost = 1) " << '\n'
		<< "2. " << special_attack << " (SP cost = 5)" << '\n'
		<< "3. " << ultimate_attack << " (SP cost = 10)" << endl;
}
// Function modifies the boss health with a damage formula
void Archer::attack(Boss& boss)
{
	int damage = (ATK + (rand() % 6)) * 1.1;	// Margin of random number is between 0 and 5
	boss.set_HP(boss.get_HP() - damage);
	this->SP -= 1;
	cout << "\nyou dealt " << damage << " damage" << endl;
}
// Function modifies the boss health with a damage formula
void Archer::secondary_attack(Boss& boss)
{
	int damage = (ATK + (rand() % 6)) * 1.3;	// Margin of random number is between 0 and 5
	boss.set_HP(boss.get_HP() - damage);
	this->SP -= 5;
	cout << "\nyou dealt " << damage << " damage" << endl;
}
// Function modifies the boss health with a damage formula
void Archer::final_attack(Boss& boss)
{
	int damage = (ATK + (rand() % 6)) * 1.8;	// Margin of random number is between 0 and 5
	boss.set_HP(boss.get_HP() - damage);
	this->SP -= 10;
	cout << "\nyou dealt " << damage << " damage" << endl;
};