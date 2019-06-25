#include <vector>
#include <string>
#include <iostream>

#include "hash_table.h"
#include "struct_profile.h"
#include "stuct_account.h"

using namespace std;

int main()
{
	HashTable<20, int, Account> Table_Accounts;
	HashTable<40, string, Profile> Table_Profiles;

	return 0;
}