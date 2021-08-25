/*
Nathan Engle
8/25/2021
Program Description: Uses a LinkedList data structure to store, modify, and display rainfall statistics
*/

#include <iostream>
#include "List.h"
#include "Rainfall.h"

using namespace std;

char menu(); //displays a menu to user, collects and verifies input, and returns user choice
void printReport(const List<Rainfall>); //takes a list of months and prints a report listing total, average, most, and least rainfall in inches
Rainfall addMonth(List<Rainfall>); //gets user input for month name and rainfall
void editMonth(List<Rainfall>&); //get user input for month name, searches list, and if found, allows user to edit rainfall amount
double findTotal(const List<Rainfall>);
double findAverage(const List<Rainfall>);
Rainfall findMost(const List<Rainfall>);
Rainfall findLeast(const List<Rainfall>);


int main()
{
	char choice = 's'; //default starting value
	List<Rainfall> listOfMonths;

	while (choice != 'Q')
	{
		choice = menu();
		switch (choice)
		{
		case 'A':
			listOfMonths.insert((listOfMonths.getLength() + 1), addMonth(listOfMonths));
			break;
		case 'E':
			editMonth(listOfMonths);
			break;
		case 'P':
			printReport(listOfMonths);
			break;
		case 'Q':
			break;
		default:
			cout << "Unexpected error occured." << endl;
			break;
		}
	}
	cout << endl << endl;
	system("pause");
	return 0;
}

char menu()
{
	bool valid = false;
	char choice;

	do
	{
		cout << "Enter your choice" << endl << endl;
		cout << " A -- Add a month of statistics" << endl << endl;
		cout << " E -- Edit a month of statistics" << endl << endl;
		cout << " P -- Print report" << endl << endl;
		cout << " Q -- Quit" << endl << endl;
		cout << "Choice: ";
		cin >> choice;
		choice = toupper(choice);

		if (cin.good() && (choice == 'A' || choice == 'E' || choice == 'P' || choice == 'Q'))
		{
			valid = true;
		}
		else
		{
			cin.clear(); //clear state flags checked by good()
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear all input before trying again
			cout << endl << "Invalid input." << endl << endl;
		}
	} while (!valid);

	//clear input buffer
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return choice;
}

void printReport(const List<Rainfall> listOfMonths)
{
	Rainfall most = findMost(listOfMonths);
	Rainfall least = findLeast(listOfMonths);
	cout << endl << endl;
	cout << "Total rainfall: " << findTotal(listOfMonths) << " inches" << endl;
	cout << "Average rainfall: " << findAverage(listOfMonths) << " inches" << endl;
	cout << "Most rainfall: " << most.getMonth() << " had " << most.getRain() << " inches" << endl;
	cout << "Least rainfall: " << least.getMonth() << " had " << least.getRain() << " inches" << endl;
	cout << endl << endl;
}

Rainfall addMonth(List<Rainfall> listOfMonths)
{
	Rainfall newMonth;
	string name;
	double rain;
	bool valid = false;

	cout << "Enter month: ";
	getline(cin, name);
	cout << "the name picked is: " << name << endl;
	newMonth.setMonth(name);
	do
	{
		cout << "\nEnter Rainfall (in inches): ";
		cin >> rain;
		if (cin.good() && rain >= 0)
		{
			valid = true;
			newMonth.setRain(rain);
		}
		else
		{
			cin.clear(); //clear state flags checked by good()
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear all input before trying again
			cout << endl << "Invalid input." << endl << endl;
		}
	} while (!valid);

	return newMonth;
	listOfMonths.insert(listOfMonths.getLength() + 1, newMonth);
}

void editMonth(List<Rainfall>& listOfMonths)
{
	string desiredName;
	double rain;
	int index;
	Rainfall newEntry;
	bool found = false;
	bool valid = false;

	cout << "Enter month: ";
	getline(cin, desiredName);

	for (index = 1; index <= listOfMonths.getLength(); index++)
	{
		if (listOfMonths.getEntry(index).getMonth() == desiredName)
		{
			found = true;
			newEntry = listOfMonths.getEntry(index);
			break;
		}
	}

	if (found)
	{
		do
		{
			cout << "\nEnter Rainfall (in inches): ";
			cin >> rain;
			if (cin.good())
			{
				valid = true;
				newEntry.setRain(rain);
				listOfMonths.setEntry(index, newEntry);
			}
			else
			{
				cin.clear(); //clear state flags checked by good()
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear all input before trying again
				cout << endl << "Invalid input." << endl << endl;
			}
		} while (!valid);
	}
	else
	{
		cout << "Month not found." << endl << endl;
	}
}

double findTotal(const List<Rainfall> listOfMonths)
{
	double total = 0;
	for (int i = 1; i <= listOfMonths.getLength(); i++)
	{
		total = (total + listOfMonths.getEntry(i).getRain());
	}
	return total;
}

double findAverage(const List<Rainfall> listOfMonths)
{
	return (findTotal(listOfMonths) / listOfMonths.getLength());
}

Rainfall findMost(const List<Rainfall> listOfMonths)
{
	double most = -1; //inches of rainfall is compared against this
	int indexOfMost = -1;

	for (int i = 1; i <= listOfMonths.getLength(); i++)
	{
		if (listOfMonths.getEntry(i).getRain() > most)
		{
			indexOfMost = i;
			most = listOfMonths.getEntry(i).getRain();
		}
	}

	return listOfMonths.getEntry(indexOfMost);
}

Rainfall findLeast(const List<Rainfall> listOfMonths)
{
	double least = listOfMonths.getEntry(1).getRain(); //default to first value of list
	int indexOfLeast = 1;

	for (int i = 1; i <= listOfMonths.getLength(); i++)
	{
		if (listOfMonths.getEntry(i).getRain() < least)
		{
			indexOfLeast = i;
			least = listOfMonths.getEntry(i).getRain();
		}
	}

	return listOfMonths.getEntry(indexOfLeast);
}