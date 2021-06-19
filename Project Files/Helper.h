#ifndef HELPER_H
#define HELPER_H

#include "Account.h"

class Helper
{
public:
	static void validate_attack_selection(int& selection);
	static void validate_role_selection(int& selection);
	static void create_character(Character*& character, Account* account);
	static void prompt_user(string& username, string& password);
	static Character* select_character(Account* account);
	static void validate_menu_select(int& selection);
	static void validate_character_prompt(int& choice);
};
#endif

