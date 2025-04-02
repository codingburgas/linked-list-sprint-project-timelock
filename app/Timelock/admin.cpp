#include "admin.h"
#include "timeline.h"

void adminPanel() 
{
	string resetColor = "\033[37m";   // White 
	string purpleColor = "\033[35m";  // Purple

	printStrRepeat(" ", 12);
	cout << "1. View all events.";

	printStrRepeat(" ", 12);
	cout << "2. Search by year.";

	printStrRepeat(" ", 12);
	cout << "3. Search by event.";

	printStrRepeat(" ", 12);
	cout << "4. Add an event in the begining.";

	printEndl(2);

	printStrRepeat(" ", 12);
	cout << "5. Add an event at the end.";

	printStrRepeat(" ", 12);
	cout << "6. Edit an event.";

	printStrRepeat(" ", 12);
	cout << "7. Delete an event.";

	printStrRepeat(" ", 12);
	cout << "8. Open favourites.";

	printEndl(3);
	centerText(purpleColor + "            Choose an option! " + resetColor);

	int option;
	cin >> option;

	switch (option)
	{
	case 1:
		system("cls");
		break;
	case 2:
		system("cls");
		break;
	case 3:
		system("cls");
		break;
	case 4:
		system("cls");
		break;
	case 5:
		system("cls");
		break;
	case 6:
		system("cls");
		break;
	case 7:
		system("cls");
		break;
	case 8: 
		system("cls");
		break;
	}
}
