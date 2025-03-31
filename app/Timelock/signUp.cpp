#include "signUp.h"

void displaySignUp()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    const string title[21] = {
    "",
    "                   .**************..**********..*************..**************.",
    "                   *     ______        .__.       ________       ._.    ._    *",
    "                   *    '  ____|       |  |      /   _____|      |   \\ |  |   *",
    "                   *   |  (__          |  |      |  |            |    \\|  |   *",
    "                   *    '.___ `.       |  |      |  |  .__.      |  .     |   *",
    "                   *    _____)  |      |  |      |  |__|  |      |  |\\    |   *",
    "                   *   |______.'       |__|      \\________/      |__| \\.__|   *",
    "                   *.             ..          ..             ..              .*",
    "                     *************  **********  *************  **************",
    "",
    "                                 .**************..*************.",
    "                                *   .__.  .__.       _______    *",
    "                                *   |  |  |  |      |   __  \\   *",
    "                                *   |  |  |  |      |  |__|  |  *",
    "                                *   |  |  |  |      |   ____/   *",
    "                                *   |  |__|  |      |  |        *",
    "                                *   \\________/      |__|        *",
    "                                *.              ..             .*",
    "                                  **************  *************"   
    };


    for (int i = 0; i < 2; i++)
    {
        cout << endl;
    }

    for (int i = 0; i < 21; i++)
    {
        cout << purpleColor << title[i] << resetColor << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        cout << endl;
    }
}


void signUp()
{
	cout << "Start your registration. Please fill the questions bellow." << endl << endl;
	
	string username, password, confirmPassword, role;

	cout << "Select a username: ";
	cin >> username;
	cout << endl;

	cout << "Select a password: ";
	cin >> password;
	cout << endl;

	cout << "Confirm password: ";
	cin >> confirmPassword;
	cout << endl;

	cout << "Select a role (admin / user): ";
	cin >> role;
	cout << endl;

	if (password == confirmPassword)
	{
		cout << "SIGN UP successful";
	}
	else
	{
		cout << "Passwords don't match! Try confirming your password again!";
	}

}