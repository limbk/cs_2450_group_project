#include "stdafx.h"
#include "Patron.h"


Patron::Patron(std::string who, int maxChkOut)
	:name(who),
	MaxCheckedOut(maxChkOut)
{
}

Patron::Patron(std::istream& in)
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
	//for (int i = 0; i < numCheckOut; i++)
	//{
	//	in >> toCast;
	//	switch (static_cast<Item::ITEMTYPES>(toCast))
	//	{
	//	case Item::ITEMTYPES::ADULTBOOK:
	//		checkedOut.push_back(new AdultBook(in));
	//		break;
	//	case Item::ITEMTYPES::CHILDRENSBOOK:
	//		checkedOut.push_back(new ChildBook(in));
	//		break;
	//	case Item::VHS: 
	//		checkedOut.push_back(new VHS(in));
	//		break;
	//	case Item::DVD: 
	//		checkedOut.push_back(new DVD(in));
	//		break;
	//	default: break;
	//	}
	//}
}

Patron::~Patron()
{
	//for (auto x : checkedOut)
	//	delete x;
}

void Patron::outputTo(std::ostream& out)
{
	out << name << "\n"
		<< MaxCheckedOut << " ";
		//<< checkedOut.size() << "\n";
	//for (auto x : checkedOut)
	//{
	//	out << x->getType() << " ";
	//	x->outputTo(out);
	//}
}

void Patron::printTo(std::ostream& out)
{
	out << name;
}

void Patron::outputCheckedOutTo(std::ostream& out, Version which)
{
	//switch (which)
	//{
	//case ALL:
	//	for (auto x : checkedOut)
	//		x->printStatusTo(out);
	//	break;
	//case BOOK:
	//	for (auto x : checkedOut)
	//	{
	//		if (x->getType() == Item::ITEMTYPES::ADULTBOOK ||
	//			x->getType() == Item::ITEMTYPES::CHILDRENSBOOK)
	//			x->printStatusTo(out);
	//	}
	//	break;
	//case MEDIA:
	//	for (auto x : checkedOut)
	//	{
	//		if (x->getType() == Item::ITEMTYPES::DVD ||
	//			x->getType() == Item::ITEMTYPES::VHS)
	//			x->printStatusTo(out);
	//	}
	//	break;
	//}
}

void Patron::outputOverdueTo(std::ostream& out, Version which)
{
	//switch (which)
	//{
	//case ALL:
	//	for (auto x : checkedOut)
	//		if (x->isOverdue())
	//			x->printStatusTo(out);
	//	break;
	//case BOOK:
	//	for (auto x : checkedOut)
	//	{
	//		if (x->getType() == Item::ITEMTYPES::ADULTBOOK ||
	//			x->getType() == Item::ITEMTYPES::CHILDRENSBOOK)
	//			if (x->isOverdue())
	//				x->printStatusTo(out);
	//	}
	//	break;
	//case MEDIA:
	//	for (auto x : checkedOut)
	//	{
	//		if (x->getType() == Item::ITEMTYPES::DVD ||
	//			x->getType() == Item::ITEMTYPES::VHS)
	//			if (x->isOverdue())
	//				x->printStatusTo(out);
	//	}
	//	break;
	//}
}

//void Patron::checkOut(Item* toCheckout)
//{
//	if (checkedOut.size() < MaxCheckedOut)
//		checkedOut.push_back(toCheckout);
//	else throw "Cannot check out more books!\n";
//}
//Item* Patron::checkIn(std::string identifier)
//{
//	auto iter = std::find_if(checkedOut.begin(), checkedOut.end(), [identifier](Item* x){return x->hasTitle(identifier); });
//	if (iter == checkedOut.end()) throw "Patron does not have this book.\n";
//	Item* toReturn = (*iter);
//	checkedOut.erase(iter);
//	return (toReturn);
//}

