#include "login.h"
#include "accessData.h"
#include "validation.h"
#include "admin.h"
#include "user.h"

void displayLogin()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    const string title[11] = {
    "",
    "               .**************..**************..***************..**********..**************.",
    "               *   .__.            ________        ________         .__.       ._.    ._    *",
    "               *   |  |           /  .__.  \\      /   _____|        |  |       |   \\ |  |   *",
    "               *   |  |           |  |  |  |      |  |              |  |       |    \\|  |   *",
    "               *   |  |           |  |  |  |      |  |  .__.        |  |       |  .     |   *",
    "               *   |  |____.      |  |__|  |      |  |__|  |        |  |       |  |\\    |   *",
    "               *   |_______|      \\________/      \\________/        |__|       |__| \\.__|   *",
    "               *.              ..             ..               ..          ..              .*",
    "                **************  *************  ***************  **********  ************** ",
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

    login();
}

void login()
{
    loadAccounts();
    string username, password;
    cout << "Enter your username: "; cin >> username;
    cout << "Enter your password: "; cin >> password;
    if (!doesAccountExist(username) || !isPasswordCorrect(username, password)) {
        cout << "Invalid username or password!" << endl;
        return;
    }
    strcpy_s(currentUser, username.c_str());
    string role = getRole(username);
    cout << "Login successful! Role: " << getRole(username) << endl;

    if (role == "admin") {
        adminPanel();  
    }
    else {
        userPanel();  
    }
}