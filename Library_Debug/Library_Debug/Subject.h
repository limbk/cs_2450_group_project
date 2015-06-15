#pragma once
#include "stdafx.h"
class Subject;
class Observer
{
private:
public:
	Observer(){};
	~Observer(){};
	void virtual update(Subject* subject){ std::cout << "Observed.\n"; };
};
class Subject
{
	
	std::vector<Observer*> theObservers{};
public:
	Subject(){};
	~Subject(){};
	void notify()
	{
		for (auto x : theObservers)
			x->update(this);
	}

	void attach(Observer* toRegister){ theObservers.push_back(toRegister); }
	void detach(Observer* toRemove)
	{
		auto found = std::find(theObservers.begin(), theObservers.end(), toRemove);
		theObservers.erase(found);
	}
};

