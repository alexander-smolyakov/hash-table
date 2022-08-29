#include <hash_table.hpp>

#include "include/account.hpp"
#include "include/profile.hpp"
#include <fmt/format.h>

const size_t baseSize = 10;

int main() {
  HashTable<baseSize, string, Account> AccountBase;

  Account inputData;

  for (size_t i = 0; i < baseSize; ++i) {
    inputData.nick = fmt::format("nick_{0}", i);
    inputData.pass = fmt::format("pass_{0}", i);
    AccountBase.Insert(inputData.nick, inputData);
  }

  AccountBase.PrintTable("[1]_table_init.txt");
  AccountBase.Remove(6);
  AccountBase.PrintTable("[2]_table_remove.txt");

  return 0;
}
