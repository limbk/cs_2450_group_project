// LibraryApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Patron.h"
#include "Adult.h"
#include "Child.h"
#include "Date.h"

typedef void (*commandFunc)(void);

void doNothing()
{
}

void mainLoop(const std::vector<std::string> MENUOPTIONS, std::vector<commandFunc> MENUFUNCTIONS);

int _tmain(int argc, _TCHAR* argv[])
{
	//Print Welcome to the screen
	std::cout << "Welcome to the Library!\n\n";
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
	//commandFunc is function pointer taking void and returning void
	//we should change later to take the library as an argument.
	const std::vector<commandFunc> MENUFUNCTIONS{
		doNothing, //Check out a book
		doNothing, //Check in a book
		doNothing, //List all books
		doNothing, //List overdue books
		doNothing, //List patron books
		doNothing, //Advance the date
		doNothing, //Add patron
		doNothing  //Remove patron
	};
	mainLoop(MENUOPTIONS, MENUFUNCTIONS);
	std::cout <<  "Thanks for using the library!\n";
	return 0;
}

void mainLoop(const std::vector<std::string> MENUOPTIONS, std::vector<commandFunc> MENUFUNCTIONS)
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
		if (!std::cin)
		{
			std::cout << "ERROR: Invalid input.\n";
			std::cin.clear();
			std::string toIgnore{};
			std::getline(std::cin, toIgnore);
			continue;
		}
		//Decrementing to actually go to correct index
		--choice;
		if (choice == MENUOPTIONS.size())
		{
			done = true;
			continue;
		}
		std::cout << "Selected option to: " << MENUOPTIONS[choice] << "\n";
		MENUFUNCTIONS[choice];
	}
}
