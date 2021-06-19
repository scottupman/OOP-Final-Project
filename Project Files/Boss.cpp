#include "Boss.h"

// Function modifies the character's health and displays the damage dealt.
void Boss::attack(Character& character) 
{
	cout << "The boss attacked " << character.get_name() << "!" << endl;
	double damage = 2 * ATK - (character.get_DEF() * .1);
	damage = round(damage);
	character.set_HP(character.get_HP() - damage);
	cout << "\n" << "The boss dealt " << static_cast<int>(damage) << " damage" << endl;
}
