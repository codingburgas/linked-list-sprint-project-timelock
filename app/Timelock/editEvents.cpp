#include "editEvents.h"
#include "timeline.h"
#include "prehistoric.h"
#include "classical.h"
#include "middleAge.h"
#include "earlyModern.h"
#include "modern.h"

// Edit events from the Prehistoric era
void editPrehistoricEvents()
{
    string redColor = "\033[31m";     // Red
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    int choice;
    while (true)
    {
        centerText(purpleColor + "           Choose an event to edit! " + resetColor);
        cin >> choice;

        switch (choice)
        {
        case 1:
            editEventFile("../data/prehistoric/stoneAge.txt");
            break;
        case 2:
            editEventFile("../data/prehistoric/bronzeAge.txt");
            break;
        case 3:
            editEventFile("../data/prehistoric/IronAge.txt");
            break;
        default:
            printEndl(2);
            centerText(redColor + "         Invalid choice. Please try again." + resetColor);
            printEndl(2);
            continue;
        }

        cout << endl;
        centerText(purpleColor + "          Do you want to edit another event? (Y/N)" + resetColor);
        printEndl(3);

        while (!_kbhit())
        {

        }

        char ch = _getch();
        if (ch == 27)
        {
            system("cls");
            displayTimeline();
            return;
        }
        else if (ch == 'Y' || ch == 'y')
        {
            continue;
        }
        else
        {
            system("cls");
            displayPrehistoric();
            return;
        }
    }
}

// Edit events from the Classical era
void editClassicalEvents()
{
    string redColor = "\033[31m";     // Red
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    int choice;
    while (true)
    {
        centerText(purpleColor + "           Choose an event to edit! " + resetColor);
        cin >> choice;

        switch (choice)
        {
        case 1:
            editEventFile("../data/classical/grecoPersianWars.txt");
            break;
        case 2:
            editEventFile("../data/classical/peloponnesianWar.txt");
            break;
        case 3:
            editEventFile("../data/classical/romanRevolution.txt");
            break;
        case 4:
            editEventFile("../data/classical/romanEmpire.txt");
            break;
        default:
            printEndl(2);
            centerText(redColor + "         Invalid choice. Please try again." + resetColor);
            printEndl(2);
            continue;
        }

        cout << endl;
        centerText(purpleColor + "          Do you want to edit another event? (Y/N)" + resetColor);
        printEndl(3);

        while (!_kbhit())
        {

        }

        char ch = _getch();
        if (ch == 27)
        {
            system("cls");
            displayClassical();
            return;
        }
        else if (ch == 'Y' || ch == 'y')
        {
            continue;
        }
        else
        {
            system("cls");
            displayClassical();
            return;
        }
    }
}

// Edit events from the Middle Ages era
void editMiddleAgeEvents()
{
    string redColor = "\033[31m";     // Red
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    int choice;
    while (true)
    {
        centerText(purpleColor + "           Choose an event to edit! " + resetColor);
        cin >> choice;

        switch (choice)
        {
        case 1:
            editEventFile("../data/middleAge/vikingAge.txt");
            break;
        case 2:
            editEventFile("../data/middleAge/battleOfHastings.txt");
            break;
        case 3:
            editEventFile("../data/middleAge/hundredYearsWar.txt");
            break;
        case 4:
            editEventFile("../data/middleAge/blackDeath.txt");
            break;
        default:
            printEndl(2);
            centerText(redColor + "         Invalid choice. Please try again." + resetColor);
            printEndl(2);
            continue;
        }

        cout << endl;
        centerText(purpleColor + "          Do you want to edit another event? (Y/N)" + resetColor);
        printEndl(3);

        while (!_kbhit())
        {

        }

        char ch = _getch();
        if (ch == 27)
        {
            system("cls");
            displayMiddleAge();
            return;
        }
        else if (ch == 'Y' || ch == 'y')
        {
            continue;
        }
        else
        {
            system("cls");
            displayMiddleAge();
            return;
        }
    }
}

// Edit events from the Early Modern era
void editEarlyModernEvents()
{
    string redColor = "\033[31m";     // Red
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    int choice;
    while (true)
    {
        centerText(purpleColor + "           Choose an event to edit! " + resetColor);
        cin >> choice;

        switch (choice)
        {
        case 1:
            editEventFile("../data/earlyModern/thirtyYearsWar.txt");
            break;
        case 2:
            editEventFile("../data/earlyModern/spanishSuccession.txt");
            break;
        case 3:
            editEventFile("../data/earlyModern/siegeOfVienna.txt");
            break;
        default:
            printEndl(2);
            centerText(redColor + "         Invalid choice. Please try again." + resetColor);
            printEndl(2);
            continue;
        }

        cout << endl;
        centerText(purpleColor + "          Do you want to edit another event? (Y/N)" + resetColor);
        printEndl(3);

        while (!_kbhit())
        {

        }

        char ch = _getch();
        if (ch == 27)
        {
            system("cls");
            displayEarlyModern();
            return;
        }
        else if (ch == 'Y' || ch == 'y')
        {
            continue;
        }
        else
        {
            system("cls");
            displayEarlyModern();
            return;
        }
    }
}

// Edit events from the Modern era
void editModernEvents()
{
    string redColor = "\033[31m";     // Red
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    int choice;
    while (true)
    {
        centerText(purpleColor + "           Choose an event to edit! " + resetColor);
        cin >> choice;

        switch (choice)
        {
        case 1:
            editEventFile("../data/modern/industrialRevolution.txt");
            break;
        case 2:
            editEventFile("../data/modern/WW1.txt");
            break;
        case 3:
            editEventFile("../data/modern/greatDepression.txt");
            break;
        case 4:
            editEventFile("../data/modern/WW2.txt");
            break;
        case 5:
            editEventFile("../data/modern/coldWar.txt");
            break;
        default:
            printEndl(2);
            centerText(redColor + "         Invalid choice. Please try again." + resetColor);
            printEndl(2);
            continue;
        }

        cout << endl;
        centerText(purpleColor + "          Do you want to edit another event? (Y/N)" + resetColor);
        printEndl(3);

        while (!_kbhit())
        {

        }

        char ch = _getch();
        if (ch == 27)
        {
            system("cls");
            displayModern();
            return;
        }
        else if (ch == 'Y' || ch == 'y')
        {
            continue;
        }
        else
        {
            system("cls");
            displayModern();
            return;
        }
    }
}