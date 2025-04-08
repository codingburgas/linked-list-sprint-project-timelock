#include "startingScreen.h"

// Display the starting screen with options to sign up or log in
void displayStartingScreen()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    const string title[11] = {
    "",
    "         .**************..*********..***************..*************..*************..**************..**************..************.",
    "         *   .________.      .__.       _.      ._      .________.      .__.            ________       .________.     .__.  __.   *",
    "         *   |___  ___|      |  |      |  \\    /  |     |  ______|      |  |           /  .__.  \\      |  ______|     |  | /  /   *",
    "         *      |  |         |  |      |   \\  /   |     |  |_____       |  |           |  |  |  |      |  |           |  |/  /    *",
    "         *      |  |         |  |      |    \\/    |     |  ______|      |  |           |  |  |  |      |  |           |     /     *",
    "         *      |  |         |  |      |  |\\  /|  |     |  |_____       |  |____.      |  |__|  |      |  |_____.     |  |\\  \\    *",
    "         *      |__|         |__|      |__| \\/ |__|     |________|      |_______|      \\________/      |________|     |__| \\__\\   *",
    "         *.              ..         ..               ..             ..             ..              ..              ..            .*",
    "         **************  *********  ***************  *************  *************  **************  **************  ************",
    ""
    };

    printEndl(2);

    for (int i = 0; i < 11; i++)
    {
        centerText(purpleColor + title[i] + resetColor);
        cout << endl;
    }

    printEndl(4);

    printStrRepeat(" ", 2);
    cout << "Select a choice!";

    printStrRepeat(" ", 33);
    cout << "1.SIGN UP";
    printStrRepeat(" ", 30);
    cout << "2.LOGIN" << endl;

    chooseAnswer();

    printEndl(2);
}

// Handle the user's choice to sign up or log in
void chooseAnswer()
{
    string redColor = "\033[31m";     // Red
    string resetColor = "\033[37m";   // White 

    int choice;
    bool isValid = false;

    while (!isValid)
    {
        cout << endl;
        printStrRepeat(" ", 2);
        cout << "Your choice: ";
        cin >> choice;
        cout << endl;

        if (choice == 1)
        {
            isValid = true;
            system("cls");
            displaySignUp();
        }
        else if (choice == 2)
        {
            isValid = true;
            system("cls");
            displayLogin();
        }
        else
        {
            cout << redColor << "Invalid choice! Choose 1. to SIGN UP or 2. to LOGIN" << resetColor << endl;
        }
    }
}