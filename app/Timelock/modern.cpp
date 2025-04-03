#include "modern.h"
#include "timeline.h"

MODERN* loadModernInfo()
{
    ifstream file("../data/modern/modern.txt");

    if (!file)
    {
        cout << "Error: Could not open modern.txt" << endl;
        return nullptr;
    }

    MODERN* head = nullptr;
    MODERN* tail = nullptr;
    string line;

    while (getline(file, line))
    {
        MODERN* newNode = new MODERN{ line, nullptr };

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

void displayModernInfo(MODERN* head) {
    MODERN* current = head;

    while (current)
    {
        centerText(current->data);
        cout << endl;

        current = current->next;
    }
}

void displayModern()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    cout << endl;
    printStrRepeat(" ", 2);
    cout << "PRESS " << purpleColor << "ESC" << resetColor << " TO GO BACK";

    string title[11] = {
    "",
    "           .****************..**************..**************..***************..**************..**************. ",
    "           *    _.      ._        ________        ________        .________.       _______         ._.   ._    *",
    "           *   |  \\    /  |      /  .__.  \\      |   __   \\       |  ______|      |   __  \\       |   \\ |  |   *",
    "           *   |   \\  /   |      |  |  |  |      |  |   |  |      |  |_____       |  |__|  |      |    \\|  |   *",
    "           *   |    \\/    |      |  |  |  |      |  |   |  |      |  ______|      |   _   /       |  .     |   *",
    "           *   |  |\\  /|  |      |  |__|  |      |  |___|  |      |  |_____       |  |\\  \\        |  |\\    |   *",
    "           *   |__| \\/ |__|      \\________/      |_______./       |________|      |__| \\__\\       |__| \\.__|   *",
    "           *.                ..              ..              ..               ..              ..              .*",
    "           ****************  **************  **************  ***************  **************  **************",
    ""
    };

    printEndl(2);

    for (int i = 0; i < 11; i++)
    {
        centerText(purpleColor + title[i] + resetColor);
        cout << endl;
    }

    printEndl(3);

    centerText("                Start exploring " + purpleColor + "Modern " + resetColor + "era events!");

    printEndl(3);


    MODERN* infoList = loadModernInfo();
    if (infoList)
    {
        displayModernInfo(infoList);
    }

    printEndl(4);

    while (!_kbhit()) 
    {

    }

    char ch = _getch();

    if (ch == 27) {
        system("cls");
        displayTimeline();
    }
}
