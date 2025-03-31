#include "signUp.h"
#include "accessData.h"
#include "validation.h"

void displaySignUp()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    const string title[21] = {
    "",
    "                .**************..**********..*************..**************.",
    "                *     ______        .__.       ________       ._.    ._    *",
    "                *    '  ____|       |  |      /   _____|      |   \\ |  |   *",
    "                *   |  (__          |  |      |  |            |    \\|  |   *",
    "                *    '.___ `.       |  |      |  |  .__.      |  .     |   *",
    "                *    _____)  |      |  |      |  |__|  |      |  |\\    |   *",
    "                *   |______.'       |__|      \\________/      |__| \\.__|   *",
    "                *.             ..          ..             ..              .*",
    "                *************  **********  *************  **************",
    "",
    "                .**************..**************.",
    "                *   .__.  .__.       _______     *",
    "                *   |  |  |  |      |   __  \\    *",
    "                *   |  |  |  |      |  |__|  |   *",
    "                *   |  |  |  |      |   ____/    *",
    "                *   |  |__|  |      |  |         *",
    "                *   \\________/      |__|         *",
    "                *.              ..              .*",
    "                 **************  **************",
    ""
    };


    for (int i = 0; i < 2; i++)
    {
        cout << endl;
    }

    for (int i = 0; i < 21; i++)
    {
        centerText(purpleColor + title[i] + resetColor);
        cout << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        cout << endl;
    }
    signUp();
}


void signUp()
{
    loadAccounts();
    string username, password, confirmPassword, role;
    cout << "Select a username: "; cin >> username;
    if (doesAccountExist(username)) {
        cout << "Username already exists!" << endl;
        return;
    }
    cout << "Select a password: "; cin >> password;
    cout << "Confirm password: "; cin >> confirmPassword;
    if (password != confirmPassword) {
        cout << "Passwords do not match!" << endl;
        return;
    }
    cout << "Select a role (admin/user): "; cin >> role;
    if (role != "admin" && role != "user") {
        cout << "Invalid role!" << endl;
        return;
    }
    saveAccount(username, password, role);
    cout << "SIGN UP successful!" << endl;
}