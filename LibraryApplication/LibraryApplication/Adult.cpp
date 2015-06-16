#include "stdafx.h"
#include "Adult.h"


Adult::Adult(std::string who)
	:Patron(who, MaxCheckedOut)
{
}

Adult::Adult(std::istream& in)
	: Patron(in)
{
}

Adult::~Adult()
{
}

void Adult::printTo(std::ostream& out)
{
	out << "Adult ";
	Patron::printTo(out);
}
