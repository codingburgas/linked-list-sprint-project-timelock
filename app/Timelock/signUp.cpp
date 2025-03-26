#include "signUp.h"

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