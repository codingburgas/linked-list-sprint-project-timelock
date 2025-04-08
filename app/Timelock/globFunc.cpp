#include "pch.h"

int progres;

int getConsoleWidth() 
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int width;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    return width;
}

void clearScreen() {
    system("cls");
}

void centerText(string text) 
{ 
    int consoleWidth = getConsoleWidth();
    int paddingLeft = (consoleWidth - text.length()) / 2;
    if (paddingLeft < 0) 
    {
        paddingLeft = 0;
    }
    cout << string(paddingLeft, ' ') << text;
}

void printEndl(int num) 
{
    for (int i = 0; i < num; i++) 
    {
        cout << endl;
    }
}

void printStrRepeat(string str, int num) 
{
    for (int i = 0; i < num; i++) 
    {
        cout << str;
    }
}

void displayQuizTitle()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    cout << endl;
    printStrRepeat(" ", 2);
    cout << "PRESS " << purpleColor << "ESC" << resetColor << " TO GO BACK";

    string quiz[11] = 
    {
         "",
         "          .**************..*************..*********..*************.",
         "          *    ________       .__.  .__.      .__.       ______     *",
         "          *   /  .__.  \\      |  |  |  |      |  |      |___   |    *",
         "          *   |  |  |  |      |  |  |  |      |  |         /  /     *",
         "          *   |  | _|_ |      |  |  |  |      |  |        /  /      *",
         "          *   |  |_\\  \\|      |  |__|  |      |  |       /  /___    *",
         "          *   \\_____\\__\\      \\________/      |__|      |_______|   *",
         "          *.             ..              ..         ..             .*",
         "          **************  *************  *********  *************",
         ""
    };

    printEndl(2);

    for (int i = 0; i < 11; i++)
    {
        centerText(purpleColor + quiz[i] + resetColor);
        cout << endl;
    }
    printEndl(3);
}

void displayEventsTitle()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    cout << endl;
    printStrRepeat(" ", 2);
    cout << "PRESS " << purpleColor << "ESC" << resetColor << " TO GO BACK";

    string events[11] =
    {
         "",
         "              .**************..******************..**************..**************..**************..**************.",
         "              *   .________.      .__.      .__.      .________.       ._.   ._       .________.        ______     *",
         "              *   |  ______|      \\   \\    /   /      |  ______|      |   \\ |  |      |___  ___|       '  ____|    *",
         "              *   |  |_____        \\   \\  /   /       |  |_____       |    \\|  |         |  |         |  (__       *",
         "              *   |  ______|        \\   \\/   /        |  ______|      |  .     |         |  |          '.___ `.    *",
         "              *   |  |_____          \\      /         |  |_____       |  |\\    |         |  |          _____)  |   *",
         "              *   |________|          \\____/          |________|      |__| \\.__|         |__|         |______.'    *",
         "              *.              ..                  ..              ..              ..              ..              .*",
         "              **************  ******************  **************  **************  **************  **************",
         ""
    };

    printEndl(2);

    for (int i = 0; i < 11; i++)
    {
        centerText(purpleColor + events[i] + resetColor);
        cout << endl;
    }
    printEndl(2);
}

void displaySearchTitle()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    string search[11] =
    {
         "",
         "             .**************..**************..**************..**************..*************..**************.",
         "             *     ______        .________.      .________.       _______       .________.      .__.  .__.   *",
         "             *    '  ____|       |  ______|      |   __   |      |   __  \\      |  ______|      |  |  |  |   *",
         "             *   |  (__          |  |_____       |  |__|  |      |  |__|  |     |  |            |  |__|  |   *",
         "             *    '.___ `.       |  ______|      |   __   |      |   _   /      |  |            |   __   |   *",
         "             *    _____)  |      |  |_____       |  |  |  |      |  |\\  \\       |  |_____.      |  |  |  |   *",
         "             *   |______.'       |________|      |__|  |__|      |__| \\__\\      |________|      |__|  |__|   *",
         "             *.              ..              ..              ..              ..             ..              .*",
         "             **************  **************  **************  **************  *************  **************",
         ""
    };

    printEndl(2);

    for (int i = 0; i < 11; i++)
    {
        centerText(purpleColor + search[i] + resetColor);
        cout << endl;
    }
    printEndl(2);
}

