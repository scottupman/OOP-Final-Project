#ifndef CHARACTER_H
#define CHARACTER_H

class Boss;

#include <string>
#include <iostream>

using namespace std;
class Character
{	
protected:
	int HP = 0, ATK = 0, DEF = 0, MP = 0, level = 0, SP = 0;
	string name, role;
	virtual void initialize_base_stats() {}
public:
	// Getters
	int get_HP() { return HP; }
	int get_ATK() { return ATK; }
	int get_DEF() { return DEF; }
	int get_MP() { return MP; }
	int get_level() { return level; }
	int get_SP() { return SP; }
	string get_name() { return name; }
	string get_role() { return role; }

	// Setters
	void set_HP(int HP) { this->HP = HP; }
	void set_ATK(int ATK) { this->ATK = ATK; }
	void set_DEF(int DEF) { this->DEF = DEF; }
	void set_MP(int MP) { this->MP = MP; }
	void set_SP(int SP) { this->SP = SP; }
	void set_level(int level) { this->level = level; }
	
	void display_stats() 
	{
		cout << "1. HP: " << HP << '\n' << "2. ATK: " << ATK << '\n' << "3. DEF: " << DEF << '\n' << "4. MP: " << MP << '\n' << "5. SP: " << SP << endl;
	}
	virtual void display_attacks() {}	
	virtual void attack(Boss& boss) {}
	virtual void secondary_attack(Boss& boss){}
	virtual void final_attack(Boss& boss){}
	
};
#endif
