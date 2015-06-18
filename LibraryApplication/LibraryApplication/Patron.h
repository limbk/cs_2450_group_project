#pragma once
//#include "Item.h"
//#include "AdultBook.h"
//#include "ChildBook.h"
//#include "DVD.h"
//#include "VHS.h"
class Patron
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~CLASS DATA~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 

	//std::vector<Item*> checkedOut{};
	std::string name{};
	int MaxCheckedOut{};

public:

	enum Version{ALL, BOOK, MEDIA};
	enum PatronType{ADULT, CHILD};
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~CLASS CONSTRUCTORS/DESTRUCTORS~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 

	Patron(std::string who, int maxChkOut = 5);
	Patron(std::istream& in);
	~Patron();

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~CLASS METHODS~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 
	
	void outputTo(std::ostream& out);
	virtual void printTo(std::ostream& out);
	void outputCheckedOutTo(std::ostream& out, Version which = ALL );
	void outputOverdueTo(std::ostream& out, Version which = ALL);
	//void checkOut(Item* toCheckout);
	//int numCheckedOut(){ return checkedOut.size(); }
	//Item* checkIn(std::string identifier);
	virtual PatronType getType() = 0;
	bool hasName(std::string toCheck) { return toCheck == name; }
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~CLASS OPERATIONS~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 

	bool operator == (const Patron& toCompare) const { return name == toCompare.name; }
};

