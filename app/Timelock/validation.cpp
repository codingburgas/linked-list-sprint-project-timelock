#include "validation.h"

// Check if an account with the given username exists
bool doesAccountExist(const string& username)
{
    ACCOUNT* temp = head;

    while (temp)
    {
        if (temp->username == username)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Check if the password is correct for the given username
bool isPasswordCorrect(const string& username, const string& password)
{
    ACCOUNT* temp = head;

    while (temp)
    {
        if (temp->username == username && temp->password == password)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Get the role of the current user
string getCurrentUserRole()
{
    ACCOUNT* current = head;
    while (current != nullptr)
    {
        if (current->username == currentUser)
        {
            return current->role;
        }
        current = current->next;
    }
    return "ROLE Not Found";
}