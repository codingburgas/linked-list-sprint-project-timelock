#include "events.h"

void displayPrehistoricEventsInfo()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    INFONODE* list = nullptr;
    int event;
    bool explored[3] = { false, false, false }; 

    while (true)
    {
        if (explored[0] && explored[1] && explored[2])
        {
            cout << endl;
            centerText(purpleColor + "      You've explored all prehistoric events! You may now attempt the quiz!" + resetColor);
            break;
        }

        centerText(purpleColor + "            Choose an event to explore! " + resetColor);
        cin >> event;

        if (list)
        {
            deleteInfoList(list);
            list = nullptr;
        }

        switch (event)
        {
        case 1:
            if (explored[0]) 
            {
                centerText("You've already explored the Stone Age.");
                cout << endl;
                continue;
            }
            printEndl(3);
            {
                string title[3] = {
                    "           *************************",
                    "           *       STONE AGE       *",
                    "           *************************"
                };
                for (int i = 0; i < 3; i++) 
                {
                    centerText(purpleColor + title[i] + resetColor);
                    cout << endl;
                }
            }
            list = loadInfoFromFile("../data/prehistoric/stoneAge.txt");
            explored[0] = true;
            break;

        case 2:
            if (explored[1])
            {
                centerText("You've already explored the Bronze Age.");                
                cout << endl;
                continue;
            }
            printEndl(3);
            {
                string title[3] = {
                    "           *************************",
                    "           *       BRONZE AGE      *",
                    "           *************************"
                };
                for (int i = 0; i < 3; i++) 
                {
                    centerText(purpleColor + title[i] + resetColor);
                    cout << endl;
                }
            }
            list = loadInfoFromFile("../data/prehistoric/bronzeAge.txt");
            explored[1] = true;
            break;

        case 3:
            if (explored[2]) 
            {
                centerText("You've already explored the Iron Age.");
                cout << endl;
                continue;
            }
            printEndl(3);
            {
                string title[3] = {
                    "           *************************",
                    "           *        IRON AGE       *",
                    "           *************************"
                };
                for (int i = 0; i < 3; i++)
                {
                    centerText(purpleColor + title[i] + resetColor);
                    cout << endl;
                }
            }
            list = loadInfoFromFile("../data/prehistoric/IronAge.txt");
            explored[2] = true;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
            continue;
        }

        if (list)
        {
            displayInfo(list);
        }
    }

    if (list)
    {
        deleteInfoList(list);
    }
}

void displayClassicalEventsInfo()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    INFONODE* list = nullptr;
    int event;
    bool explored[4] = { false, false, false, false };

    while (true)
    {
        if (explored[0] && explored[1] && explored[2] && explored[3])
        {
            cout << endl;
            centerText(purpleColor + "      You've explored all classical events! You may now attempt the quiz!" + resetColor);
            break;
        }

        centerText(purpleColor + "            Choose an event to explore! " + resetColor);
        cin >> event;

        if (list)
        {
            deleteInfoList(list);
            list = nullptr;
        }

        switch (event)
        {
        case 1:
            if (explored[0]) 
            {
                centerText("You've already explored The Greco - Persian Wars.");
                cout << endl;
                continue;
            }
            printEndl(2);
            {
                string title[3] = {
                    "               ****************************************",
                    "               *       The Greco - Persian Wars       *",
                    "               ****************************************"
                };
                for (int i = 0; i < 3; i++) 
                {
                    centerText(purpleColor + title[i] + resetColor);
                    cout << endl;
                }
            }
            list = loadInfoFromFile("../data/classical/grecoPersianWars.txt");
            explored[0] = true;
            break;

        case 2:
            if (explored[1]) 
            {
                centerText("You've already explored The Peloponnesian War.");
                cout << endl;
                continue;
            }
            printEndl(3);
            {
                string title[3] = {
                    "               ************************************",
                    "               *       The Peloponnesian War      *",
                    "               ************************************"
                };
                for (int i = 0; i < 3; i++) 
                {
                    centerText(purpleColor + title[i] + resetColor);
                    cout << endl;
                }
            }
            list = loadInfoFromFile("../data/classical/peloponnesianWar.txt");
            explored[1] = true;
            break;

        case 3:
            if (explored[2])
            {
                centerText("You've already explored The Roman Revolution.");
                cout << endl;
                continue;
            }
            printEndl(3);
            {
                string title[3] = {
                    "               *************************************",
                    "               *        The Roman Revolution       *",
                    "               *************************************"
                };
                for (int i = 0; i < 3; i++) 
                {
                    centerText(purpleColor + title[i] + resetColor);
                    cout << endl;
                }
            }
            list = loadInfoFromFile("../data/classical/romanRevolution.txt");
            explored[2] = true;
            break;

        case 4:
            if (explored[3]) 
            {
                centerText("You've already explored The Decline and Fall of the Roman Empire.");
                cout << endl;
                continue;
            }
            printEndl(3);
            {
                string title[3] = {
                    "               *********************************************************",
                    "               *        The Decline and Fall of the Roman Empire       *",
                    "               *********************************************************"
                };
                for (int i = 0; i < 3; i++) {
                    centerText(purpleColor + title[i] + resetColor);
                    cout << endl;
                }
            }
            list = loadInfoFromFile("../data/classical/romanEmpire.txt");
            explored[3] = true;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
            continue;
        }

        if (list)
        {
            displayInfo(list);
        }
    }

    if (list)
    {
        deleteInfoList(list);
    }
}

