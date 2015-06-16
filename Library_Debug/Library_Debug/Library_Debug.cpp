// Library_Debug.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Subject.h"

#include "DebugItem.h"
#include "DebugDate.h"
#include "DebugPatron.h"
#include "DebugLibrary.h"


//void testDebugDate()
//{
//	DebugDate tom;
//	std::cout << tom;
//	DebugDate sally;
//	std::cout << sally;
//	if (sally == tom)
//		std::cout <<  "Is equal...works.\nAdvancing the date by 1 year now...\n";
//	else std::cout << "Is equal does not work.\n";
//	tom = tom.advance(365);
//	std::cout << tom;
//	if (sally != tom)
//		std::cout <<  "Is not equal...works.\n";
//	else std::cout << "Not equal does not work.\n";
//	std::cout <<  "Testing nicer output.\n";
//	tom.outputStatusTo(std::cout);
//	std::cout <<  "\nReversing time...\n";
//	tom = tom.advance(-365);
//	tom.outputStatusTo(std::cout);
//	std::cout << std::endl;
//	std::cout <<  "Input: <Year> <Month> <Day>\n";
//	DebugDate smith(std::cin);
//	smith.outputTo(std::cout);
//	std::cout <<  "Messing with stringstream...\n";
//	std::stringstream testing;
//	smith.outputTo(testing);
//	if (testing.rdbuf()->in_avail() != 0)
//		std::cout << "Works with stringstream!\n";
//	std::cin.clear();
//	std::cin.ignore();
//	std::cout <<  "DebugDate testing is done.\n";
//	getchar();
//}
//void TestDebugItem()
//{
//	DebugItem sam("Sam is my title");
//	DebugItem steve("Sam is my title");
//	std::cout <<  "Output is: Title\nCheckout Date\nDue Date\nAmount of days for it to be overdue.\nIs Overdue\n";
//	sam.outputTo(std::cout);
//	if (sam == steve)
//		std::cout <<  "Comparisons work!\n";
//	else std::cout << "Comparison failed.\n";
//	std::cout << "Checking out in the future!\n";
//	sam.checkOut(DebugDate().advance(5));
//	sam.outputTo(std::cout);
//	std::cout <<  "Saving to a file...\n";
//	std::ofstream outputFile("TestSave.txt", std::ofstream::out);
//	sam.outputTo(outputFile);
//	outputFile.close();
//	std::ifstream inputFile("TestSave.txt", std::ifstream::in);
//	DebugItem greg(inputFile);
//	if (greg == sam)
//	{
//		std::cout << "First equals...\n";
//		greg.outputTo(std::cout);
//		std::cout <<  "Second equals...\n";
//		sam.outputTo(std::cout);
//		std::cout << "Save and loading works!\n";
//	}
//	else std::cout << "Save and loading do not work.\n";
//	std::cout <<  "Testing nicer print.\n";
//	sam.printStatusTo(std::cout);
//	std::cout << "\n";
//	std::cout <<  "Testing observer pattern now.\n";
//	DebugDate subDate;
//	//Should expire in 7 days.
//	DebugItem obsItem("Shamalam", 7);
//	//Cant test this without observer pattern.
//	//if (sam.isOverdue())
//	//{
//	//	std::cout <<  "Is overdue...working.\n";
//	//}
//	std::cout <<  "Testing DebugItem complete!\n";
//	getchar();
//}
//
//void TestDebugMediaAndBook()
//{
//	std::vector<DebugItem*> debugcollection{};
//	std::cout << "Creating collection of titles.\n";
//	debugcollection.push_back(new DebugBook("1001 Arabian Nights"));
//	debugcollection.push_back(new DebugMedia("The Witcher"));
//	std::cout << "Printing title status.";
//	for (auto x : debugcollection)
//		x->printStatusTo(std::cout);
//	std::cout << "Saving two titles to file.\n";
//	std::ofstream output("TestBatchSave.txt");
//	for (auto x : debugcollection)
//	{
//		output << x->getType() << " ";
//		x->outputTo(output);
//	}
//	output.close();
//	std::vector<DebugItem*> secondCollection{};
//	std::ifstream inputForComparison("TestBatchSave.txt");
//	while (inputForComparison)
//	{
//		try
//		{
//			int toCast;
//			inputForComparison >> toCast;
//			switch ((DebugItem::ITEMTYPES)toCast)
//			{
//			case DebugItem::ITEMTYPES::BOOK:
//				secondCollection.push_back(new DebugBook(inputForComparison));
//				break;
//			case DebugItem::ITEMTYPES::MEDIA:
//				secondCollection.push_back(new DebugMedia(inputForComparison));
//				break;
//			}
//		}
//		catch (...)
//		{
//			break;
//		}
//	}
//	inputForComparison.close();
//	if (debugcollection.size() != secondCollection.size())
//		std::cout << "Loading is bugged.\n";
//	else std::cout << "Loading works.\n";
//	std::cout << "Loading titles from file.\n";
//	std::ifstream input("BookTitles.txt");
//	while (input)
//	{
//		try
//		{
//			debugcollection.push_back(new DebugBook(input));
//			debugcollection.push_back(new DebugMedia(input));
//		}
//		catch (...)
//		{
//			break;
//		}
//	}
//	input.close();
//	std::cout << "Printing collection titles...\n";
//	for (auto x : debugcollection)
//		x->printTitleTo(std::cout), std::cout << "\n";
//	std::cout <<  "Saving collection...\n";
//	std::ofstream collectionOutput("BookTitles.txt");
//	for (auto x:debugcollection)
//	{
//		collectionOutput << x->getType() << " ";
//		x->outputTo(collectionOutput);
//	}
//	collectionOutput.close();
//	std::cout <<  "Test completed.\n";
//	getchar();
//}
//
//void testPatron()
//{
//	std::cout <<  "Creating Patron who has no items..\n";
//	DebugPatron greg("Greg");
//	greg.outputTo(std::cout);
//	std::cout <<  "Giving patron some books.\n";
//	greg.checkOut(new DebugBook("Essential C++"));
//	greg.checkOut(new DebugMedia("Firefly Season 1"));
//	greg.checkOut(new DebugBook("Python Cookbook"));
//	greg.checkOut(new DebugMedia("Dumb and Dumber"));
//	greg.checkOut(new DebugBook("Design Patterns"));
//	greg.outputTo(std::cout);
//	std::cout <<  "Having patron save to file.\n";
//	std::ofstream outputPatron("PatronTestSave.txt");
//	greg.outputTo(outputPatron);
//	outputPatron.close();
//	std::cout <<  "Reading in duplicate patron.\n";
//	std::ifstream inputPatron("PatronTestSave.txt");
//	DebugPatron gregDoppleGanger(inputPatron);
//	inputPatron.close();
//	if (gregDoppleGanger == greg)
//	{
//		std::cout <<  "Doppleganger stats...\n";
//		gregDoppleGanger.outputTo(std::cout);
//		std::cout <<  "Original stats...\n";
//		greg.outputTo(std::cout);
//		std::cout << "Read in successful.\n";
//	}
//	else std::cout << "Read in failed.\n";
//	std::cout <<  "Printing different versions of checked out...\n";
//	std::cout <<  "All\n";
//	greg.outputCheckedOutTo(std::cout, DebugPatron::Version::ALL);
//	std::cout << "\nBooks\n";
//	greg.outputCheckedOutTo(std::cout, DebugPatron::Version::BOOK);
//	std::cout << "\nMedia\n";
//	greg.outputCheckedOutTo(std::cout, DebugPatron::Version::MEDIA);
//	std::cout <<  "\nSuccess!\n";
//	std::cout << "Checking in a title...\n";
//	DebugItem* toReturn = greg.checkIn("Firefly Season 1");
//	std::cout <<  "Returned title.\n";
//	toReturn->outputTo(std::cout);
//	std::cout <<  "Patron state is now...\n";
//	greg.outputTo(std::cout);
//	greg.checkOut(toReturn);
//	std::cout <<  "Testing checking out more than allowed.\n";
//	DebugBook* toReject = new DebugBook("50 Shades of Gray");
//	try
//	{
//		greg.checkOut(toReject);
//	}
//	catch (char* rejection_str)
//	{
//		std::cout << rejection_str;
//		std::cout << "Success!\n";
//	}
//	catch (...)
//	{
//		//do nothing
//	}
//	std::cout <<  "Testing complete!\n";
//	getchar();
//}

