#include "startingScreen.h"


void displayStartingScreen()
{

    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    const string title[11] = {
    "",
    "      .**************..*********..****************..*************..*************..**************..**************..************.",
    "      *   .________.      .__.       _.      ._      .________.      .__.            ________       .________.     .__.  __.   *",
    "      *   |___  ___|      |  |      |  \\    /  |     |  ______|      |  |           /  .__.  \\      |  ______|     |  | /  /   *",
    "      *      |  |         |  |      |   \\  /   |     |  |_____       |  |           |  |  |  |      |  |           |  |/  /    *",
    "      *      |  |         |  |      |    \\/    |     |  ______|      |  |           |  |  |  |      |  |           |     /     *",
    "      *      |  |         |  |      |  |\\  /|  |     |  |_____       |  |____.      |  |__|  |      |  |_____.     |  |\\  \\    *",
    "      *      |__|         |__|      |__| \\/ |__|     |________|      |_______|      \\________/      |________|     |__| \\__\\   *",
    "      *.              ..        ..                ..             ..             ..              ..              ..            .*",
    "       **************  ********  ****************  *************  *************  **************  **************  ************",
    ""
    };


    for (int i = 0; i < 2; i++)
    {
        cout << endl;
    }

    for (int i = 0; i < 11; i++)
    {
        centerText(purpleColor + title[i] + resetColor);
        cout << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        cout << endl;
    }

    cout << "Select a choice!";

    cout << setw(38) << "1.SIGN UP" << setw(30) << "2.LOGIN" << endl;

    chooseAnswer();

    for (int i = 0; i < 2; i++)
    {
        cout << endl;
    }

    displayTimeline();
}

void chooseAnswer()
{
    cout << endl << "Your choice: ";
    int choice;
    cin >> choice;
    cout << endl;

    if (choice == 1)
    {
        system("cls");
        displaySignUp();
    }
    else if (choice == 2)
    {
        system("cls");
        displayLogin();
    }
    else
    {
        cout << "Invalid choice! Choose 1. to SIGN UP or 2. to LOGIN" << endl;
    }
}
