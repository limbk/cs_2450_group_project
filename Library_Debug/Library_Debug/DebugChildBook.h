#pragma once
#include "DebugBook.h"
class DebugChildBook :
	public DebugBook
{
	static const int DUE = 7;
public:
	DebugChildBook(std::string theTitle);
	DebugChildBook(std::istream& in);
	~DebugChildBook();
	ITEMTYPES getType(){ return CHILDRENSBOOK; }
	void printStatusTo(std::ostream& out);
	void printAsAvailableTo(std::ostream& out);

};

