#include "stdafx.h"
#include "Date.h"

Date::Date()
	:Subject()
{
	time_t t = time(0);
	localtime_s(&currentDate, &t);
}

Date::Date(std::istream& in)
	:Subject()
{
	in >> currentDate.tm_year;
	in >> currentDate.tm_mon;
	in >> currentDate.tm_mday;
}

Date::~Date()
{
}
Date Date::advance(int numDays)
{
	Date toReturn;
	toReturn.currentDate = currentDate;
	toReturn.currentDate.tm_mday += numDays;
	time_t normalize = mktime(&toReturn.currentDate);
	localtime_s(&toReturn.currentDate, &normalize);
	notify();
	return toReturn;
}

std::ostream& Date::outputTo(std::ostream& out)
{
	out << currentDate.tm_year << " "
		<< currentDate.tm_mon << " "
		<< currentDate.tm_mday << " \n";
	return out;
}

std::ostream& Date::outputStatusTo(std::ostream& out)
{
	out << (currentDate.tm_year + 1900);
	switch (currentDate.tm_mon)
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
	out << currentDate.tm_mday;
	return out;
}

bool Date::operator ==(const Date& toCompare) const
{
	return (currentDate.tm_year == toCompare.currentDate.tm_year &&
		currentDate.tm_mon == toCompare.currentDate.tm_mon &&
		currentDate.tm_mday == toCompare.currentDate.tm_mday);
}



bool Date::operator>=(const Date& toCompare) const
{
	if (currentDate.tm_year > toCompare.currentDate.tm_year)
		return true;
	if (currentDate.tm_year == currentDate.tm_year)
	{
		if (currentDate.tm_mon > toCompare.currentDate.tm_mon)
			return true;
		if (currentDate.tm_mon == toCompare.currentDate.tm_mon)
		{
			if (currentDate.tm_mday > toCompare.currentDate.tm_mday)
				return true;
			if (currentDate.tm_mday == toCompare.currentDate.tm_mday)
				return true;
		}
	}
	return false;
}