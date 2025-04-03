#include "prehistoric.h"
#include "validation.h"
#include "admin.h"
#include "user.h"

#include "timeline.h"

PREHISTORIC* loadPrehistoricInfo()
{
    ifstream file("../data/prehistoric/prehistoric.txt");

    if (!file) 
    {
        cout << "Error: Could not open prehistoric.txt" << endl;
        return nullptr;
    }

    PREHISTORIC* head = nullptr;
    PREHISTORIC* tail = nullptr;
    string line;

    while (getline(file, line)) 
    {
        PREHISTORIC* newNode = new PREHISTORIC{ line, nullptr };

        if (!head) 
        {
            head = newNode;
            tail = newNode;
        }
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    file.close();
    return head;
}

void displayPrehistoricInfo(PREHISTORIC* head) 
{
    PREHISTORIC* current = head;

    while (current) 
    {
        centerText(current->data);
        cout << endl;

        current = current->next;
    }
}

void editPrehistoricInfo(PREHISTORIC* head) 
{
    PREHISTORIC* current = head;
    int lineNum = 1;
    char ch;

    while (current) 
    {
        cout << "[" << lineNum << "] " << current->data << endl;
        current = current->next;
        lineNum++;
    }

    cout << endl << "Enter the line number you want to edit: ";
    int editLine;
    cin >> editLine;
    cin.ignore();

    current = head;
    lineNum = 1;

    while (current) {
        if (lineNum == editLine) 
        {
            cout << "Editing: " << current->data << endl;
            cout << "Enter new text: ";
            getline(cin, current->data);
            break;
        }
        current = current->next;
        lineNum++;
    }

    cout << endl << "Press 'S' to save changes or any other key to discard: ";
    ch = _getch();

    if (ch == 's' || ch == 'S') {
        savePrehistoricInfo(head);
        cout << endl << "Changes saved successfully!" << endl;
    }
    else {
        cout << endl << "Changes discarded." << endl;
    }
}

void savePrehistoricInfo(PREHISTORIC* head) 
{
    ofstream file("../data/prehistoric/prehistoric.txt");

    if (!file) {
        cout << "Error: Could not open prehistoric.txt for writing!" << endl;
        return;
    }

    PREHISTORIC* current = head;
    while (current) 
    {
        file << current->data << endl;
        current = current->next;
    }

    file.close();
}

void deletePrehistoricFile()
{
    const char* filename = "../data/prehistoric/prehistoric.txt";

    if (remove(filename) == 0)
    {
        cout << "The prehistoric data file has been successfully deleted!" << endl;
    }
    else
    {
        cout << "Error: Could not delete the file." << endl;
    }
}

void displayPrehistoric() 
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    cout << endl;
    printStrRepeat(" ", 2);
    cout << "PRESS " << purpleColor << "ESC" << resetColor << " TO GO BACK";

    const string title[21] = {
    "",
    "           .**************..*************..**************.",
    "           *    _______         _______       .________.   *",
    "           *   |   __  \\       |   __  \\      |  ______|   *",
    "           *   |  |__|  |      |  |__|  |     |  |_____    *",
    "           *   |   ____/       |   _   /      |  ______|   *",
    "           *   |  |            |  |\\  \\       |  |_____    *",
    "           *   |__|            |__| \\__\\      |________|   *",
    "           *.              ..             ..              .*",
    "           **************  *************  **************",
    "",
    "         .**************..********..**************..*************..**************..**************..********..**************.",
    "         *   .__.  .__.      .__.        ______       .________.       ________        _______        .__.      .________.   *",
    "         *   |  |  |  |      |  |       '  ____|      |___  ___|      /  .__.  \\      |   __  \\       |  |      |  ______|   *",
    "         *   |  |__|  |      |  |      |  (__            |  |         |  |  |  |      |  |__|  |      |  |      |  |         *",
    "         *   |   __   |      |  |       '.___ `.         |  |         |  |  |  |      |   _   /       |  |      |  |         *",
    "         *   |  |  |  |      |  |       _____)  |        |  |         |  |__|  |      |  |\\  \\        |  |      |  |_____.   *",
    "         *   |__|  |__|      |__|      |______.'         |__|         \\________/      |__| \\__\\       |__|      |________|   *",
    "         *.              ..        ..              ..             ..              ..              ..        ..              .*",
    "         **************  ********  **************  *************  **************  **************  ********  **************",
    ""
    };

    printEndl(2);

    for (int i = 0; i < 21; i++)
    {
        centerText(purpleColor + title[i] + resetColor);
        cout << endl;
    }

    printEndl(3);

    centerText("            Start exploring " + purpleColor + "Prehistoric " + resetColor+ "era events!");

    printEndl(3);

    PREHISTORIC* infoList = loadPrehistoricInfo();
    if (infoList) 
    {
        displayPrehistoricInfo(infoList);
    }

    printEndl(4);

    string role = getCurrentUserRole();
    if (role == "admin")
    {
        adminPanel();
    }
    else
    {
        userPanel();
    }

    while (!_kbhit()) 
    {

    }

    char ch = _getch();

    if (ch == 27) 
    {
        system("cls");
        displayTimeline();
    }
}






