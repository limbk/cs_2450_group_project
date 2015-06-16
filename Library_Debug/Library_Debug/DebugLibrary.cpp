#include "stdafx.h"
#include "DebugLibrary.h"


DebugItem* DebugLibrary::retrieveTitle(std::string title)
{
	auto toReturn = std::find_if(availableItems.begin(), availableItems.end(),
		[title](DebugItem* toCheck){return toCheck->hasTitle(title); });
	if (toReturn == availableItems.end()) return nullptr;
	return (*toReturn);
}

DebugPatron* DebugLibrary::retrievePatron(std::string who)
{
	auto toReturn = std::find_if(knownPatrons.begin(), knownPatrons.end(),
		[who](DebugPatron* toCheck){return toCheck->hasName(who); });
	if (toReturn == knownPatrons.end()) return nullptr;
	else return (*toReturn);
}

DebugLibrary::DebugLibrary(DebugDate startDate, std::istream& inCatalog)
	:currDate(startDate)
{
	int toCast;
	while (inCatalog)
	{
		try
		{
			inCatalog >> toCast;
			switch (static_cast<DebugItem::ITEMTYPES>(toCast))
			{
			case DebugItem::ADULTBOOK:		
				availableItems.push_back(new DebugAdultBook(inCatalog));
				break;
			case DebugItem::CHILDRENSBOOK: 		
				availableItems.push_back(new DebugChildBook(inCatalog));
				break;
			case DebugItem::VHS: 			
				availableItems.push_back(new DebugVHS(inCatalog));
				break;
			case DebugItem::DVD: 			
				availableItems.push_back(new DebugDVD(inCatalog));
				break;
			default: break;
			}
		}
		catch (...)
		{
			//This is bad to do...not broken, but bad.
			if (inCatalog.eof() != true)
				std::cout << "Bad read during catalog!\n";
			break;
		}
	}
}

DebugLibrary::DebugLibrary(std::istream& in)
{
	currDate = DebugDate(in);
	int availableItemsSize;
	in >> availableItemsSize;
	int toCast;
	for (int i = 0; i < availableItemsSize; i++)
	{
		in >> toCast;
		switch (static_cast<DebugItem::ITEMTYPES>(toCast))
		{
		case DebugItem::ADULTBOOK:
			availableItems.push_back(new DebugAdultBook(in));
			break;
		case DebugItem::CHILDRENSBOOK: 
			availableItems.push_back(new DebugChildBook(in));
			break;
		case DebugItem::VHS: 
			availableItems.push_back(new DebugVHS(in));
			break;
		case DebugItem::DVD:
			availableItems.push_back(new DebugDVD(in));
			break;
		}
	}
	int patronSize;
	in >> patronSize;
	for (int i = 0; i < patronSize; i++)
	{
		in >> toCast;
		switch (static_cast<DebugPatron::PatronType>(toCast))
		{
		case DebugPatron::ADULT: 
			knownPatrons.push_back(new DebugAdult(in));
			break;
		case DebugPatron::CHILD: 
			knownPatrons.push_back(new DebugChild(in));
			break;
		}
	}
}

DebugLibrary::~DebugLibrary()
{
	for (auto x : availableItems)
		delete x;
	for (auto x : knownPatrons)
		delete x;
}

void DebugLibrary::addPatron(std::string name, DebugPatron::PatronType which)
{
	if (name.empty()) throw "Empty name!\n";
	if (retrievePatron(name) != nullptr) throw "Person by that name already exists!\n";
	switch (which)
	{
	case DebugPatron::PatronType::ADULT:
		knownPatrons.push_back(new DebugAdult(name));
		break;
	case DebugPatron::PatronType::CHILD:
		knownPatrons.push_back(new DebugChild(name));
		break;
	}
}
void DebugLibrary::removePatron(std::string who)
{
	DebugPatron* toRemove = retrievePatron(who);
	if (toRemove != nullptr)
	{
		auto extractedBooks = toRemove->extractBooks();
		for (auto item : extractedBooks)
			availableItems.push_back(item);
		delete toRemove;
		knownPatrons.erase(std::remove(knownPatrons.begin(), knownPatrons.end(), toRemove), knownPatrons.end());
	}
}

