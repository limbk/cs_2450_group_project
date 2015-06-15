#pragma once
#include "DebugMedia.h"
class DebugDVD :
	public DebugMedia
{
	static const int DUE = 2;
public:

	DebugDVD(std::string theTitle);
	DebugDVD(std::istream& in);
	~DebugDVD();
	ITEMTYPES getType(){ return DVD; }
};

