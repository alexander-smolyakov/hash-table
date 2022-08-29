#ifndef PROFILE_HPP
#define PROFILE_HPP

#include <iostream>
#include <string>

struct Profile {
  std::string firstName;
  std::string lastName;
  int id;
};

std::ostream& operator<<(std::ostream& stream, Profile const& pro) {
  stream << pro.firstName << " " << pro.lastName << " (" << pro.id << ")";
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
  size_t operator()(Profile const& pro) const {
    size_t h1 = hash<string>()(pro.firstName);
    size_t h2 = hash<string>()(pro.lastName);
    return h1 + (h2 << 1) + pro.id;
  }
};
}  // namespace std

#endif  // PROFILE_HPP
