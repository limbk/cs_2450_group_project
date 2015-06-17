#include "stdafx.h"
#include "DebugMedia.h"


DebugMedia::DebugMedia(std::string theTitle, int dueIn)
	:DebugItem(theTitle, dueIn)
{
}

DebugMedia::DebugMedia(std::istream& in)
	: DebugItem(in)
{
}

DebugMedia::~DebugMedia()
{
}