int _tmain(int argc, _TCHAR* argv[])
{
	//testDebugDate();
	//TestDebugItem();
	//TestDebugMediaAndBook();
	//testPatron();
	std::cout <<  "Creating library full of titles.\n";
	std::ifstream libTitles("BookTitles.txt");
	DebugLibrary frank(DebugDate(), libTitles);
	libTitles.close();
	std::cout <<  "Posting what is available to an adult.\n";
	frank.outputAvailableTo(std::cout, DebugPatron::PatronType::ADULT);
	std::cout <<  "That's a lot!!\n";
	std::cout <<  "Adding a new patron to the library!\n";
	frank.addPatron("Greg", DebugPatron::PatronType::ADULT);
	frank.outputKnownPatronsTo(std::cout);
	std::cout <<  "Making new empty library.\n";
	std::ifstream smallerLibraryInput("TestBatchSave.txt");
	DebugLibrary sally(DebugDate(), smallerLibraryInput);
	smallerLibraryInput.close();
	sally.addPatron("Smith", DebugPatron::PatronType::ADULT);
	sally.outputAvailableTo(std::cout, DebugPatron::PatronType::ADULT);
	std::cout <<  "Adding a couple books...\n";
	sally.addItem("This is my life now.", DebugItem::ITEMTYPES::ADULTBOOK);
	sally.addItem("This is my story", DebugItem::ITEMTYPES::DVD);
	sally.outputAvailableTo(std::cout, DebugPatron::PatronType::ADULT);
	std::cout <<  "Removing one of the books...\n";
	sally.removeItem("This is my story");
	sally.outputAvailableTo(std::cout, "Smith");
	std::cout <<  "Checking out titles now.\n";
	sally.checkoutTitle("This is my life now.", "Smith");
	sally.checkoutTitle(" 1001 Arabian Nights", "Smith");
	sally.outputCheckedOutTo(std::cout);
	sally.outputAvailableTo(std::cout, "Smith");
	std::cout <<  "\nReturning the title now.\n";
	sally.checkinTitle("This is my life now.", "Smith");
	sally.outputTo(std::cout);
	std::cout <<  "Removing patron who still has books...\n";
	sally.removePatron("Smith");
	sally.outputAvailableTo(std::cout, DebugPatron::PatronType::ADULT);
	std::cout <<  "Saving to file now...\n";
	std::ofstream output("TestLibrarySave.txt");
	sally.outputTo(output);
	output.close();
	std::cout <<  "Loading the saved file.\n";
	std::ifstream testLoadFile("TestLibrarySave.txt");
	DebugLibrary slappy(testLoadFile);
	slappy.outputTo(std::cout);
	std::cout <<  "Test complete!\n";

	getchar();
	return 0;
}

