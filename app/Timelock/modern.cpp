
#include "modern.h"
#include "timeline.h"

void displayModern()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    string title[11] = {
    "",
    "      .****************..**************..**************..***************..**************..**************.",
    "      *    _.      ._        ________        ________        .________.       _______         ._.   ._    *",
    "      *   |  \\    /  |      /  .__.  \\      |   __   \\       |  ______|      |   __  \\       |   \\ |  |   *",
    "      *   |   \\  /   |      |  |  |  |      |  |   |  |      |  |_____       |  |__|  |      |    \\|  |   *",
    "      *   |    \\/    |      |  |  |  |      |  |   |  |      |  ______|      |   _   /       |  .     |   *",
    "      *   |  |\\  /|  |      |  |__|  |      |  |___|  |      |  |_____       |  |\\  \\        |  |\\    |   *",
    "      *   |__| \\/ |__|      \\________/      |_______./       |________|      |__| \\__\\       |__| \\.__|   *",
    "      *.                ..              ..              ..               ..              ..              .*",
    "     ****************  **************  **************  ***************  **************  **************",
    ""
    };

    printEndl(2);

    for (int i = 0; i < 11; i++)
    {
        centerText(purpleColor + title[i] + resetColor);
        cout << endl;
    }

    printEndl(2);

    centerText("      Start exploring " + purpleColor + "Modern " + resetColor + "era events!");

    printEndl(2);


    while (!_kbhit()) {

    }


    char ch = _getch();

    if (ch == 27) {
        system("cls");
        displayTimeline();
    }
}
