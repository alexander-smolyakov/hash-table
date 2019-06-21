#ifndef STRUCT_PROFILE_H
#define STRUCT_PROFILE_H

#include <iostream>
#include <string>
using namespace std;

struct Profile
{
	string firstName;
	string lastName;
	int id;
};

ostream& operator<< (ostream& stream, const Profile& pro)
{
	stream << pro.firstName << " " << pro.lastName << " (" << pro.id << ")";
	return stream;
}

bool operator== (const Profile& left, const Profile& right)
{
	if ((left.firstName == right.firstName) && (left.lastName == right.lastName) && (left.id == right.id))
		return true;
	else
		return false;
}

namespace std
{
	template<>
	struct hash<Profile>
	{
	public:
		size_t operator()(Profile const& pro) const
		{
			size_t h1 = hash<string>()(pro.firstName);
			size_t h2 = hash<string>()(pro.lastName);
			return h1 + (h2 << 1) + pro.id;
		}
	};
}

#endif