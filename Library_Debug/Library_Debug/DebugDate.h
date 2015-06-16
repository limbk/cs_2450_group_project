#pragma once
#include "Subject.h"
class DebugDate : public Subject
{
private:
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~CLASS DATA~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 
	struct tm currentDebugDate{};

public:
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~CLASS CONSTRUCTORS/DESTRUCTORS~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 

	DebugDate();
	DebugDate(int year, int month, int day);
	DebugDate(std::istream& in);
	~DebugDate();

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~CLASS METHODS~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 

	DebugDate advance(int numDays);
	std::ostream& outputTo(std::ostream& out);
	std::ostream& outputStatusTo(std::ostream& out);

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~CLASS OPERATIONS~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 

	bool operator ==(const DebugDate& toCompare) const;
	bool operator !=(const DebugDate& toCompare) const { return !((*this) == toCompare); }
	bool operator >=(const DebugDate& toCompare) const;

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~CLASS FRIENDS~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 

	friend std::ostream& operator << (std::ostream& out, const DebugDate& toPrint);
};

inline std::ostream& operator<<(std::ostream& out, const DebugDate& toPrint)
{
	out << "Day is:" << toPrint.currentDebugDate.tm_mday << "\nMonth is:"
		<< toPrint.currentDebugDate.tm_mon << "\nYear is:"
		<< toPrint.currentDebugDate.tm_year << std::endl;
	return out;
}
