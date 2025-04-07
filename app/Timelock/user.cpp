#include "user.h"
#include "timeline.h"
#include "prehistoric.h"
#include "classical.h"
#include "middleAge.h"
#include "earlyModern.h"
#include "modern.h"
#include "events.h"
#include "search.h"

void userPanel(int page)
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    printStrRepeat(" ", 12);
    cout << "1. View all events.";

    printStrRepeat(" ", 8);
    cout << "2. Search by year.";

    printStrRepeat(" ", 8);
    cout << "3. Search by event.";

    printStrRepeat(" ", 8);
    cout << "4. Attempt quiz.";

    printStrRepeat(" ", 8);
    cout << "5. Open favourites."; // TODO: Add favourites functionality

    printEndl(3);
    centerText(purpleColor + "            Choose an option! " + resetColor);

    int option;
    cin >> option;

    system("cls");

    switch (option)
    {
    case 1:
        displayEventsTitle();
        switch (page)
        {
        case 1:
            displayPrehistoricEvents();
            displayPrehistoricEventsInfo();
            break;
        case 2:
            displayClassicalEvents();
            displayClassicalEventsInfo();
            break;
        case 3:
            displaymiddleAgeEvents();
            displayMiddleAgeEventsInfo();
            break;
        case 4:
            displayearlyModernEvents();
            displayEarlyModernEventsInfo();
            break;
        case 5:
            displayModernEvents();
            displayModernEventsInfo();
            break;
        }
        break;
    case 2:
        displaySearchTitle();
        searchByDate(page); 
        break;
    case 3:
        displaySearchTitle();
        searchByEvent(page); 
        break;
    case 4:
        displayQuizTitle();
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
    case 5:
        // TODO: Implement favourites later
        // system("cls");
        // displayFavourites(page);
        break;
    default:
        cout << "\nInvalid option. Returning to timeline.\n";
        break;
    }
}
