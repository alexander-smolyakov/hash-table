#ifndef HASHTABLE_H
#define HASHTABLE_H

// A = (sqrt(5) - 1) / 2
const double A = 0.6180339887498948;

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