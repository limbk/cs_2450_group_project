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

