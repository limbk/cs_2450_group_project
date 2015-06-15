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
