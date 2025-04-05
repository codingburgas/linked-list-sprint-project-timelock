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
    while (head) {
        QUIZNODE* temp = head;
        head = head->next;
        delete temp;
    }
}

INFONODE* loadInfoFromFile(const string& filepath) 
{
    ifstream file(filepath);

    if (!file) {
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