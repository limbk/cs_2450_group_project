#include "stdafx.h"
#include "DebugBook.h"





DebugBook::DebugBook(std::string theTitle, int dueIn)
	:DebugItem(theTitle, dueIn)
{
}

DebugBook::DebugBook(std::istream& in)
	:DebugItem(in)
{
}

DebugBook::~DebugBook()
{
}
