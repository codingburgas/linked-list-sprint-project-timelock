#include "events.h"
#include "favourites.h"

// Display events' info
void displayPrehistoricEventsInfo()
{
    string redColor = "\033[31m";     // Red
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
            centerText(purpleColor + "      You've explored all PREHISTORIC events! You may now attempt the quiz!" + resetColor);
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
                printEndl(2);
                centerText(redColor + "             You've already explored the 'Stone Age'." + resetColor);
                printEndl(2);
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
                printEndl(2);
                centerText(redColor + "             You've already explored the 'Bronze Age'." + resetColor);                
                printEndl(2);
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
                printEndl(2);
                centerText(redColor + "             You've already explored the 'Iron Age'." + resetColor);
                printEndl(2);
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
            printEndl(2);
            centerText(redColor + "             Invalid choice. Try again." + resetColor);
            printEndl(2);
            continue;
        }

        if (list)
        {
            displayInfo(list);
            askToAddToFavourites("Prehistoric", list);
        }
    }

    if (list)
    {
        deleteInfoList(list);
    }
}

// Display events' info
void displayClassicalEventsInfo()
{
    string redColor = "\033[31m";     // Red
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
            centerText(purpleColor + "      You've explored all CLASSICAL events! You may now attempt the quiz!" + resetColor);
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
                printEndl(2);
                centerText(redColor + "             You've already explored 'The Greco - Persian Wars'." + resetColor);
                printEndl(2);
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
                printEndl(2);
                centerText(redColor + "             You've already explored 'The Peloponnesian War'." +  resetColor);
                printEndl(2);
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
                printEndl(2);
                centerText(redColor + "             You've already explored 'The Roman Revolution'." + resetColor);
                printEndl(2);
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
                printEndl(2);
                centerText(redColor + "             You've already explored 'The Decline and Fall of the Roman Empire'." + resetColor);
                printEndl(2);
                continue;
            }
            printEndl(3);
            {
                string title[3] = {
                    "               *********************************************************",
                    "               *        The Decline and Fall of the Roman Empire       *",
                    "               *********************************************************"
                };
                for (int i = 0; i < 3; i++) 
                {
                    centerText(purpleColor + title[i] + resetColor);
                    cout << endl;
                }
            }
            list = loadInfoFromFile("../data/classical/romanEmpire.txt");
            explored[3] = true;
            break;

        default:
            printEndl(2);
            centerText(redColor+ "             Invalid choice. Try again." + resetColor);
            printEndl(2);
            continue;
        }

        if (list)
        {
            displayInfo(list);
            askToAddToFavourites("Classical", list);
        }
    }

    if (list)
    {
        deleteInfoList(list);
    }
}

