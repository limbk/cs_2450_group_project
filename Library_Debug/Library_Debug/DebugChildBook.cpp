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
void DebugChildBook::printStatusTo(std::ostream& out)
{
	out << "Childrens Book";
	DebugItem::printStatusTo(out);
}

void DebugChildBook::printAsAvailableTo(std::ostream& out)
{
	out << "Childrens Book ";
	DebugItem::printAsAvailableTo(out);
}
