// LibraryApp.cpp : main project file.

#include "stdafx.h"
#include <iostream>

using namespace System;
using namespace std;

int main(array<System::String ^> ^args)
{
	//Load Library Object


	//Print Welcome to the screen
	cout << "Welcome to the Library\n\n";

	//Print Menu items
	bool done = false;
	int choice;
	while (done == false) {
		cout << "Please select an action number from the following menu: \n";
		cout << "1) Check out a book. \n";
		cout << "2) Check in a book. \n";
		cout << "3) List all books. \n";
		cout << "4) List overdue books. \n";
		cout << "5) List a patron's books. \n";
		cout << "6) Advance the date. \n";
		cout << "7) Quit\n\n";
		cout << "Selection: ";

		//Gather information from the user
		cin.clear();
		cin >> choice;
		switch (choice){
		case 1:
			//checkout a book
			break;
		case 2:
			//checkin a book
			break;
		case 3:
			//list all books
			break;
		case 4:
			//list overdue books
			break;
		case 5:
			//list a patron's books
			break;
		case 6:
			//advance the date
			break;
		case 7:
			//Quit
			done = true;
			break;
		default:
			cout << "ERROR: Invalid input";
			cin.ignore(INT_MAX);
			break;
		}

	}

    return 0;
}
