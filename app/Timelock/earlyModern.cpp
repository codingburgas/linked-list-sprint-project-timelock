#include "earlyModern.h"
#include "timeline.h"

EARLYMODERN* loadEarlyModernInfo()
{
    ifstream file("../data/earlyModern/earlyModern.txt");

    if (!file)
    {
        cout << "Error: Could not open earlyModern.txt" << endl;
        return nullptr;
    }

    EARLYMODERN* head = nullptr;
    EARLYMODERN* tail = nullptr;
    string line;

    while (getline(file, line))
    {
        EARLYMODERN* newNode = new EARLYMODERN{ line, nullptr };

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

void displayEarlyModernInfo(EARLYMODERN* head) {
    EARLYMODERN* current = head;

    while (current)
    {
        centerText(current->data);
        cout << endl;

        current = current->next;
    }
}

void displayEarlyModern()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    cout << endl;
    printStrRepeat(" ", 2);
    cout << "PRESS " << purpleColor << "ESC" << resetColor << " TO GO BACK";

    string title[21] = {
    "",
    "       .**************..**************..**************..*************..*************.",
    "       *   .________.      .________.       _______        .__.          .__    __.   *",
    "       *   |  ______|      |   __   |      |   __  \\       |  |          \\  \\  /  /   *",
    "       *   |  |_____       |  |__|  |      |  |__|  |      |  |           \\  \\/  /    *",
    "       *   |  ______|      |   __   |      |   _   /       |  |            \\    /     *",
    "       *   |  |_____       |  |  |  |      |  |\\  \\        |  |____.        |  |      *",
    "       *   |________|      |__|  |__|      |__| \\__\\       |_______|        |__|      *",
    "       *.              ..              ..              ..             ..             .*",
    "        **************  **************  **************  *************  ************* ",
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

    for (int i = 0; i < 21; i++)
    {
        centerText(purpleColor + title[i] + resetColor);
        cout << endl;
    }

    printEndl(3);

    centerText("                Start exploring " + purpleColor + "Early Modern " + resetColor + "era events!");

    printEndl(3);


    EARLYMODERN* infoList = loadEarlyModernInfo();
    if (infoList)
    {
        displayEarlyModernInfo(infoList);
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