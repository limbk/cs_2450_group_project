#pragma once
#include "DebugMedia.h"
class DebugVHS :
	public DebugMedia
{
	static const int DUE = 3;
public:
	DebugVHS(std::string theTitle);
	DebugVHS(std::istream& in);
	~DebugVHS();
	ITEMTYPES getType(){ return VHS; }
};

