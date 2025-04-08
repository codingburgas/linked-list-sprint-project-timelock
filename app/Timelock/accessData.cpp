#include "accessData.h"

ACCOUNT* head = nullptr;
char currentUser[25] = "";

// Load all accounts from a CSV file into a linked list
void loadAccounts()
{
    ifstream file("../data/accounts.csv");
    string line, username, password, role, progressStr;
    int progress;

    head = nullptr;

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

        ACCOUNT* newAcc = new ACCOUNT{ username, password, role, progress, head };
        head = newAcc;
    }
    file.close();
}

// Save a new account to the CSV file and update the linked list
void saveAccount(const string& username, const string& password, const string& role, int progress)
{
    ofstream file("../data/accounts.csv", ios::app);
    file << username << "," << password << "," << role << "," << progress << endl;
    file.close();

    ACCOUNT* newAcc = new ACCOUNT{ username, password, role, progress, head };
    head = newAcc;
}

// Load the progress of the current user from the linked list
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

// Save the progress of the current user to the CSV file and update the linked list
void saveUserProgress()
{
    ACCOUNT* temp = head;
    while (temp != nullptr)
    {
        if (temp->username == currentUser)
        {
            temp->progress = progres;
            break;
        }
        temp = temp->next;
    }

    ifstream inFile("../data/accounts.csv");
    vector<string> lines;
    string line;

    while (getline(inFile, line))
    {
        stringstream ss(line);
        string username, password, role, progressStr;
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, role, ',');
        getline(ss, progressStr, ',');

        if (username == currentUser)
        {
            line = username + "," + password + "," + role + "," + to_string(progres);
        }

        lines.push_back(line);
    }
    inFile.close();

    ofstream outFile("../data/accounts.csv", ios::trunc);
    for (int i = 0; i < lines.size(); i++)
    {
        outFile << lines[i] << endl;
    }
    outFile.close();
}

// Approve pending admin accounts based on user input
void approveAdmin()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple
    string redColor = "\033[31m";     // Red
    string greenColor = "\033[32m";   // Green

    string title[11] = {
    "",
    "            .**************..**************..**************..***************..**************..**************..**************. ",
    "           *    _______        .________.        ________        .__.  .__.      .________.        ______       .________.   *",
    "           *   |   __  \\       |  ______|       /  .__.  \\       |  |  |  |      |  ______|       '  ____|      |___  ___|   *",
    "           *   |  |__|  |      |  |_____        |  |  |  |       |  |  |  |      |  |_____       |  (__            |  |      *",
    "           *   |   _   /       |  ______|       |  | _|_ |       |  |  |  |      |  ______|       '.___ `.         |  |      *",
    "           *   |  |\\  \\        |  |_____        |  |_\\  \\|       |  |__|  |      |  |_____        _____)  |        |  |      *",
    "           *   |__| \\__\\       |________|       \\_____\\__\\       \\________/      |________|      |______.'         |__|      *",
    "           *.              ..              ..              ..               ..              ..               ..             .*",
    "           **************  **************  **************  ***************  **************  **************  **************",
    ""
    };

    printEndl(2);

    for (int i = 0; i < 11; i++)
    {
        centerText(purpleColor + title[i] + resetColor);
        cout << endl;
    }

    ACCOUNT* temp = head;
    bool foundPending = false;
    vector<string> updatedLines;

    ifstream inFile("../data/accounts.csv");
    string line;

    while (getline(inFile, line))
    {
        stringstream ss(line);
        string username, password, role, progressStr;
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, role, ',');
        getline(ss, progressStr, ',');

        if (role == "pending")
        {
            foundPending = true;
            printEndl(3);
            centerText(purpleColor + "           Pending account found: " + resetColor + username);
            printEndl(2);
            centerText(purpleColor + "           Approve this account as admin? (Y/N): " + resetColor);

            char choice;
            cin >> choice;
            printEndl(2);
            choice = tolower(choice);

            if (choice == 'y')
            {
                role = "admin";
                progressStr = "4";
                centerText(greenColor + "           Approved: " + resetColor + username);
                cout << endl;
            }
            else
            {
                centerText(redColor + "            " + username + "'s request rejected!" + resetColor);
                cout << endl;
                role = "user";
            }
        }

        updatedLines.push_back(username + "," + password + "," + role + "," + progressStr);
    }
    inFile.close();

    if (!foundPending)
    {
        printEndl(2);
        centerText(redColor + "             No pending accounts found." + resetColor);
        cout << endl;
        return;
    }

    ofstream outFile("../data/accounts.csv", ios::trunc);
    for (const string& updatedLine : updatedLines)
    {
        outFile << updatedLine << endl;
    }
    outFile.close();
}