#include "stdafx.h"
#include "DebugVHS.h"


DebugVHS::DebugVHS(std::string theTitle)
	:DebugMedia(theTitle, DUE)
{
}


DebugVHS::DebugVHS(std::istream& in)
	: DebugMedia(in)
{
}

DebugVHS::~DebugVHS()
{
}

void DebugVHS::printStatusTo(std::ostream& out)
{
	out << "VHS ";
	DebugItem::printStatusTo(out);
}

void DebugVHS::printAsAvailableTo(std::ostream& out)
{
	out << "VHS ";
	DebugItem::printAsAvailableTo(out);
}