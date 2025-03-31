#include "signUp.h"
#include "accessData.h"
#include "validation.h"
#include "admin.h"
#include "user.h"
#include "timeline.h"

void displaySignUp()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    const string title[11] = {
    "",
    " .*************..**********..*************..**************.                   .**************..**************.",
    "  *     ______        .__.       ________       ._.    ._    *                 *   .__.  .__.       _______     *",
    "  *    '  ____|       |  |      /   _____|      |   \\ |  |   *                 *   |  |  |  |      |   __  \\    *",
    "  *   |  (__          |  |      |  |            |    \\|  |   *                 *   |  |  |  |      |  |__|  |   *",
    "  *    '.___ `.       |  |      |  |  .__.      |  .     |   *                 *   |  |  |  |      |   ____/    *",
    "  *    _____)  |      |  |      |  |__|  |      |  |\\    |   *                 *   |  |__|  |      |  |         *",
    " *   |______.'       |__|      \\________/      |__| \\.__|   *                 *   \\________/      |__|         *",
    "  *.             ..          ..             ..              .*                 *.              ..              .*",
    "  *************  **********  *************  **************                     **************  **************",
    ""
    };

    printEndl(2);

    for (int i = 0; i < 11; i++)
    {
        centerText(purpleColor + title[i] + resetColor);
        cout << endl;
    }

    printEndl(2);

    printStrRepeat(" ", 10);

    centerText(resetColor + "Start " + purpleColor + "SIGNING UP" + resetColor + ". Please fill the questions bellow." + resetColor);
    
    printEndl(4);

    signUp();
}


void signUp()
{
    string redColor = "\033[31m";     // Red
    string greenColor = "\033[32m";   // Green
    string resetColor = "\033[37m";   // White 

    loadAccounts();

    string username, password, confirmPassword, role;

    bool validUsername = false;
    while (!validUsername)
    {
        centerText("Select a USERNAME: ");
        cin >> username;

        if (doesAccountExist(username))
        {
            cout << endl;
            centerText(redColor + "          This username already exists! Try a new one!" + resetColor);
            printEndl(2);
        }
        else
        {
            validUsername = true;
        }
    }

    bool passwordsMatch = false;
    while (!passwordsMatch)
    {
        centerText("Select a PASSWORD: ");
        cin >> password;

        centerText("Confirm PASSWORD: ");
        cin >> confirmPassword;

        if (password != confirmPassword)
        {
            cout << endl;
            centerText(redColor + "           Passwords do not match! Try again!" + resetColor);
            printEndl(2);
        }
        else
        {
            passwordsMatch = true;
        }
    }

    bool validRole = false;
    while (!validRole)
    {
        centerText("Select a role (admin/user): ");
        cin >> role;

        if (role != "admin" && role != "user")
        {
            cout << endl;
            centerText(redColor + "            Invalid role! Choose between USER and ADMIN" + resetColor);
            printEndl(2);
        }
        else
        {
            validRole = true;
        }
    }

    saveAccount(username, password, role);

    cout << endl;
    centerText(greenColor + "             SIGN UP successful!" + resetColor);

    sleep_for(seconds(2));

    system("cls");

    displayTimeline();
}