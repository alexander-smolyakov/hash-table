#ifndef CUSTOM_TYPES_H
#define CUSTOM_TYPES_H
#include <iostream>
#include <string>
using namespace std;

struct Account
{
	string nick;
	string pass;
};

struct ProFile 
{
	string firstName;
	string lastName;
	int id;
};

ostream& operator<< (ostream &stream, const Account &acc)
{
	stream << acc.nick << ", " << acc.pass;
	return stream;
}

ostream& operator<< (ostream &stream, const ProFile &pro)
{
	stream << pro.firstName << " " << pro.lastName << " (" << pro.id << ")"; 
	return stream;
}

bool operator== (const Account& left, const Account& right)
{
	if ((left.nick == right.nick) && (left.pass == right.pass))
		return true;
	else
		return false;
}

bool operator== (const ProFile& left, const ProFile& right)
{
	if ((left.firstName == right.firstName) && (left.lastName == right.lastName) && (left.id == right.id))
		return true;
	else
		return false;
}

namespace std
{
    template<>
    struct hash<Account>
    {
		public:
		size_t operator()(Account const& acc) const 
		{
			size_t h1 = hash<string>()(acc.nick);
			size_t h2 = hash<string>()(acc.pass);
			return h1 ^ (h2 << 1);
		}
    };

	template<>
    struct hash<ProFile>
	{
		public:
		size_t operator()(ProFile const& pro) const 
		{
			size_t h1 = hash<string>()(pro.firstName);
			size_t h2 = hash<string>()(pro.lastName);
			return h1 + (h2 << 1) + pro.id;
		}
    };
}
#endif