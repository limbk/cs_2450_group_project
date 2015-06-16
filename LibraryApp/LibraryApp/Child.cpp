#include "stdafx.h"
#include "Child.h"


Child::Child(std::string who)
	:Patron(who, MaxCheckedOut)
{
}

Child::Child(std::istream& in)
	: Patron(in)
{
	
}

Child::~Child()
{
}

void Child::printTo(std::ostream& out)
{
	out << "Child ";
	Patron::printTo(out);
}