// LibraryApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Patron.h"
#include "Adult.h"
#include "Child.h"
#include "Date.h"

//Patron* createPatron(std::vector<Patron*> currPatrons)
//{
//	Patron* toReturn = nullptr;
//	char response = 'Y';
//	while (response == 'Y')
//	{
//		std::cout << "Please enter a name for the new patron: ";
//		std::string newName;
//		std::getline(std::cin, newName);
//		if (std::find_if(currPatrons.begin(), currPatrons.end(),
//			[newName](Patron* toCheck)
//		{ return toCheck->hasName(newName); }) != currPatrons.end())
//		{
//			std::cout << "Sorry but that name is already taken.\nWould you like to try a different name?\nY/N: ";
//			std::cin >> response;
//			toupper(response);
//		}
//		else
//		{
//
//		}
//
//	}
//}

void mainLoop(const std::vector<std::string> MENUOPTIONS)
{
	bool done = false;
	int choice;
	std::vector<Patron*> patrons{};
	while (!done) {
		std::cout << "Please select an action number from the following menu: \n";
		for (int i = 0; i < MENUOPTIONS.size(); i++)
			std::cout << i + 1 << ") " << MENUOPTIONS[i] << "\n";
		std::cout << MENUOPTIONS.size() + 1 << ") Quit\n\n";
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
			//Add patron

			break;
		case 8:
			//remove patron
			break;
		case 9:
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
}

int _tmain(int argc, _TCHAR* argv[])
{
	//Load Library Object


	//Print Welcome to the screen
	std::cout << "Welcome to the Library\n\n";
	//Print Menu items
	const std::vector<std::string> MENUOPTIONS
	{
		"Check out a book",
		"Check in a book.",
		"List all books.",
		"List overdue books.",
		"List a patron's books.",
		"Advance the date.",
		"Add a new patron.",
		"Remove a patron."
	};
	mainLoop(MENUOPTIONS);
	return 0;
}

