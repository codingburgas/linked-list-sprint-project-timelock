#include "startingScreen.h"
#include "title.h"

void displayStartingScreen()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple


    for (int i = 0; i < 4; i++)
    {
        cout << endl;
    }

    for (int i = 0; i < 11; i++)
    {
        cout << purpleColor << title[i] << resetColor << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        cout << endl;
    }

    cout << "Select a choice!";

    for (int i = 0; i < 33; i++)
    {
        cout << " ";
    }

    cout << "1.SIGN UP                     2.LOGIN" << endl;

    for (int i = 0; i < 2; i++)
    {
        cout << endl;
    }

    displayTimeline();
}

void chooseAnswer()
{
    cout << "Your choice: ";
    int choice;
    cin >> choice;
    cout << endl;

    if (choice == 1)
    {
        signUp();
    }
    else if (choice == 2)
    {
        login();
    }
    else
    {
        cout << "Invalid choice! Choose 1. to SIGN UP or 2. to LOGIN" << endl;
    }
}
