#ifndef STUCT_ACCOUNT_H
#define STUCT_ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;


struct Account
{
	string nick;
	string pass;
};

ostream& operator<< (ostream& stream, const Account& acc)
{
	stream << acc.nick << ", " << acc.pass;
	return stream;
}


bool operator== (const Account& left, const Account& right)
{
	if ((left.nick == right.nick) && (left.pass == right.pass))
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
}

#endif