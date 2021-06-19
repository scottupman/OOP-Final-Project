#ifndef ARCHER_H
#define ARCHER_H

#include "Character.h"
#include "StatsTemp.h"
#include "Boss.h"

class Archer : public Character
{
private:
	string basic_attack = "Quickdraw";	// 1 SP
	string special_attack = "Bulletstorm";	// 5 SP
	string ultimate_attack = "Rain of Arrows";	// 10 SP
	void initialize_base_stats() override;	// Helper function for instantiating the stats when the object is created.

public:
	Archer(string name, string role, int level, int SP, int ATK, int DEF, int HP, int MP);
	Archer(string name);

	void display_attacks();
	
	// Functions modify the health of the boss using a damage formula
	void attack(Boss& boss);
	void secondary_attack(Boss& boss);
	void final_attack(Boss& boss);
	
};
#endif

