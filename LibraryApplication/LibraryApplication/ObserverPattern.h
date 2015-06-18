#pragma once
#include "stdafx.h"
template <typename T>
class Subject;
template <typename T>
class Observer
{
private:
public:
	Observer(){};
	~Observer(){};
	void virtual update(Subject<T>* subject){ std::cout << "Observed.\n"; };
};
template <typename T>
class Subject
{
	
	std::vector<Observer<T>*> theObservers{};
public:
	Subject(){};
	~Subject(){};
	void notify()
	{
		for (auto x : theObservers)
			x->update(this);
	}

	void attach(Observer<T>* toRegister){ theObservers.push_back(toRegister); }
	void detach(Observer<T>* toRemove)
	{
		auto found = std::find(theObservers.begin(), theObservers.end(), toRemove);
		theObservers.erase(found);
	}
	virtual T* getValue() = 0;
};

