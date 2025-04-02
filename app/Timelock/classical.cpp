#include "classical.h"
#include "timeline.h"

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
    
    printEndl(4);

    while (!_kbhit()) {

    }


    char ch = _getch();

    if (ch == 27) {
        system("cls");
        displayTimeline();
    }

}
