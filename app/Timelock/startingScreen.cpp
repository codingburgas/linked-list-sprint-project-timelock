#include "startingScreen.h"


void displayStartingScreen()
{
    string timelock[11] = {
        "                                                                                                                        ",
        "      .**************..*********..****************..*************..*************..**************..**************..*************.",
        "      *   .________.      .__.       _.      ._      .________.      .__.            ________       .________.     .__.  __.   *",
        "      *   |___  ___|      |  |      |  \\    /  |     |  ______|      |  |           /  .__.  \\      |  ______|     |  | /  /   *",
        "      *      |  |         |  |      |   \\  /   |     |  |_____       |  |           |  |  |  |      |  |           |  |/  /    *",
        "      *      |  |         |  |      |    \\/    |     |  ______|      |  |           |  |  |  |      |  |           |     /     *",
        "      *      |  |         |  |      |  |\\  /|  |     |  |_____       |  |____.      |  |__|  |      |  |_____.     |  |\\  \\    *",
        "      *      |__|         |__|      |__| \\/ |__|     |________|      |_______|      \\________/      |________|     |__| \\__\\   *",
        "      *.              ..        ..                ..             ..             ..              ..              ..            .*",
        "        **************  ********  ****************  *************  *************  **************  **************  ************",
        "                                                                                                                         "
    };
    
    for (int i = 0; i < 4; i++)
    {
        cout << endl;
    }
    
    for (int i = 0; i < 11; i++) 
    {
        cout << timelock[i] << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        cout << endl;
    }

    for (int i = 0; i < 49; i++)
    {
        cout << " ";
    }

    cout << "1.REGISTER                     2.LOGIN" << endl;

    for (int i = 0; i < 2; i++)
    {
        cout << endl;
    }
    chooseAnswer();
}

void chooseAnswer()
{
    cout << "Choose an answer:" << endl;
    int answer;
    cin >> answer;

    if (answer == 1)
    {
        cout << "Start your registration. Please fill the questions bellow." << endl;
    }
    else if (answer == 2)
    {
        cout << "Login to an existing account." << endl;
    }
    else
    {
        cout << "Invalid answer! Choose 1. to REGISTER or 2. to LOGIN" << endl;
    }
}
