#include "custom_types.hpp"
#include "hash-table/hash_table.hpp"

const size_t baseSize = 10;

int main() {
  HashTable<baseSize, string, Account> AccountBase;

  Account inputData, testInsert;
  string nick, pass;

  ifstream nickList("tests/[0]_init_list_nick.txt");
  ifstream passList("tests/[0]_init_list_pass.txt");

  int count = 0;

  while (count != baseSize) {
    getline(nickList, nick);
    getline(passList, pass);

    inputData.nick = nick;
    inputData.pass = pass;

    AccountBase.Insert(inputData.nick, inputData);

    count++;
  }

  passList.close();
  nickList.close();

  AccountBase.PrintTable("tests/[1]_table_init.txt");
  AccountBase.Remove(6);
  AccountBase.PrintTable("tests/[2]_table_remove.txt");

  ofstream searchLog("tests/[3]_table_search.txt");

  ifstream keyList("tests/[0]_init_list_nick.txt");
  count = 0;
  string buffer;

  while (count != baseSize) {
    getline(keyList, buffer);

    searchLog << "key = " << buffer
              << " | index = " << AccountBase.Search(buffer) << endl;

    count++;
  }

  searchLog.close();
  keyList.close();
  testInsert.nick = "insertTest";
  testInsert.pass = "insertTest";
  AccountBase.Insert(testInsert.nick, testInsert);
  AccountBase.PrintTable("tests/[4]_table_insert.txt");

  return 0;
}
