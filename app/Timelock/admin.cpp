#include "admin.h"
#include "timeline.h"
#include "prehistoric.h"
#include "classical.h"
#include "middleAge.h"
#include "earlyModern.h"
#include "modern.h"
#include "events.h"
#include "editEvents.h"
#include "deleteEvents.h"
#include "search.h"
#include "addEvents.h"
#include "favourites.h"
#include "accessData.h"

// Display the admin panel with various options
void adminPanel(int page)
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
    cout << "4. Add an event at the beginning.";

    printEndl(2);

    printStrRepeat(" ", 12);
    cout << "5. Add an event at the end.";

    printStrRepeat(" ", 12);
    cout << "6. Edit an event.";

    printStrRepeat(" ", 12);
    cout << "7. Delete an event.";

    printStrRepeat(" ", 12);
    cout << "8. Open favourites.";

    printEndl(2);

    printStrRepeat(" ", 65);
    cout << "9. Approve admin.";

    printEndl(3);
    centerText(purpleColor + "            Choose an option! " + resetColor);

    int option;
    cin >> option;

    switch (option)
    {
    case 1:
        system("cls");
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
        system("cls");
        displaySearchTitle();
        searchByDate(page);
        break;

    case 3:
        system("cls");
        displaySearchTitle();
        searchByEvent(page);
        break;

    case 4:
        system("cls");
        displayAddTitle();
        addEventAtBeginning(page); 
        break;

    case 5:
        system("cls");
        displayAddTitle();
        addEventAtEnd(page); 
        break;

    case 6:
        system("cls");
        displayEventsTitle();
        switch (page)
        {
        case 1:
            displayPrehistoricEvents();
            editPrehistoricEvents();
            break;
        case 2:
            displayClassicalEvents();
            editClassicalEvents();
            break;
        case 3:
            displaymiddleAgeEvents();
            editMiddleAgeEvents();
            break;
        case 4:
            displayearlyModernEvents();
            editEarlyModernEvents();
            break;
        case 5:
            displayModernEvents();
            editModernEvents();
            break;
        }
        break;

    case 7:
        system("cls");
        displayEventsTitle();
        switch (page)
        {
        case 1:
            displayPrehistoricEvents();
            deletePrehistoricEvents();
            break;
        case 2:
            displayClassicalEvents();
            deleteClassicalEvents();
            break;
        case 3:
            displaymiddleAgeEvents();
            deleteMiddleAgeEvents();
            break;
        case 4:
            displayearlyModernEvents();
            deleteEarlyModernEvents();
            break;
        case 5:
            displayModernEvents();
            deleteModernEvents();
            break;
        }
        break;

    case 8:
        system("cls");
        displayEventsTitle();
        switch (page)
        {
        case 1:
            displayFavouritesByEra("Prehistoric");
            break;
        case 2:
            displayFavouritesByEra("Classical");
            break;
        case 3:
            displayFavouritesByEra("Middle Ages");
            break;
        case 4:
            displayFavouritesByEra("Early Modern");
            break;
        case 5:
            displayFavouritesByEra("Modern");
            break;
        }
        break;
    case 9:
        system("cls");
        approveAdmin();
        break;
    }
    
}
