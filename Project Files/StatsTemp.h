#ifndef STATSTEMP_H
#define STATSTEMP_H

#include "Character.h"
class StatsTemp
{
private:
	static int HP_temp, ATK_temp, DEF_temp, MP_temp, SP_temp;	// Will act as temporary data values for the stats
public:
	static void store_stats(Character& character);
	static void load_stats(Character& character);
	static int get_SP() { return SP_temp; }
};
#endif