// Display events' info
void displayMiddleAgeEventsInfo()
{
    string redColor = "\033[31m";     // Red
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
            centerText(purpleColor + "      You've explored all MIDDLE AGE events! You may now attempt the quiz!" + resetColor);
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
                printEndl(2);
                centerText(redColor + "             You've already explored 'Viking Age'." + resetColor);
                printEndl(2);
                continue;
            }
            printEndl(2);
            {
                string title[3] = {
                    "            **************************",
                    "            *       Viking Age       *",
                    "            **************************"
                };
                for (int i = 0; i < 3; i++)
                {
                    centerText(purpleColor + title[i] + resetColor);
                    cout << endl;
                }
            }
            list = loadInfoFromFile("../data/middleAge/vikingAge.txt");
            explored[0] = true;
            break;

        case 2:
            if (explored[1])
            {
                printEndl(2);
                centerText(redColor + "             You've already explored the 'Battle of Hastings'." + resetColor);
                printEndl(2);
                continue;
            }
            printEndl(3);
            {
                string title[3] = {
                    "               *********************************",
                    "               *       Battle of Hastings      *",
                    "               *********************************"
                };
                for (int i = 0; i < 3; i++)
                {
                    centerText(purpleColor + title[i] + resetColor);
                    cout << endl;
                }
            }
            list = loadInfoFromFile("../data/middleAge/battleOfHastings.txt");
            explored[1] = true;
            break;

        case 3:
            if (explored[2])
            {
                printEndl(2);
                centerText(redColor + "             You've already explored the 'Hundred Years' War'." + resetColor);
                printEndl(2);
                continue;
            }
            printEndl(3);
            {
                string title[3] = {
                    "               ***********************************",
                    "               *        Hundred Years' War       *",
                    "               ***********************************"
                };
                for (int i = 0; i < 3; i++)
                {
                    centerText(purpleColor + title[i] + resetColor);
                    cout << endl;
                }
            }
            list = loadInfoFromFile("../data/middleAge/hundredYearsWar.txt");
            explored[2] = true;
            break;

        case 4:
            if (explored[3])
            {
                printEndl(2);
                centerText(redColor + "             You've already explored the 'Black Death'." + resetColor);
                printEndl(2);
                continue;
            }
            printEndl(3);
            {
                string title[3] = {
                    "            ****************************",
                    "            *        Black Death       *",
                    "            ****************************"
                };
                for (int i = 0; i < 3; i++)
                {
                    centerText(purpleColor + title[i] + resetColor);
                    cout << endl;
                }
            }
            list = loadInfoFromFile("../data/middleAge/blackDeath.txt");
            explored[3] = true;
            break;

        default:
            printEndl(2);
            centerText(redColor + "             Invalid choice. Try again." + resetColor);
            printEndl(2);
        }

        if (list)
        {
            displayInfo(list);
            askToAddToFavourites("Middle Ages", list);
        }
    }

    if (list)
    {
        deleteInfoList(list);
    }
}

// Display events' info
void displayEarlyModernEventsInfo()
{
    string redColor = "\033[31m";     // Red
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
            centerText(purpleColor + "      You've explored all EARLY MODERN events! You may now attempt the quiz!" + resetColor);
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
                printEndl(2);
                centerText(redColor + "             You've already explored the 'Thirty Years' War'." + resetColor);
                printEndl(2);
                continue;
            }
            printEndl(3);
            {
                string title[3] = {
                    "               ********************************",
                    "               *       Thirty Years' War      *",
                    "               ********************************"
                };
                for (int i = 0; i < 3; i++)
                {
                    centerText(purpleColor + title[i] + resetColor);
                    cout << endl;
                }
            }
            list = loadInfoFromFile("../data/earlyModern/thirtyYearsWar.txt");
            explored[0] = true;
            break;

        case 2:
            if (explored[1])
            {
                printEndl(2);
                centerText(redColor + "             You've already explored 'Treaty of Utrecht ends War of Spanish Succession'." + resetColor);
                printEndl(2);
                continue;
            }
            printEndl(3);
            {
                string title[3] = {
                    "         ***************************************************************",
                    "         *       Treaty of Utrecht ends War of Spanish Succession      *",
                    "         ***************************************************************"
                };
                for (int i = 0; i < 3; i++)
                {
                    centerText(purpleColor + title[i] + resetColor);
                    cout << endl;
                }
            }
            list = loadInfoFromFile("../data/earlyModern/spanishSuccession.txt");
            explored[1] = true;
            break;

        case 3:
            if (explored[2])
            {
                printEndl(2);
                centerText(redColor + "             You've already explored 'Turks defeated outside Vienna'." + resetColor);
                printEndl(2);
                continue;
            }
            printEndl(3);
            {
                string title[3] = {
                    "                **********************************************",
                    "                *        Turks defeated outside Vienna       *",
                    "                **********************************************"
                };
                for (int i = 0; i < 3; i++)
                {
                    centerText(purpleColor + title[i] + resetColor);
                    cout << endl;
                }
            }
            list = loadInfoFromFile("../data/earlyModern/siegeOfVienna.txt");
            explored[2] = true;
            break;

        default:
            printEndl(2);
            centerText(redColor + "             Invalid choice. Try again." + resetColor);
            printEndl(2);
        }

        if (list)
        {
            displayInfo(list);
            askToAddToFavourites("Early Modern", list);
        }
    }

    if (list)
    {
        deleteInfoList(list);
    }
}

