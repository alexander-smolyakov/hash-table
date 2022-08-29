#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "math.h"
#include <fstream>
#include <string>

using namespace std;

template <size_t S, typename K, typename T> class HashTable {
public:
  HashTable();
  HashTable(const HashTable &);
  ~HashTable();
  HashTable &operator=(const HashTable &);

  bool Insert(K, T);
  int Search(K);
  void Remove(int);

  void PrintTable(string);

private:
  // methods
  int hashFunction(K);
  int linearInvestigation(size_t, size_t);
  // field
  enum cellStatus { Empty, Busy, Delete };
  struct cell {
    cellStatus status;
    K key;
    T data;
  };
  cell *hashTable_;
};

template <size_t S, typename K, typename T> HashTable<S, K, T>::HashTable() {
  hashTable_ = new cell[S];

  for (size_t count = 0; count < S; count++)
    hashTable_[count].status = Empty;
}

template <size_t S, typename K, typename T>
HashTable<S, K, T>::HashTable(const HashTable &copy) {
  hashTable_ = new cell[S];

  for (size_t count = 0; count < S; count++)
    hashTable_[count] = copy.hashTable_[count];
}

template <size_t S, typename K, typename T> HashTable<S, K, T>::~HashTable() {
  delete[] hashTable_;
}

template <size_t S, typename K, typename T>
HashTable<S, K, T> &HashTable<S, K, T>::operator=(const HashTable &leftValue) {
  if (this != &leftValue)
    for (size_t count = 0; count < S; count++)
      hashTable_[count] = leftValue.hashTable_[count];

  return *this;
}

template <size_t S, typename K, typename T>
void HashTable<S, K, T>::PrintTable(string fileName) {
  ofstream saveFile(fileName);
  saveFile << "[index] = (status) <key, [data]>\n";

  for (size_t count = 0; count < S; count++) {
    saveFile << "[" << count << "] (" << hashTable_[count].status << ") <("
             << hashFunction(hashTable_[count].key) << " | "
             << hashTable_[count].key << "), [" << hashTable_[count].data
             << "]>\n";
  }

  saveFile.close();
}

template <size_t S, typename K, typename T>
int HashTable<S, K, T>::hashFunction(K key) {
  const double A = (sqrt(5) - 1) / 2;

  hash<K> hash;

  int value = (int)floor(S * (hash(key) * A - floor(hash(key) * A)));

  return value;
}

template <size_t S, typename K, typename T>
int HashTable<S, K, T>::linearInvestigation(size_t hashValue, size_t count) {
  return (hashValue + count) % S;
}

template <size_t S, typename K, typename T>
bool HashTable<S, K, T>::Insert(K key, T data) {
  size_t count(0), index(0);
  size_t hashValue = hashFunction(key);

  do {
    index = linearInvestigation(hashValue, count);

    if (hashTable_[index].status != Busy) {
      hashTable_[index].status = Busy;
      hashTable_[index].key = key;
      hashTable_[index].data = data;

      return true;
    } else
      count++;
  } while (count != S);

  return false;
}

template <size_t S, typename K, typename T>
int HashTable<S, K, T>::Search(K key) {
  int index(0), count(0);
  size_t hashValue = hashFunction(key);

  do {
    index = linearInvestigation(hashValue, count);

    if (hashTable_[index].status == Busy) {
      if (hashTable_[index].key == key)
        return index;
    }

    count++;
  } while (hashTable_[index].status != Empty && count != S);

  return -1;
}

template <size_t S, typename K, typename T>
void HashTable<S, K, T>::Remove(int index) {
  if (hashTable_[index].status != Empty) {
    hashTable_[index].status = Delete;
    int j(index);
    cell BackUpRecrod;

    while (true) {
      j = (j + 1) % S;

      if (hashTable_[j].status != Busy)
        break;
      else {
        size_t k = hashFunction(hashTable_[j].key);

        if ((j > index && (k <= index || k > j)) ||
            (j < index && (k <= index && k > j))) {
          BackUpRecrod = hashTable_[index];
          hashTable_[index] = hashTable_[j];
          hashTable_[j] = BackUpRecrod;
          index = j;
        }
      }
    }
  }
}

//#include "hash_table_impl.h"
#endif