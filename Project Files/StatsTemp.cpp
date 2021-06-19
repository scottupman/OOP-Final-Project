#include "StatsTemp.h"
int StatsTemp::HP_temp = 0;
int StatsTemp::ATK_temp = 0;
int StatsTemp::DEF_temp = 0;
int StatsTemp::MP_temp = 0;
int StatsTemp::SP_temp = 0;

// Stores the stats into their respective variables in order to allow the character to start back to their initial stats
void StatsTemp::store_stats(Character& character)
{
	HP_temp = character.get_HP();
	ATK_temp = character.get_ATK();
	DEF_temp = character.get_DEF();
	MP_temp = character.get_MP();
	SP_temp = character.get_SP();
}
// Sets the stats to the values of the temp variables.
void StatsTemp::load_stats(Character& character)
{
	character.set_HP(HP_temp);
	character.set_ATK(ATK_temp);
	character.set_DEF(DEF_temp);
	character.set_MP(MP_temp);
	character.set_SP(SP_temp);
}