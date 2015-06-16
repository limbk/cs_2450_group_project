#pragma once
#include "DebugPatron.h"
class DebugChild :
	public DebugPatron
{
	static const int MaxCheckedOut = 3;
public:
	DebugChild(std::string who);
	DebugChild(std::istream& in);
	~DebugChild();
	PatronType getType(){ return CHILD; }
	void printTo(std::ostream& out);
};

