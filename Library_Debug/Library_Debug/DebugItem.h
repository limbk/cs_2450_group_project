#pragma once
#include "DebugDate.h"
#include "Subject.h"

class DebugItem : public Observer
{
private:
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~CLASS DATA~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 

	DebugDate checkOutDate{};
	DebugDate dueDate{};
	std::string title{};
	bool _isOverdue = false;
	int dueInNumDays{};

public:

	enum ITEMTYPES{ADULTBOOK, CHILDRENSBOOK, VHS, DVD};

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~CLASS CONSTRUCTORS/DESTRUCTORS~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 

	DebugItem(std::string theTitle, int dueInDays = 3);
	DebugItem(std::istream& in);
	~DebugItem();

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~CLASS METHODS~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 
	virtual std::ostream& outputTo(std::ostream& out);
	void checkOut(DebugDate& outDay);
	void checkIn(DebugDate& inDay);
	bool isOverdue() const { return _isOverdue; }
	bool hasTitle(const std::string& toCheck){ return (toCheck == title); }
	virtual ITEMTYPES getType() = 0;
	void update(Subject* toExamine);
	virtual void printStatusTo(std::ostream& out);
	virtual void printAsAvailableTo(std::ostream& out);

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~CLASS OPERATIONS~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 

	bool operator == (const DebugItem& toCompare) const
	{
		return (title == toCompare.title && 
			checkOutDate == toCompare.checkOutDate && 
			dueDate == toCompare.dueDate && 
			_isOverdue == toCompare._isOverdue);
	}
};

