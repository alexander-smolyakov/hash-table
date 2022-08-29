#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <fmt/format.h>

#include <iostream>
#include <string>

struct Account {
  std::string nick;
  std::string pass;
};

std::ostream& operator<<(std::ostream& stream, Account const& val) {
  return stream << fmt::format("nick = {0}, pass = {1}", val.nick, val.pass);
}

bool operator==(Account const& left, Account const& right) {
  return ((left.nick == right.nick) && (left.pass == right.pass));
}

namespace std {
template <>
struct hash<Account> {
 public:
  size_t operator()(Account const& val) const {
    size_t h1 = hash<string>()(val.nick);
    size_t h2 = hash<string>()(val.pass);
    return h1 ^ (h2 << 1);
  }
};
}  // namespace std

#endif  // ACCOUNT_HPP
