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
