#include "login.h"
#include "accessData.h"
#include "validation.h"
#include "admin.h"
#include "user.h"
#include "timeline.h"
#include "startingScreen.h"

void displayLogin()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    const string title[11] = {
    "",
    "              .**************..*************..***************..**********..**************. ",
    "             *   .__.            ________        ________         .__.       ._.    ._    *",
    "             *   |  |           /  .__.  \\      /   _____|        |  |       |   \\ |  |   *",
    "             *   |  |           |  |  |  |      |  |              |  |       |    \\|  |   *",
    "             *   |  |           |  |  |  |      |  |  .__.        |  |       |  .     |   *",
    "             *   |  |____.      |  |__|  |      |  |__|  |        |  |       |  |\\    |   *",
    "             *   |_______|      \\________/      \\________/        |__|       |__| \\.__|   *",
    "             *.              ..             ..               ..          ..              .*",
    "              **************  *************  ***************  **********  ************** ",
    ""
    };

    printEndl(2);

    for (int i = 0; i < 11; i++)
    {
        centerText(purpleColor + title[i] + resetColor);
        cout << endl;
    }

    printEndl(2);

    printStrRepeat(" ", 8);

    centerText(purpleColor + "LOGIN " + resetColor + "to an existing account.");

    printEndl(4);

    login();
    
}

void login()
{
    string redColor = "\033[31m";     // Red
    string greenColor = "\033[32m";   // Green
    string resetColor = "\033[37m";   // White 



    loadAccounts();

    string username, password;

    bool validUsername = false;
    while (!validUsername)
    {
        centerText("    Enter your USERNAME: ");
        cin >> username;

        if (!doesAccountExist(username))
        {
            cout << endl;
            centerText(redColor + "                Username does not exist! Try again." + resetColor);
            printEndl(2);
        }
        else
        {
            validUsername = true;
        }
    }

    bool validPassword = false;
    while (!validPassword)
    {
        centerText("    Enter your PASSWORD: ");
        cin >> password;

        if (!isPasswordCorrect(username, password))
        {
            cout << endl;
            centerText(redColor + "                Incorrect password! Try again." + resetColor);
            printEndl(2);
        }
        else
        {
            validPassword = true;
        }
    }

    strcpy_s(currentUser, username.c_str());
    string role = getCurrentUserRole();

    cout << endl;
    centerText(greenColor + "                  Login successful! You are logged in as " + role + "." + resetColor);

    sleep_for(seconds(2));

    system("cls"); 

    displayTimeline();
}