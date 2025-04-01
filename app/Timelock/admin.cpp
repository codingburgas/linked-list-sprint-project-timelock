#include "admin.h"
#include "timeline.h"

void adminPanel() 
{
	printStrRepeat(" ", 2);
	cout << "1. Search by year." << endl;

	printStrRepeat(" ", 2);
	cout << "2. Search by event." << endl;

	printStrRepeat(" ", 2);
	cout << "3. Add an event in the begining." << endl;

	printStrRepeat(" ", 2);
	cout << "4. Add an event at the end." << endl;

	printStrRepeat(" ", 2);
	cout << "5. Edit an event." << endl;

	printStrRepeat(" ", 2);
	cout << "6. Delete an event." << endl;

	cout << endl;
	printStrRepeat(" ", 2);
	cout << "Choose an option: ";
	int option;
	cin >> option;

}
