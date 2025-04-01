#include "user.h"
#include "timeline.h"


void userPanel() 
{
	printStrRepeat(" ", 2);
	cout << "1. Search by year." << endl;

	printStrRepeat(" ", 2);
	cout << "2. Search by event." << endl;

	printStrRepeat(" ", 2);
	cout << "3. View all events" << endl;

	printStrRepeat(" ", 2);
	cout << "4. Launch quiz" << endl;

	cout << endl;
	printStrRepeat(" ", 2);
	cout << "Choose an option: ";
	int option;
	cin >> option;
}