// Display events' info
void displayModernEventsInfo()
{
    string redColor = "\033[31m";     // Red
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    INFONODE* list = nullptr;
    int event;
    bool explored[5] = { false, false, false, false, false };

    while (true)
    {
        if (explored[0] && explored[1] && explored[2] && explored[3] && explored[4])
        {
            cout << endl;
            centerText(purpleColor + "      You've explored all MODERN events! You may now attempt the quiz!" + resetColor);
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
                printEndl(2);
                centerText(redColor + "             You've already explored 'Industrial Revolution'." + resetColor);
                printEndl(2);
                continue;
            }
            printEndl(2);
            {
                string title[3] = {
                    "            *************************************",
                    "            *       Industrial Revolution       *",
                    "            *************************************"
                };
                for (int i = 0; i < 3; i++)
                {
                    centerText(purpleColor + title[i] + resetColor);
                    cout << endl;
                }
            }
            list = loadInfoFromFile("../data/modern/industrialRevolution.txt");
            explored[0] = true;
            break;

        case 2:
            if (explored[1])
            {
                printEndl(2);
                centerText(redColor + "             You've already explored the 'World War I'." + resetColor);
                printEndl(2);
                continue;
            }
            printEndl(3);
            {
                string title[3] = {
                    "               **************************",
                    "               *       World War I      *",
                    "               **************************"
                };
                for (int i = 0; i < 3; i++)
                {
                    centerText(purpleColor + title[i] + resetColor);
                    cout << endl;
                }
            }
            list = loadInfoFromFile("../data/modern/WW1.txt");
            explored[1] = true;
            break;

        case 3:
            if (explored[2])
            {
                printEndl(2);
                centerText(redColor + "             You've already explored the 'Great Depression'." + resetColor);
                printEndl(2);
                continue;
            }
            printEndl(3);
            {
                string title[3] = {
                    "               *********************************",
                    "               *        Great Depression       *",
                    "               *********************************"
                };
                for (int i = 0; i < 3; i++)
                {
                    centerText(purpleColor + title[i] + resetColor);
                    cout << endl;
                }
            }
            list = loadInfoFromFile("../data/modern/greatDepression.txt");
            explored[2] = true;
            break;

        case 4:
            if (explored[3])
            {
                printEndl(2);
                centerText(redColor + "             You've already explored the 'World War II'." + resetColor);
                printEndl(2);
                continue;
            }
            printEndl(3);
            {
                string title[3] = {
                    "            *****************************",
                    "            *        World War II       *",
                    "            *****************************"
                };
                for (int i = 0; i < 3; i++)
                {
                    centerText(purpleColor + title[i] + resetColor);
                    cout << endl;
                }
            }
            list = loadInfoFromFile("../data/modern/WW2.txt");
            explored[3] = true;
            break;

        case 5:
            if (explored[4])
            {
                printEndl(2);
                centerText(redColor + "             You've already explored the 'Cold War'." + resetColor);
                printEndl(2);
                continue;
            }
            printEndl(3);
            {
                string title[3] = {
                    "            *************************",
                    "            *        Cold War       *",
                    "            *************************"
                };
                for (int i = 0; i < 3; i++)
                {
                    centerText(purpleColor + title[i] + resetColor);
                    cout << endl;
                }
            }
            list = loadInfoFromFile("../data/modern/coldWar.txt");
            explored[4] = true;
            break;

        default:
            printEndl(2);
            centerText(redColor + "             Invalid choice. Try again." + resetColor);
            printEndl(2);
        }

        if (list)
        {
            displayInfo(list);
            askToAddToFavourites("Modern", list);
        }
    }

    if (list)
    {
        deleteInfoList(list);
    }
}
