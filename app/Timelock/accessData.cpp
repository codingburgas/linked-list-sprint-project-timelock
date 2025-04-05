#include "accessData.h"

ACCOUNT* head = nullptr;
char currentUser[25] = "";

void loadAccounts() 
{
    ifstream file("../data/accounts.csv");
    string line, username, password, role, progressStr; 
    int progress;

    while (getline(file, line)) 
    {
        stringstream ss(line);
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, role, ',');
        getline(ss, progressStr, ',');

        if (progressStr.empty())
            progress = 0;
        else
            progress = stoi(progressStr);


        ACCOUNT* newAcc = new ACCOUNT{ username, password, role,progress, head };
        head = newAcc;
    }
    file.close();
}

void saveAccount(const string& username, const string& password, const string& role,int progress)
{
    ofstream file("../data/accounts.csv", ios::app);
    file << username << "," << password << "," << role <<","<<progress << endl;
    file.close();

    ACCOUNT* newAcc = new ACCOUNT{ username, password, role, progress,head };
    head = newAcc;
}
void loadUserProgress()
{
    ACCOUNT* temp = head;
    while (temp != nullptr)
    {
        if (temp->username == currentUser)
        {
            progres = temp->progress; 
            break;
        }
        temp = temp->next;
    }
}