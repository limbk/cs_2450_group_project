#include "stdafx.h"
#include "DebugItem.h"


DebugItem::DebugItem(std::string theTitle, int dueInDays)
	:title(theTitle),
	dueInNumDays(dueInDays)
	,	Observer()
{
	DebugDate newDueDate = checkOutDate.advance(dueInNumDays);
	dueDate = newDueDate;
}
DebugItem::DebugItem(std::istream& in)
	:Observer()
{
	std::string theTitle;
	std::getline(in, theTitle);
	title = theTitle;
	checkOutDate = DebugDate(in);
	dueDate = DebugDate(in);
	in >> dueInNumDays;
	in >> _isOverdue;
	if (!in) throw "Reading failed!!";
	//eliminate newline character.
	in.ignore();
}
DebugItem::~DebugItem()
{
}

std::ostream& DebugItem::outputTo(std::ostream& out)
{
	out << title << "\n\t";
	checkOutDate.outputTo(out);
	out << "\t";
	dueDate.outputTo(out);
	out << dueInNumDays << "\n";
	out << _isOverdue << "\n";
	return out;
}
void DebugItem::printStatusTo(std::ostream& out)
{
	out << title;
	checkOutDate.outputStatusTo(out);
	dueDate.outputStatusTo(out);
	if (_isOverdue)
		std::cout << "Yes";
	else std::cout << "No";
}
void DebugItem::printTitleTo(std::ostream& out)
{
	out << title;
}

void DebugItem::checkOut(DebugDate& outDay)
{
	outDay.attach(this);
	DebugDate temp_date = outDay;
	dueDate = temp_date.advance(dueInNumDays);
	checkOutDate =	outDay;
}

void DebugItem::checkIn(DebugDate& inDay)
{
	inDay.detach(this);
}

void DebugItem::update(Subject* toExamine)
{
	DebugDate* toCompare = static_cast<DebugDate*>(toExamine);
	if ((*toCompare) >= dueDate)
		_isOverdue = true;
	else
		_isOverdue = false;
}