#ifndef MAGE_H
#define MAGE_H

#include "Character.h"
#include "StatsTemp.h"
#include "Boss.h"
class Mage : public Character
{
private:
	string basic_attack = "Spellcast";	// 1 SP
	string special_attack = "Abysmal Spell";	// 5 SP
	string ultimate_attack = "Cataclysm";	// 10 SP
	void initialize_base_stats() override;	// Helper function for instantiating the stats when the object is created.
public:
	Mage(string name, string role, int level, int SP, int ATK, int DEF, int HP, int MP);
	Mage(string name);

	void display_attacks();
	
	// Functions modify the health of the boss using a damage formula
	void attack(Boss& boss);
	void secondary_attack(Boss& boss);
	void final_attack(Boss& boss);
	
};
#endif