void DebugLibrary::addItem(std::string title, DebugItem::ITEMTYPES which)
{
	if (title.empty()) throw "Title cannot be empty!\n";
	switch (which)
	{
	case DebugItem::ADULTBOOK: 
		availableItems.push_back(new DebugAdultBook(title));
		break;
	case DebugItem::CHILDRENSBOOK:
		availableItems.push_back(new DebugChildBook(title));
		break;
	case DebugItem::VHS:
		availableItems.push_back(new DebugVHS(title));
		break;
	case DebugItem::DVD:
		availableItems.push_back(new DebugDVD(title));
		break;
	default: break;
	}
}

void DebugLibrary::removeItem(std::string whichTitle)
{
	DebugItem* toRemove = retrieveTitle(whichTitle);
	if (toRemove != nullptr)
	{
		delete toRemove;
		availableItems.erase(std::remove(availableItems.begin(), availableItems.end(), toRemove), availableItems.end());
	}
}

void DebugLibrary::outputCheckedOutTo(std::ostream& out)
{
	for (auto x : knownPatrons)
		x->outputCheckedOutTo(out);
}

void DebugLibrary::outputAvailableTo(std::ostream& out, DebugPatron::PatronType which)
{
	switch (which)
	{
	case DebugPatron::PatronType::ADULT:
		for (auto x : availableItems)
			x->printAsAvailableTo(out), out << "\n";
		break;
	case DebugPatron::PatronType::CHILD:
		for (auto x : availableItems)
			if (x->getType() == DebugItem::ITEMTYPES::CHILDRENSBOOK)
				x->printAsAvailableTo(out), out << "\n";
		break;
	}
}

void DebugLibrary::outputAvailableTo(std::ostream& out, std::string who)
{
	DebugPatron* toWhom = retrievePatron(who);
	if (toWhom == nullptr) throw "Unrecognized patron!\n";
	outputAvailableTo(out, toWhom->getType());
}
void DebugLibrary::outputKnownPatronsTo(std::ostream& out)
{
	for (auto x : knownPatrons)
		x->printTo(out), out << "\n";
}

void DebugLibrary::checkoutTitle(std::string toCheckout, std::string who)
{
	DebugItem* toRemove = retrieveTitle(toCheckout);
	DebugPatron* toRecieve = retrievePatron(who);
	//When moving to UI this is where I can catch and make a message dialog
	if (toRemove == nullptr || toRecieve == nullptr)
	{
		std::cout << "Cannot find title and/or patron!\n";
		return;
	}
	toRemove->checkOut(currDate);
	try
	{
		toRecieve->checkOut(toRemove);
		availableItems.erase(std::remove(availableItems.begin(), availableItems.end(), toRemove), availableItems.end());
	}
	catch (char* errMsg)
	{
		std::cout << errMsg;
		toRemove->checkIn(currDate);
	}
}

void DebugLibrary::checkinTitle(std::string toReturn, std::string who)
{
	DebugPatron* theReturner = retrievePatron(who);
	//Note: I should just do a message dialog instead
	if (theReturner == nullptr)
		throw "Cannot find patron!\n";
	try
	{
		DebugItem* returned = theReturner->checkIn(toReturn);
		availableItems.push_back(returned);
	}
	catch (char* thrownMessage)
	{
		//catch the bad news here
		//maybe handle this better? with the gui this shouldnt happen...
		std::cout << thrownMessage;
	}
	
}
//Purpose: Outputs the conditions of the library to the output stream provided 
//	 really only used for saving, but is useful as public for debugging purposes.
//Pre-conditions: Out is not in a failed state. Out has been initialized to valid  
//	 values.
//Post-conditions: Library state is written out in a manner from which it can be 
//	 read back in.
void DebugLibrary::outputTo(std::ostream& out)
{
	currDate.outputTo(out);
	out << availableItems.size() << " ";
	for (auto x : availableItems)
	{
		out << x->getType() << " ";
		x->outputTo(out);
	}
	out << knownPatrons.size() << " ";
	for (auto x : knownPatrons)
	{
		out << x->getType() << " ";
		x->outputTo(out);
	}
}
//Purpose: Library advances its current date as specified by numDays.
//Pre-conditions: None
//Post-conditions: Library date is altered by the number of days.
void DebugLibrary::advanceDate(int numDays)
{
	currDate = currDate.advance(numDays);
}