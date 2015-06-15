#include "stdafx.h"
#include "DebugLibrary.h"


std::_Vector_iterator<std::_Vector_val<std::_Simple_types<DebugItem*>>> 
DebugLibrary::findTitle(std::string title)
{
	auto toReturn = std::find_if(availableItems.begin(), availableItems.end(),
		[title](DebugItem* toCheck){return toCheck->hasTitle(title); });
	return toReturn;
}

std::_Vector_iterator<std::_Vector_val<std::_Simple_types<DebugPatron*>>> 
DebugLibrary::findPatron(std::string who)
{
	auto toReturn = std::find_if(knownPatrons.begin(), knownPatrons.end(),
		[who](DebugPatron* toCheck){return toCheck->hasName(who); });
	return toReturn;
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
	if (findPatron(name) != knownPatrons.end()) throw "Person by that name already exists!\n";
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
	auto toRemove = findPatron(who);
	if (toRemove != knownPatrons.end())
	{
		delete (*toRemove);
		knownPatrons.erase(toRemove);
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
	auto toRemove = findTitle(whichTitle);
	if (toRemove != availableItems.end())
	{
		delete (*toRemove);
		availableItems.erase(toRemove);
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
			x->outputTo(out);
		break;
	case DebugPatron::PatronType::CHILD:
		for (auto x : availableItems)
			if (x->getType() == DebugItem::ITEMTYPES::CHILDRENSBOOK)
				x->outputTo(out);
		break;
	}
}

void DebugLibrary::outputAvailableTo(std::ostream& out, std::string who)
{
	auto toWhom = findPatron(who);
	if (toWhom == knownPatrons.end()) throw "Unrecognized patron!\n";
	outputAvailableTo(out, (*toWhom)->getType());
}

void DebugLibrary::outputKnownPatronsTo(std::ostream& out)
{
	for (auto x : knownPatrons)
		x->outputTo(out);
}

void DebugLibrary::checkoutTitle(std::string toCheckout, std::string who)
{
	auto toRemove = findTitle(toCheckout);
	auto toRecieve = findPatron(who);
	//When moving to UI this is where I can catch and make a message dialog
	if (toRemove == availableItems.end() || toRecieve == knownPatrons.end())
		std::cout << "Cannot find title and/or patron!\n";
	(*toRemove)->checkOut(currDate);
	(*toRecieve)->checkOut((*toRemove));
	availableItems.erase(toRemove);
}

void DebugLibrary::checkinTitle(std::string toReturn, std::string who)
{
	auto theReturner = findPatron(who);
	if (theReturner == knownPatrons.end())
		throw "Cannot find patron!\n";
	try
	{
		auto returned = (*theReturner)->checkIn(toReturn);
		availableItems.push_back(returned);
	}
	catch (char* thrownMessage)
	{
		//catch the bad news here
		std::cout << thrownMessage;
	}
	
}

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

void DebugLibrary::advanceDate(int numDays)
{
	currDate = currDate.advance(numDays);
}