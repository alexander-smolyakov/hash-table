#ifndef HASHTABLE_H
#define HASHTABLE_H

template <size_t S, typename K, typename T>
class HashTable
{
public:

	HashTable();
	HashTable(const HashTable&);
	~HashTable();
	HashTable& operator = (const HashTable&);

	bool Insert(K, T);
	int Search(K);
	void Remove(int);

private:
	// methods
	int hashFunction(K);
	int linearInvestigation(size_t, size_t);

	// fields
	enum cellStatus { Empty, Busy, Delete };
	struct cell { cellStatus status; K key; T data; };
	cell* hashTable_;
};

#include "HashTable_Implementation.h"
#endif