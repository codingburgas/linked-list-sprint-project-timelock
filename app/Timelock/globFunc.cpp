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
