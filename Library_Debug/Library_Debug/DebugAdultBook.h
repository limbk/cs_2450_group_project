#pragma once
#include "DebugBook.h"
class DebugAdultBook :
	public DebugBook
{
	static const int DUE = 14;
public:
	DebugAdultBook(std::string theTitle);
	DebugAdultBook(std::istream& in);
	~DebugAdultBook();
	ITEMTYPES getType(){ return ADULTBOOK; }
};

