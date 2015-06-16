#pragma once
#include "Patron.h"
class Adult :
	public Patron
{
	static const int MaxCheckedOut = 6;
public:
	Adult(std::string who);
	Adult(std::istream& in);
	~Adult();
	PatronType getType() override
	{ return ADULT; }
	void printTo(std::ostream& out);
};

