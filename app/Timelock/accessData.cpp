#include "accessData.h"

ACCOUNT* head = nullptr;
char currentUser[25] = "";

void loadAccounts() 
{
    ifstream file("../data/accounts.csv");
    string line, username, password, role;

    while (getline(file, line)) 
    {
        stringstream ss(line);
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, role, ',');
        ACCOUNT* newAcc = new ACCOUNT{ username, password, role, head };
        head = newAcc;
    }
    file.close();
}

void saveAccount(const string& username, const string& password, const string& role) 
{
    ofstream file("../data/accounts.csv", ios::app);
    file << username << "," << password << "," << role << "\n";
    file.close();

    ACCOUNT* newAcc = new ACCOUNT{ username, password, role, head };
    head = newAcc;
}
