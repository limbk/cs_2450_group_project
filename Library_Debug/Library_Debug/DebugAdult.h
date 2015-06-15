#pragma once
#include "DebugPatron.h"
class DebugAdult :
	public DebugPatron
{
	static const int MaxCheckedOut = 6;
public:
	DebugAdult(std::string who);
	DebugAdult(std::istream& in);
	~DebugAdult();
	PatronType getType() override
	{ return ADULT; }
};