void appendNode(QUIZNODE*& head, const string& line) 
{
    QUIZNODE* newNode = new QUIZNODE{ line, nullptr };
    if (!head) head = newNode;
    else 
    {
        QUIZNODE* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

void deleteList(QUIZNODE* head) 
{
    while (head) 
    {
        QUIZNODE* temp = head;
        head = head->next;
        delete temp;
    }
}

INFONODE* loadInfoFromFile(const string& filepath) 
{
    ifstream file(filepath);

    if (!file) 
    {
        cout << "Error: Could not open " << filepath << endl;
        return nullptr;
    }

    INFONODE* head = nullptr;
    INFONODE* tail = nullptr;
    string line;

    while (getline(file, line)) 
    {
        INFONODE* newNode = new INFONODE;
        newNode->data = line;
        newNode->next = nullptr;

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

void displayInfo(INFONODE* head) 
{
    INFONODE* current = head;

    printEndl(2);
    while (current) 
    {
        centerText(current->data);
        cout << endl;
        current = current->next;
    }
    printEndl(4);
}

void deleteInfoList(INFONODE* head) 
{
    while (head) 
    {
        INFONODE* temp = head;
        head = head->next;
        delete temp;
    }
}

void editEventFile(const string& filepath)
{

    string redColor = "\033[31m";     // Red
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple
    string greenColor = "\033[32m";   // Green

    INFONODE* head = loadInfoFromFile(filepath);

    if (!head)
    {
        centerText(redColor + "File could not be loaded." + resetColor);
        cout << endl;
        return;
    }

    printEndl(2);
    centerText(purpleColor + "            Current content of the file: " + resetColor);
    cout << endl;
    displayInfo(head);

    deleteInfoList(head);

    cout << endl;
    centerText(purpleColor + "          Editing mode: " + resetColor + "Type the new content for the file.");
    cout << endl;
    centerText("          Type " + purpleColor + "'END' " + resetColor + "on a new line when you're done.");
    printEndl(2);

    INFONODE* newHead = nullptr;
    INFONODE* tail = nullptr;
    string line;

    cin.ignore(); 
    while (true)
    {
        getline(cin, line);
        if (line == "END") break;

        INFONODE* newNode = new INFONODE{ line, nullptr };

        if (!newHead)
        {
            newHead = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    ofstream file(filepath);
    if (!file)
    {
        printEndl(2);
        centerText(redColor + "Could not open file to save changes." + resetColor);
        cout << endl;
        deleteInfoList(newHead);
        return;
    }

    INFONODE* current = newHead;
    while (current)
    {
        file << current->data << endl;
        current = current->next;
    }

    file.close();
    printEndl(2);
    centerText(greenColor +  "           File updated successfully!" + resetColor);
    printEndl(2);

    deleteInfoList(newHead);
}

void deleteEventFile(const string& filepath)
{
    string redColor = "\033[31m";     // Red
    string resetColor = "\033[37m";   // White 
    string greenColor = "\033[32m";   // Green
    string purpleColor = "\033[35m";  // Purple

    printEndl(2);
    centerText(purpleColor + "            Current content of the file: " + resetColor);
    cout << endl;

    INFONODE* head = loadInfoFromFile(filepath);

    if (!head)
    {
        centerText(redColor + "         File could not be loaded or doesn't exist." + resetColor);
        cout << endl;
        return;
    }

    displayInfo(head);

    char confirm;
    centerText(purpleColor + "              Are you sure you want to delete this file? (Y/N): " + resetColor);
    cin >> confirm;

    if (confirm == 'Y' || confirm == 'y')
    {
        if (remove(filepath.c_str()) == 0)
        {
            printEndl(2);
            centerText(greenColor + "               File deleted successfully!" + resetColor);
        }
        else
        {
            printEndl(2);
            centerText(redColor + "         Failed to delete the file." + resetColor);
        }
    }
    else
    {
        printEndl(2);
        centerText(redColor + "               File deletion cancelled." + resetColor);
    }

    printEndl(2);
    deleteInfoList(head);
}