#ifndef GAMEMANAGER_H
#define GAMEMANGER_H

#include "Character.h"
#include "StatsTemp.h"
#include "Boss.h"
#include <iomanip>
#include <vector>
class GameManager
{
private:
	static bool game_over;	// When true, ends the program
	static void update_stats(Character& character);	// Helper function to level_up() function
public:
	static void level_up(Character& character);		
	static void set_game_over(bool end_game) { game_over = end_game; }
	static bool get_game_over(){ return game_over; }
	static void regen_SP(Character& character);
	static void display_combat(Character& character, Boss& boss);
};
#endif