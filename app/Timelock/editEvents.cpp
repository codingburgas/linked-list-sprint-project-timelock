#include "editEvents.h"

void editPrehistoricEvents()
{
    string redColor = "\033[31m";     // Red
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    int choice;
    centerText(purpleColor + "      Choose an event to edit! " + resetColor);
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
        centerText(redColor + "Invalid choice."  + resetColor);
        cout << endl;
        break;
    }
}

void editClassicalEvents()
{
    string redColor = "\033[31m";     // Red
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    int choice;
    centerText(purpleColor + "      Choose an event to edit! " + resetColor);
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
        centerText(redColor + "Invalid choice." + resetColor);
        cout << endl;
        break;
    }
}

void editMiddleAgeEvents()
{
    string redColor = "\033[31m";     // Red
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    int choice;
    centerText(purpleColor + "      Choose an event to edit! " + resetColor);
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
        centerText(redColor + "Invalid choice." + resetColor);
        cout << endl;
        break;
    }
}

void editEarlyModernEvents()
{
    string redColor = "\033[31m";     // Red
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    int choice;
    centerText(purpleColor + "      Choose an event to edit! " + resetColor);
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
        centerText(redColor + "Invalid choice." + resetColor);
        cout << endl;
        break;
    }
}

void editModernEvents()
{
    string redColor = "\033[31m";     // Red
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    int choice;
    centerText(purpleColor + "      Choose an event to edit! " + resetColor);
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
        centerText(redColor + "Invalid choice." + resetColor);
        cout << endl;
        break;
    }
}