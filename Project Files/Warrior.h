#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"
#include "StatsTemp.h"
#include "Boss.h"

class Warrior : public Character
{
private:
	string basic_attack = "Slash";	// 1 SP
	string special_attack = "Heavy Slash";	// 5 SP
	string ultimate_attack = "Meteor Slash";	// 10 SP
	void initialize_base_stats() override;	// Helper function for instantiating the stats when the object is created.

public:
	Warrior(string name, string role, int level, int SP, int ATK, int DEF, int HP, int MP);
	Warrior(string name);


	void display_attacks();
		
	// Functions modify the health of the boss using a damage formula
	void attack(Boss& boss);
	void secondary_attack(Boss& boss);
	void final_attack(Boss& boss);	
};
#endif
