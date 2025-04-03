#include "classical.h"
#include "timeline.h"

CLASSICAL* loadClassicalInfo()
{
    ifstream file("../data/classical/classical.txt");

    if (!file)
    {
        cout << "Error: Could not open classical.txt" << endl;
        return nullptr;
    }

    CLASSICAL* head = nullptr;
    CLASSICAL* tail = nullptr;
    string line;

    while (getline(file, line))
    {
        CLASSICAL* newNode = new CLASSICAL{ line, nullptr };

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

void displayClassicalInfo(CLASSICAL* head) {
    CLASSICAL* current = head;

    while (current)
    {
        centerText(current->data);
        cout << endl;

        current = current->next;
    }
}

void displayClassical()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    cout << endl;
    printStrRepeat(" ", 2);
    cout << "PRESS " << purpleColor << "ESC" << resetColor << " TO GO BACK";

    string title[11] = {
    "",
    "       .*************..**************..**************..*************..*************..*********..**************..**************..*************.",
    "      *   .________.      .__.           .________.        ______         ______        .__.      .________.      .________.      .__.        *",
    "      *   |  ______|      |  |           |   __   |       '  ____|       '  ____|       |  |      |  ______|      |   __   |      |  |        *",
    "      *   |  |            |  |           |  |__|  |      |  (__         |  (__          |  |      |  |            |  |__|  |      |  |        *",
    "      *   |  |            |  |           |   __   |       '.___ `.       '.___ `.       |  |      |  |            |   __   |      |  |        *",
    "      *   |  |_____.      |  |____.      |  |  |  |       _____)  |      _____)  |      |  |      |  |_____.      |  |  |  |      |  |____.   *",
    "      *   |________|      |_______|      |__|  |__|      |______.'      |______.'       |__|      |________|      |__|  |__|      |_______|   *",
    "      *.             ..              ..              ..             ..             ..         ..              ..              ..             .*",
    "        *************  **************  **************  *************  *************  *********  **************  **************  *************  ",
    ""
    };

    printEndl(2);

    for (int i = 0; i < 11; i++)
    {
        centerText(purpleColor + title[i] + resetColor);
        cout << endl;
    }

    printEndl(3);

    centerText("            Start exploring " + purpleColor + "Classical " + resetColor + "era events!");
    
    printEndl(3);


    CLASSICAL* infoList = loadClassicalInfo();
    if (infoList)
    {
        displayClassicalInfo(infoList);
    }

    printEndl(4);

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
