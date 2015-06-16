#pragma once
#include "DebugItem.h"
class DebugBook : public DebugItem
{
public:
	DebugBook(std::string theTitle, int dueIn = 6);
	DebugBook(std::istream& in);
	~DebugBook();
};

