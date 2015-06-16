#pragma once
#include "DebugItem.h"
#include "DebugPatron.h"
#include "DebugAdult.h"
#include "DebugChild.h"
#include "DebugDate.h"
class DebugLibrary
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~CLASS DATA~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 

	DebugDate currDate{};
	std::vector<DebugItem*> availableItems{};
	std::vector<DebugPatron*> knownPatrons{};

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~HELPER METHODS~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 

	DebugItem* retrieveTitle(std::string title);
	DebugPatron* retrievePatron(std::string who);

public:
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~CLASS CONSTRUCTORS/DESTRUCTORS~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 

	DebugLibrary(DebugDate startDate, std::istream& inCatalog);
	explicit DebugLibrary(std::istream& in);
	~DebugLibrary();

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~CLASS METHODS~~~~~~~~~~~~~~~~~~~~~~~
	 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 

	void addPatron(std::string name, DebugPatron::PatronType which);
	void removePatron(std::string who);
	void addItem(std::string title, DebugItem::ITEMTYPES which);
	void removeItem(std::string whichTitle);
	void outputCheckedOutTo(std::ostream& out);
	void outputAvailableTo(std::ostream& out, DebugPatron::PatronType which);
	void outputAvailableTo(std::ostream& out, std::string who);
	void outputKnownPatronsTo(std::ostream& out);
	void checkoutTitle(std::string toCheckout, std::string who);
	void checkinTitle(std::string toReturn, std::string who);
	//Consider turning this into private...it will output EVERYTHING
	void outputTo(std::ostream& out);
	void advanceDate(int numDays);
};

