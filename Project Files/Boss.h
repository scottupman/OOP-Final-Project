#ifndef BOSS_H
#define BOSS_H

#include "Character.h"
#include <math.h>
class Boss
{
private:
	int HP, ATK, level;
public:
	// Constructor passes character object in order to load the stats of the boss
	Boss(Character& character)
	{
		this->level = character.get_level();
		this->HP = 20 * level - 10 * (level - 1);	// Boss HP goes up by 10 for each level of the character
		this->ATK = level;
	}
	int get_HP() { return HP; }
	int get_ATK() { return ATK; }
	void set_HP(int HP) { this->HP = HP; }
		
	void attack(Character& character);
	
};
#endif