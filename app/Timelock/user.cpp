#include "user.h"
#include "timeline.h"
#include "prehistoric.h"
#include "classical.h"
#include "middleAge.h"
#include "earlyModern.h"
#include "modern.h"

void userPanel(int page) 
{
    
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

	printStrRepeat(" ", 7);
	cout << "1. View all events.";

	printStrRepeat(" ", 5);
	cout << "2. Search by year.";

	printStrRepeat(" ", 5);
	cout << "3. Search by event.";

	printStrRepeat(" ", 5);
	cout << "4. View all events.";

	printStrRepeat(" ", 5);
	cout << "5. Attempt quiz.";

    printStrRepeat(" ", 5);
    cout << "6. Open favourites.";

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
        switch (page)
        {
        case 1:
            displayPrehistoricQuiz();
            break;
        case 2:
            displayClassicalQuiz();
            break;
        case 3:
            displaymiddleAgeQuiz();
            break;
        case 4:
            displayearlyModernQuiz();
            break;
        case 5:
            displayModernQuiz();
            break;
        }
        break;
    case 6:
        system("cls");
        break;
    }
	
}