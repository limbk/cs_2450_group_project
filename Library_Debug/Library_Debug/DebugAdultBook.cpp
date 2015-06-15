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
