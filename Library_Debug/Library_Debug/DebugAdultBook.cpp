#include "stdafx.h"
#include "DebugAdultBook.h"


DebugAdultBook::DebugAdultBook(std::string theTitle)
	:DebugBook(theTitle, DUE)
{
	
}
DebugAdultBook::DebugAdultBook(std::istream& in)
	: DebugBook(in)
{
	
}
DebugAdultBook::~DebugAdultBook()
{
	
}
void DebugAdultBook::printStatusTo(std::ostream& out)
{
	out << "Adult Book";
	DebugItem::printStatusTo(out);
}

void DebugAdultBook::printAsAvailableTo(std::ostream& out)
{
	out << "Adult Book ";
	DebugItem::printAsAvailableTo(out);
}
