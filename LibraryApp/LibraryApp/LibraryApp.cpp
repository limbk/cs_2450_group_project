// LibraryApp.cpp : main project file.

#include "stdafx.h"


int main(int argc, char* argv[])
{
	//Load Library Object


	//Print Welcome to the screen
	std::cout << "Welcome to the Library\n\n";

	//Print Menu items
	bool done = false;
	int choice;
	while (done == false) {
		std::cout << "Please select an action number from the following menu: \n";
		std::cout << "1) Check out a book. \n";
		std::cout << "2) Check in a book. \n";
		std::cout << "3) List all books. \n";
		std::cout << "4) List overdue books. \n";
		std::cout << "5) List a patron's books. \n";
		std::cout << "6) Advance the date. \n";
		std::cout << "7) Quit\n\n";
		std::cout << "Selection: ";

		//Gather information from the user
		std::cin.clear();
		std::cin >> choice;
		switch (choice){
		case 1:
			//checkout a book
			std::cout << "Checking out a book...\n";
			break;
		case 2:
			//checkin a book
			std::cout << "Checking in a book...\n";
			break;
		case 3:
			//list all books
			std::cout << "Listing all books...\n";
			break;
		case 4:
			//list overdue books
			std::cout << "Listing overdue books...\n";
			break;
		case 5:
			//list a patron's books
			std::cout << "Listing patrons books...\n";
			break;
		case 6:
			//advance the date
			std::cout << "Advancing the date...\n";
			break;
		case 7:
			//Quit
			done = true;
			break;
		default:
			std::cout << "ERROR: Invalid input.\n";
			std::cin.clear();
			std::string toIgnore{};
			std::getline(std::cin, toIgnore);
			break;
		}

	}

    return 0;
}
