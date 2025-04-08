#include "deleteEvents.h"
#include "timeline.h"

// Delete events from the Prehistoric era
void deletePrehistoricEvents()
{
    string redColor = "\033[31m";     // Red
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    int choice;
    while (true)
    {
        centerText(purpleColor + "           Choose an event to delete! " + resetColor);
        cin >> choice;

        switch (choice)
        {
        case 1:
            deleteEventFile("../data/prehistoric/stoneAge.txt");
            break;
        case 2:
            deleteEventFile("../data/prehistoric/bronzeAge.txt");
            break;
        case 3:
            deleteEventFile("../data/prehistoric/IronAge.txt");
            break;
        default:
            printEndl(2);
            centerText(redColor + "         Invalid choice. Please try again." + resetColor);
            printEndl(2);
            continue;
        }

        cout << endl;
        centerText(purpleColor + "              Do you want to delete another event? (Y/N)" + resetColor);
        printEndl(3);

        while (!_kbhit())
        {

        }

        char ch = _getch();
        if (ch == 27)
        {
            clearScreen();
            displayTimeline();
            return;
        }
        else if (ch == 'Y' || ch == 'y')
        {
            continue;
        }
        else
        {
            clearScreen();
            displayTimeline();
            return;
        }
    }
}

// Delete events from the Classical era
void deleteClassicalEvents()
{
    string redColor = "\033[31m";     // Red
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    int choice;
    while (true)
    {
        centerText(purpleColor + "           Choose an event to delete! " + resetColor);
        cin >> choice;

        switch (choice)
        {
        case 1:
            deleteEventFile("../data/classical/grecoPersianWars.txt");
            break;
        case 2:
            deleteEventFile("../data/classical/peloponnesianWar.txt");
            break;
        case 3:
            deleteEventFile("../data/classical/romanRevolution.txt");
            break;
        case 4:
            deleteEventFile("../data/classical/romanEmpire.txt");
            break;
        default:
            printEndl(2);
            centerText(redColor + "         Invalid choice. Please try again." + resetColor);
            printEndl(2);
            continue;
        }

        cout << endl;
        centerText(purpleColor + "              Do you want to delete another event? (Y/N)" + resetColor);
        printEndl(3);

        while (!_kbhit())
        {

        }

        char ch = _getch();
        if (ch == 27)
        {
            clearScreen();
            displayTimeline();
            return;
        }
        else if (ch == 'Y' || ch == 'y')
        {
            continue;
        }
        else
        {
            clearScreen();
            displayTimeline();
            return;
        }
    }
}

// Delete events from the Middle Ages era
void deleteMiddleAgeEvents()
{
    string redColor = "\033[31m";     // Red
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    int choice;
    while (true)
    {
        centerText(purpleColor + "           Choose an event to delete! " + resetColor);
        cin >> choice;

        switch (choice)
        {
        case 1:
            deleteEventFile("../data/middleAge/vikingAge.txt");
            break;
        case 2:
            deleteEventFile("../data/middleAge/battleOfHastings.txt");
            break;
        case 3:
            deleteEventFile("../data/middleAge/hundredYearsWar.txt");
            break;
        case 4:
            deleteEventFile("../data/middleAge/blackDeath.txt");
            break;
        default:
            printEndl(2);
            centerText(redColor + "         Invalid choice. Please try again." + resetColor);
            printEndl(2);
            continue;
        }

        cout << endl;
        centerText(purpleColor + "              Do you want to delete another event? (Y/N)" + resetColor);
        printEndl(3);

        while (!_kbhit())
        {

        }

        char ch = _getch();
        if (ch == 27)
        {
            clearScreen();
            displayTimeline();
            return;
        }
        else if (ch == 'Y' || ch == 'y')
        {
            continue;
        }
        else
        {
            clearScreen();
            displayTimeline();
            return;
        }
    }
}

// Delete events from the Early Modern era
void deleteEarlyModernEvents()
{
    string redColor = "\033[31m";     // Red
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    int choice;
    while (true)
    {
        centerText(purpleColor + "           Choose an event to delete! " + resetColor);
        cin >> choice;

        switch (choice)
        {
        case 1:
            deleteEventFile("../data/earlyModern/thirtyYearsWar.txt");
            break;
        case 2:
            deleteEventFile("../data/earlyModern/spanishSuccession.txt");
            break;
        case 3:
            deleteEventFile("../data/earlyModern/siegeOfVienna.txt");
            break;
        default:
            printEndl(2);
            centerText(redColor + "         Invalid choice. Please try again." + resetColor);
            printEndl(2);
            continue;
        }

        cout << endl;
        centerText(purpleColor + "              Do you want to delete another event? (Y/N)" + resetColor);
        printEndl(3);

        while (!_kbhit())
        {

        }

        char ch = _getch();
        if (ch == 27)
        {
            clearScreen();
            displayTimeline();
            return;
        }
        else if (ch == 'Y' || ch == 'y')
        {
            continue;
        }
        else
        {
            clearScreen();
            displayTimeline();
            return;
        }
    }
}

// Delete events from the Modern era
void deleteModernEvents()
{
    string redColor = "\033[31m";     // Red
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    int choice;
    while (true)
    {
        centerText(purpleColor + "           Choose an event to delete! " + resetColor);
        cin >> choice;

        switch (choice)
        {
        case 1:
            deleteEventFile("../data/modern/industrialRevolution.txt");
            break;
        case 2:
            deleteEventFile("../data/modern/WW1.txt");
            break;
        case 3:
            deleteEventFile("../data/modern/greatDepression.txt");
            break;
        case 4:
            deleteEventFile("../data/modern/WW2.txt");
            break;
        case 5:
            deleteEventFile("../data/modern/coldWar.txt");
            break;
        default:
            printEndl(2);
            centerText(redColor + "         Invalid choice. Please try again." + resetColor);
            printEndl(2);
            continue;
        }

        cout << endl;
        centerText(purpleColor + "              Do you want to delete another event? (Y/N)" + resetColor);
        printEndl(3);

        while (!_kbhit())
        {

        }

        char ch = _getch();
        if (ch == 27)
        {
            clearScreen();
            displayTimeline();
            return;
        }
        else if (ch == 'Y' || ch == 'y')
        {
            continue;
        }
        else
        {
            clearScreen();
            displayTimeline();
            return;
        }
    }
}