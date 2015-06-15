#include "stdafx.h"
#include "DebugPatron.h"


DebugPatron::DebugPatron(std::string who, int maxChkOut)
	:name(who),
	MaxCheckedOut(maxChkOut)
{
}

DebugPatron::DebugPatron(std::istream& in)
{
	std::string toBeName{};
	std::getline(in, toBeName);
	name = toBeName;
	in >> MaxCheckedOut;
	int numCheckOut;
	in >> numCheckOut;
	in.ignore();
	//Consider replacing this code with a factory method
	int toCast;
	for (int i = 0; i < numCheckOut; i++)
	{
		in >> toCast;
		switch (static_cast<DebugItem::ITEMTYPES>(toCast))
		{
		case DebugItem::ITEMTYPES::ADULTBOOK:
			checkedOut.push_back(new DebugAdultBook(in));
			break;
		case DebugItem::ITEMTYPES::CHILDRENSBOOK:
			checkedOut.push_back(new DebugChildBook(in));
			break;
		case DebugItem::VHS: 
			checkedOut.push_back(new DebugVHS(in));
			break;
		case DebugItem::DVD: 
			checkedOut.push_back(new DebugDVD(in));
			break;
		default: break;
		}
	}
}

DebugPatron::~DebugPatron()
{
	for (auto x : checkedOut)
		delete x;
}

void DebugPatron::outputTo(std::ostream& out)
{
	out << name << "\n" 
		<< MaxCheckedOut << " "
		<< checkedOut.size() << "\n";
	for (auto x : checkedOut)
	{
		out << x->getType() << " ";
		x->outputTo(out);
	}
}

void DebugPatron::outputCheckedOutTo(std::ostream& out, Version which)
{
	switch (which)
	{
	case ALL:
		for (auto x : checkedOut)
			x->printStatusTo(out);
		break;
	case BOOK:
		for (auto x : checkedOut)
		{
			if (x->getType() == DebugItem::ITEMTYPES::ADULTBOOK ||
				x->getType() == DebugItem::ITEMTYPES::CHILDRENSBOOK)
				x->printStatusTo(out);
		}
		break;
	case MEDIA:
		for (auto x : checkedOut)
		{
			if (x->getType() == DebugItem::ITEMTYPES::DVD ||
				x->getType() == DebugItem::ITEMTYPES::VHS)
				x->printStatusTo(out);
		}
		break;
	}
}

void DebugPatron::outputOverdueTo(std::ostream& out, Version which)
{
	switch (which)
	{
	case ALL:
		for (auto x : checkedOut)
			if (x->isOverdue())
				x->printStatusTo(out);
		break;
	case BOOK:
		for (auto x : checkedOut)
		{
			if (x->getType() == DebugItem::ITEMTYPES::ADULTBOOK ||
				x->getType() == DebugItem::ITEMTYPES::CHILDRENSBOOK)
				if (x->isOverdue())
					x->printStatusTo(out);
		}
		break;
	case MEDIA:
		for (auto x : checkedOut)
		{
			if (x->getType() == DebugItem::ITEMTYPES::DVD ||
				x->getType() == DebugItem::ITEMTYPES::VHS)
				if (x->isOverdue())
					x->printStatusTo(out);
		}
		break;
	}
}
void DebugPatron::checkOut(DebugItem* toCheckout)
{
	if (checkedOut.size() < MaxCheckedOut)
		checkedOut.push_back(toCheckout);
	else throw "Cannot check out more books!\n";
}
DebugItem* DebugPatron::checkIn(std::string identifier)
{
	auto iter = std::find_if(checkedOut.begin(), checkedOut.end(), [identifier](DebugItem* x){return x->hasTitle(identifier); });
	if (iter == checkedOut.end()) throw "Patron does not have this book.\n";
	DebugItem* toReturn = (*iter);
	checkedOut.erase(iter);
	return (toReturn);
}
