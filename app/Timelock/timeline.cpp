#include "timeline.h"
#include "prehistoric.h"
#include "classical.h"
#include "middleAge.h"
#include "earlyModern.h"
#include "modern.h"

string eras[5] = 
{
    "1. Prehistoric era",
    "2. Classical era",
    "3. The Middle Age era",
    "4. Early Modern era",
    "5. Modern era"
};

void displayTimeline()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    string title[11] = {
    "",
    "       .*************..*********..****************..*************..*************..*********..*************..**************.",
    "      *   .________.      .__.       _.      ._      .________.      .__.           .__.       ._.   ._       .________.   *",
    "      *   |___  ___|      |  |      |  \\    /  |     |  ______|      |  |           |  |      |   \\ |  |      |  ______|   *",
    "      *      |  |         |  |      |   \\  /   |     |  |_____       |  |           |  |      |    \\|  |      |  |_____    *",
    "      *      |  |         |  |      |    \\/    |     |  ______|      |  |           |  |      |  .     |      |  ______|   *",
    "      *      |  |         |  |      |  |\\  /|  |     |  |_____       |  |____.      |  |      |  |\\    |      |  |_____    *",
    "      *      |__|         |__|      |__| \\/ |__|     |________|      |_______|      |__|      |__| \\.__|      |________|   *",
    "      *.             ..         ..                ..             ..             ..         ..             ..              .*",
    "      *************  *********  ****************  *************  *************  *********  *************  **************",
    ""
    };

    printEndl(2);

    for (int i = 0; i < 11; i++)
    {
        centerText(purpleColor + title[i] + resetColor);
        cout << endl;
    }

    printEndl(5);
    printStrRepeat(" ", 10);
    cout << "<<";

    for (int i = 1; i < 29; i++)
    {
        if (i % 5 == 0)
        {
            cout << "|";
        }
        else
        {
            cout << "-----";
        }        
    }
    cout << "->>" << endl;

    printStrRepeat(" ", 16);

    for (int i = 0; i < 5; i++)
    {
        cout << eras[i] << "      ";
    }

    printEndl(4);

    centerText("Choose an era to explore: ");

    int era;
    cin >> era;
  
    if (era == 1)
    {
        system("cls");
        displayPrehistoric();
    }
    else if (era == 2)
    {
        system("cls");
        displayClassical();
    }
    else if (era == 3)
    {
        system("cls");
        displayMiddleAge();
    }
    else if (era == 4)
    {
        system("cls");
        displayEarlyModern();
    }
    else if (era == 5)
    {
        system("cls");
        displayModern();
    }
}



