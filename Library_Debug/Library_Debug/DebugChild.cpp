#include "stdafx.h"
#include "DebugChild.h"


DebugChild::DebugChild(std::string who)
	:DebugPatron(who, MaxCheckedOut)
{
}

DebugChild::DebugChild(std::istream& in)
	: DebugPatron(in)
{
	
}

DebugChild::~DebugChild()
{
}
