#include "stdafx.h"
#include "DebugChildBook.h"


DebugChildBook::DebugChildBook(std::string theTitle)
	:DebugBook(theTitle, DUE)
{
}

DebugChildBook::DebugChildBook(std::istream& in)
	: DebugBook(in)
{
	
}

DebugChildBook::~DebugChildBook()
{
}
