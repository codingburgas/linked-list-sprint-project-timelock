#include "prehistoric.h"
#include "validation.h"
#include "admin.h"
#include "user.h"

#include "timeline.h"

void displayPrehistoric() 
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    cout << "Press 'Esc' to go back";

    const string title[21] = {
    "",
    "    .**************..*************..**************.",
    "    *    _______         _______       .________.   *",
    "    *   |   __  \\       |   __  \\      |  ______|   *",
    "    *   |  |__|  |      |  |__|  |     |  |_____    *",
    "    *   |   ____/       |   _   /      |  ______|   *",
    "    *   |  |            |  |\\  \\       |  |_____    *",
    "    *   |__|            |__| \\__\\      |________|   *",
    "    *.              ..             ..              .*",
    "    **************  *************  **************",
    "",
    "        .**************..********..**************..*************..**************..**************..********..**************.",
    "       *   .__.  .__.      .__.        ______       .________.       ________        _______        .__.      .________.   *",
    "       *   |  |  |  |      |  |       '  ____|      |___  ___|      /  .__.  \\      |   __  \\       |  |      |  ______|   *",
    "       *   |  |__|  |      |  |      |  (__            |  |         |  |  |  |      |  |__|  |      |  |      |  |         *",
    "       *   |   __   |      |  |       '.___ `.         |  |         |  |  |  |      |   _   /       |  |      |  |         *",
    "       *   |  |  |  |      |  |       _____)  |        |  |         |  |__|  |      |  |\\  \\        |  |      |  |_____.   *",
    "       *   |__|  |__|      |__|      |______.'         |__|         \\________/      |__| \\__\\       |__|      |________|   *",
    "       *.              ..        ..              ..             ..              ..              ..        ..              .*",
    "       **************  ********  **************  *************  **************  **************  ********  **************",
    ""
    };

    printEndl(2);

    for (int i = 0; i < 21; i++)
    {
        centerText(purpleColor + title[i] + resetColor);
        cout << endl;
    }

    printEndl(2);

    centerText("Start exploring " + purpleColor + "Prehistoric " + resetColor+ "era events!");

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

    while (!_kbhit()) {

    }


    char ch = _getch();

    if (ch == 27) {
        system("cls");
        displayTimeline();
    }
}


