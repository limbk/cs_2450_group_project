#pragma once
#include "Patron.h"
class Child :
	public Patron
{
	static const int MaxCheckedOut = 3;
public:
	Child(std::string who);
	Child(std::istream& in);
	~Child();
	PatronType getType(){ return CHILD; }
	void printTo(std::ostream& out);
};

