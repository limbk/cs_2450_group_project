#pragma once
#include "DebugItem.h"
#include "DebugAdultBook.h"
#include "DebugChildBook.h"
#include "DebugDVD.h"
#include "DebugVHS.h"
class DebugPatron
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~CLASS DATA~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 

	std::list<DebugItem*> checkedOut{};
	std::string name{};
	int MaxCheckedOut{};

public:

	enum Version{ALL, BOOK, MEDIA};
	enum PatronType{ADULT, CHILD};
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~CLASS CONSTRUCTORS/DESTRUCTORS~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 

	DebugPatron(std::string who, int maxChkOut = 5);
	DebugPatron(std::istream& in);
	~DebugPatron();

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~CLASS METHODS~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 
	
	void outputTo(std::ostream& out);
	void outputCheckedOutTo(std::ostream& out, Version which = ALL );
	void outputOverdueTo(std::ostream& out, Version which = ALL);
	void checkOut(DebugItem* toCheckout);
	int numCheckedOut(){ return checkedOut.size(); }
	DebugItem* checkIn(std::string identifier);
	virtual PatronType getType() = 0;
	bool hasName(std::string toCheck) { return toCheck == name; }
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~CLASS OPERATIONS~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 

	bool operator == (const DebugPatron& toCompare) const { return name == toCompare.name; }
};

