#include "timeline.h"
#include "prehistoric.h"
#include "classical.h"
#include "middleAge.h"
#include "earlyModern.h"
#include "modern.h"

// Array of era names
string eras[5] =
{
    "1. Prehistoric era",
    "2. Classical era",
    "3. The Middle Age era",
    "4. Early Modern era",
    "5. Modern era"
};

// Array of corresponding years
string years[5] =
{
    "3000 BCE",
    "500 CE",
    "1500 CE",
    "1800 CE",
    "Present"
};

// Display the timeline and prompt the user to choose an era
void displayTimeline()
{
    int page = 0;
    string redColor = "\033[31m";     // Red
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    string title[11] = {
    "",
    "         .*************..*********..****************..*************..*************..*********..*************..**************.",
    "         *   .________.      .__.       _.      ._      .________.      .__.           .__.       ._.   ._       .________.   *",
    "         *   |___  ___|      |  |      |  \\    /  |     |  ______|      |  |           |  |      |   \\ |  |      |  ______|   *",
    "         *      |  |         |  |      |   \\  /   |     |  |_____       |  |           |  |      |    \\|  |      |  |_____    *",
    "         *      |  |         |  |      |    \\/    |     |  ______|      |  |           |  |      |  .     |      |  ______|   *",
    "         *      |  |         |  |      |  |\\  /|  |     |  |_____       |  |____.      |  |      |  |\\    |      |  |_____    *",
    "         *      |__|         |__|      |__| \\/ |__|     |________|      |_______|      |__|      |__| \\.__|      |________|   *",
    "         *.             ..         ..                ..             ..             ..         ..             ..              .*",
    "         *************  *********  ****************  *************  *************  *********  *************  **************",
    ""
    };

    printEndl(2);

    for (int i = 0; i < 11; i++)
    {
        centerText(purpleColor + title[i] + resetColor);
        cout << endl;
    }

    printEndl(5);

    printStrRepeat(" ", 31);

    for (int i = 0; i < 5; i++)
    {
        cout << years[i] << "              ";
    }

    cout << endl;

    printStrRepeat(" ", 12);
    cout << purpleColor << "<<";

    for (int i = 1; i < 29; i++)
    {
        if (i % 5 == 0)
        {
            cout << purpleColor << "|";
        }
        else
        {
            cout << purpleColor << "-----";
        }
    }
    cout << purpleColor << "->>" << resetColor << endl;

    printStrRepeat(" ", 18);

    for (int i = 0; i < 5; i++)
    {
        cout << eras[i] << "      ";
    }

    printEndl(4);

    centerText("          Choose an " + purpleColor + "ERA" + resetColor + " to explore: ");

    int era;
    cin >> era;

    while (era < 1 || era > 5)
    {
        cout << endl;
        centerText(redColor + "                Invalid choice! Please enter a number between 1 and 5: " + resetColor);
        cin >> era;
    }

    switch (era)
    {
    case 1:
        clearScreen();
        displayPrehistoric();
        break;
    case 2:
        if (progres >= 1)
        {
            clearScreen();
            displayClassical();
            break;
        }
        else
        {
            printEndl(2);
            centerText(redColor + "                Invalid choice! Complete Prehistoric Era first! " + resetColor);
            sleep_for(seconds(1));
            clearScreen();
            displayTimeline();
            break;
        }
    case 3:
        if (progres >= 2)
        {
            clearScreen();
            displayMiddleAge();
            break;
        }
        else
        {
            printEndl(2);
            centerText(redColor + "                Invalid choice! Complete Classical Era first! " + resetColor);
            sleep_for(seconds(1));
            clearScreen();
            displayTimeline();
            break;
        }
    case 4:
        if (progres >= 3)
        {
            clearScreen();
            displayEarlyModern();
            break;
        }
        else
        {
            printEndl(2);
            centerText(redColor + "                Invalid choice! Complete Middle Age Era first! " + resetColor);
            sleep_for(seconds(1));
            clearScreen();
            displayTimeline();
            break;
        }
    case 5:
        if (progres == 4)
        {
            clearScreen();
            displayModern();
            break;
        }
        else
        {
            printEndl(2);
            centerText(redColor + "                Invalid choice! Complete Early Modern Era first! " + resetColor);
            sleep_for(seconds(1));
            clearScreen();
            displayTimeline();
            break;
        }
    }
}