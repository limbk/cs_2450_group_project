#pragma once
#include "ObserverPattern.h"

class Date : public Subject<Date>
{
private:
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~CLASS DATA~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 
	struct tm currentDate{};

public:
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~CLASS CONSTRUCTORS/DESTRUCTORS~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 

	Date();
	Date(int year, int month, int day);
	Date(std::istream& in);
	~Date();

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~CLASS METHODS~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 

	Date advance(int numDays);
	std::ostream& outputTo(std::ostream& out);
	std::ostream& outputStatusTo(std::ostream& out);
	Date* getValue(){ return this; }

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~CLASS OPERATIONS~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 

	bool operator ==(const Date& toCompare) const;
	bool operator !=(const Date& toCompare) const { return !((*this) == toCompare); }
	bool operator >=(const Date& toCompare) const;

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~CLASS FRIENDS~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 

	friend std::ostream& operator << (std::ostream& out, const Date& toPrint);
};

inline std::ostream& operator<<(std::ostream& out, const Date& toPrint)
{
	out << "Day is:" << toPrint.currentDate.tm_mday << "\nMonth is:"
		<< toPrint.currentDate.tm_mon << "\nYear is:"
		<< toPrint.currentDate.tm_year << std::endl;
	return out;
}
