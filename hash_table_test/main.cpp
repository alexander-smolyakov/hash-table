#include "hash_table\hash_table.h"
#include "custom_types\custom_types.h"

int main () 
{
	const size_t baseSize = 12;
	HashTable <baseSize, string, Account> AccountBase;
	Account inputData;

	ifstream nickList("nick.txt");
	ifstream passList("pass.txt");

	int count = 0;
	
	while (count != baseSize)
	{
		string nick, pass;
		getline(nickList, nick);
		getline(passList, pass);

		inputData.nick = nick;
		inputData.pass = pass;

		AccountBase.hashTable_Insert (inputData.nick,inputData);

		count++;
	}

	for (int i = 0; i < baseSize; i++)
		AccountBase.hashTable_Remove (i);

	AccountBase.printHashTable("test.txt");
	nickList.close();
	passList.close();

	system("pause");
	return EXIT_SUCCESS;
}