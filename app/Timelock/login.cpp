#include "login.h"

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
    "                 **************  *************  ***************  **********  ************** ",
    ""
    };


    for (int i = 0; i < 2; i++)
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

    login();
}

void login()
{
	cout << "Login to an existing account." << endl;

	string username, password;

	cout << "Enter your username: ";
	cin >> username;
	cout << endl;

	cout << "Enter your password: ";
	cin >> password;
	cout << endl;


}