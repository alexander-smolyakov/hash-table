#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

template <size_t S, typename K, typename T>
class HashTable 
{		
	public:

		HashTable ();
		HashTable (const HashTable&);
		~HashTable ();
		HashTable& operator = (const HashTable&);
		
		bool hashTable_Insert (K, T);
		int hashTable_Search (K);
		void hashTable_Remove (int);

	// for tests 
		K getCellKey (size_t);
		T getCellData (size_t);
		string getCellStatus (size_t);

		void printHashTable (string);
	private:
	// methods
		int hashFunction (K);
		int linearInvestigation (K, size_t);	
	// field
		struct cell {string status; K key; T data;};
		cell* hashTable_;
};

#include "hash_table_impl.h"
#endif