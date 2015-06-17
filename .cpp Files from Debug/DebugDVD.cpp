#include "stdafx.h"
#include "DebugDVD.h"


DebugDVD::DebugDVD(std::string theTitle)
	:DebugMedia(theTitle, DUE)
{
}

DebugDVD::DebugDVD(std::istream& in)
	: DebugMedia(in)
{
	
}

DebugDVD::~DebugDVD()
{
}

void DebugDVD::printStatusTo(std::ostream& out)
{
	out << "DVD ";
	DebugItem::printStatusTo(out);
}

void DebugDVD::printAsAvailableTo(std::ostream& out)
{
	out << "DVD ";
	DebugItem::printAsAvailableTo(out);
}