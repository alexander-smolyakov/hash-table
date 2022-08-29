#ifndef PROFILE_HPP
#define PROFILE_HPP

#include <fmt/format.h>

#include <iostream>
#include <string>

struct Profile {
  std::string firstName;
  std::string lastName;
  int id;
};

std::ostream& operator<<(std::ostream& stream, Profile const& val) {
  stream << fmt::format("first_name = {0}, second_name = {1}, id = {3}",
                        val.firstName, val.lastName, val.id);
  return stream;
}

bool operator==(Profile const& left, Profile const& right) {
  return ((left.firstName == right.firstName) &&
          (left.lastName == right.lastName) && (left.id == right.id));
}

namespace std {
template <>
struct hash<Profile> {
 public:
  size_t operator()(Profile const& val) const {
    size_t h1 = hash<string>()(val.firstName);
    size_t h2 = hash<string>()(val.lastName);
    return h1 + (h2 << 1) + val.id;
  }
};
}  // namespace std

#endif  // PROFILE_HPP
