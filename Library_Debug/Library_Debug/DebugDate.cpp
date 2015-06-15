#include "stdafx.h"
#include "DebugDate.h"

DebugDate::DebugDate()
	:Subject()
{
	time_t t = time(0);
	localtime_s(&currentDebugDate, &t);
}

DebugDate::DebugDate(std::istream& in)
	:Subject()
{
	in >> currentDebugDate.tm_year;
	in >> currentDebugDate.tm_mon;
	in >> currentDebugDate.tm_mday;
}

DebugDate::~DebugDate()
{
}
DebugDate DebugDate::advance(int numDays)
{
	DebugDate toReturn;
	toReturn.currentDebugDate = currentDebugDate;
	toReturn.currentDebugDate.tm_mday += numDays;
	time_t normalize = mktime(&toReturn.currentDebugDate);
	localtime_s(&toReturn.currentDebugDate, &normalize);
	notify();
	return toReturn;
}

std::ostream& DebugDate::outputTo(std::ostream& out)
{
	out << currentDebugDate.tm_year << " "
		<< currentDebugDate.tm_mon << " "
		<< currentDebugDate.tm_mday << " \n";
	return out;
}

std::ostream& DebugDate::outputStatusTo(std::ostream& out)
{
	out << (currentDebugDate.tm_year + 1900);
	switch (currentDebugDate.tm_mon)
	{
	case 0:
		out << "January";
		break;
	case 1:
		out << "February";
		break;
	case 2:
		out << "March";
		break;
	case 3:
		out << "April";
		break;
	case 4:
		out << "May";
		break;
	case 5:
		out << "June";
		break;
	case 6:
		out << "July";
		break;
	case 7:
		out << "August";
		break;
	case 8:
		out << "September";
		break;
	case 9:
		out << "October";
		break;
	case 10:
		out << "November";
		break;
	case 11:
		out << "December";
		break;
	}
	out << currentDebugDate.tm_mday;
	return out;
}

bool DebugDate::operator ==(const DebugDate& toCompare) const
{
	return (currentDebugDate.tm_year == toCompare.currentDebugDate.tm_year &&
		currentDebugDate.tm_mon == toCompare.currentDebugDate.tm_mon &&
		currentDebugDate.tm_mday == toCompare.currentDebugDate.tm_mday);
}



bool DebugDate::operator>=(const DebugDate& toCompare) const
{
	if (currentDebugDate.tm_year > toCompare.currentDebugDate.tm_year)
		return true;
	if (currentDebugDate.tm_year == currentDebugDate.tm_year)
	{
		if (currentDebugDate.tm_mon > toCompare.currentDebugDate.tm_mon)
			return true;
		if (currentDebugDate.tm_mon == toCompare.currentDebugDate.tm_mon)
		{
			if (currentDebugDate.tm_mday > toCompare.currentDebugDate.tm_mday)
				return true;
			if (currentDebugDate.tm_mday == toCompare.currentDebugDate.tm_mday)
				return true;
		}
	}
	return false;
}