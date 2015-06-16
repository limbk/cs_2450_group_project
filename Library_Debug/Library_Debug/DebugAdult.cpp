#include "stdafx.h"
#include "DebugAdult.h"


DebugAdult::DebugAdult(std::string who)
	:DebugPatron(who, MaxCheckedOut)
{
}

DebugAdult::DebugAdult(std::istream& in)
	: DebugPatron(in)
{
}

DebugAdult::~DebugAdult()
{
}

void DebugAdult::printTo(std::ostream& out)
{
	out << "Adult ";
	DebugPatron::printTo(out);
}
