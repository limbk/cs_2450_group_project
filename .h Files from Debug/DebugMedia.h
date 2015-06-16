#pragma once
#include "DebugItem.h"
class DebugMedia :
	public DebugItem
{
public:
	DebugMedia(std::string theTitle, int dueIn = 3);
	explicit DebugMedia(std::istream& in);
	~DebugMedia();
};

