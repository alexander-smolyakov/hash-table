#include <hash_table.hpp>
#include <example_app/account.hpp>

const size_t baseSize = 10;

int main() {
  HashTable<baseSize, string, Account> AccountBase;

  Account inputData, testInsert;

  inputData.nick = "test";
  inputData.pass = "pass";

  for (size_t i = 0; i < baseSize; ++i) {
    AccountBase.Insert(inputData.nick, inputData);
  } 

  AccountBase.PrintTable("[1]_table_init.txt");
  AccountBase.Remove(6);
  AccountBase.PrintTable("[2]_table_remove.txt");

  return 0;
}
