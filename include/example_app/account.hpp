#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
#include <string>

struct Account {
  std::string nick;
  std::string pass;
};

std::ostream& operator<<(std::ostream& stream, Account const& acc) {
  stream << acc.nick << ", " << acc.pass;
  return stream;
}

bool operator==(Account const& left, Account const& right) {
  return ((left.nick == right.nick) && (left.pass == right.pass));
}

namespace std {
template <>
struct hash<Account> {
 public:
  size_t operator()(Account const& acc) const {
    size_t h1 = hash<string>()(acc.nick);
    size_t h2 = hash<string>()(acc.pass);
    return h1 ^ (h2 << 1);
  }
};
}  // namespace std

#endif  // ACCOUNT_HPP
