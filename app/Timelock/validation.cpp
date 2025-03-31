#include "validation.h"

bool doesAccountExist(const string& username) {
    ACCOUNT* temp = head;
    while (temp) {
        if (temp->username == username) return true;
        temp = temp->next;
    }
    return false;
}

bool isPasswordCorrect(const string& username, const string& password) {
    ACCOUNT* temp = head;
    while (temp) {
        if (temp->username == username && temp->password == password) return true;
        temp = temp->next;
    }
    return false;
}

string getRole(const string& username) {
    ACCOUNT* temp = head;
    while (temp) {
        if (temp->username == username) return temp->role;
        temp = temp->next;
    }
    return "";
}