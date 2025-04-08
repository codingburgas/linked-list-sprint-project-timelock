#include "addEvents.h"
#include "dateUtils.h"

// Get the file path for the specified era based on the page number
string getEraPath(int page)
{
    switch (page)
    {
    case 1: return "../data/prehistoric";
    case 2: return "../data/classical";
    case 3: return "../data/middleAge";
    case 4: return "../data/earlyModern";
    case 5: return "../data/modern";
    default: return "";
    }
}

// Display the title for adding an event
void displayAddTitle()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m"; // Purple

    cout << endl;
    printStrRepeat(" ", 2);
    cout << "PRESS " << purpleColor << "ESC" << resetColor << " TO GO BACK";

    string add[11] =
    {
         "",
         "          .**************..**************..***************.",
         "          *   .________.      ________          ________    *",
         "          *   |   __   |      |   __   \\       |   __   \\   *",
         "            *   |  |__|  |      |  |   |  |      |  |   |  |   *",
         "            *   |   __   |      |  |   |  |      |  |   |  |   *",
         "           *   |  |  |  |      |  |___|  |      |  |___|  |   *",
         "            *   |__|  |__|      |_______./       |_______./    *",
         "           *.              ..              ..               .*",
         "           **************  **************  ***************",
         ""
    };

    printEndl(2);

    for (int i = 0; i < 11; i++)
    {
        centerText(purpleColor + add[i] + resetColor);
        cout << endl;
    }
    printEndl(3);
}

// Create a new event file with the given details
void createEventFile(const string& folderPath, const string& title, const string& date, const string& description)
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m"; // Purple
    string greenColor = "\033[32m";  // Green
    string redColor = "\033[31m";   // Red

    string filename = folderPath + "/" + title + ".txt";
    ofstream out(filename);
    if (!out)
    {
        centerText(redColor + "Failed to create file." + resetColor);
        cout << endl;
        return;
    }

    centerText(purpleColor + "        Title: " + resetColor + title);
    printEndl(2);
    centerText(purpleColor + "        Date: " + resetColor + date);
    printEndl(2);
    centerText(purpleColor + "        Description: " + resetColor + description);
    printEndl(2);
    centerText(greenColor + "        Event added successfully: " + resetColor + filename);
    printEndl(2);
}

// Add a new event to the specified era, either at the beginning or end
void addEventGeneric(int page, bool atBeginning)
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m"; // Purple

    cin.ignore();
    string title, date, description;
    centerText(purpleColor + "         Enter event title: " + resetColor);
    getline(cin, title);
    printEndl(2);
    centerText(purpleColor + "        Enter event year: " + resetColor);
    getline(cin, date);
    printEndl(2);
    centerText(purpleColor + "            Enter event description: " + resetColor);
    getline(cin, description);
    printEndl(2);

    string folderPath = getEraPath(page);
    int eventYear = stoi(date);

    if (isEarliestYear(eventYear, folderPath))
    {
        centerText(purpleColor + "          This is the earliest event in this era!" + resetColor);
        printEndl(2);
    }
    else if (isLatestYear(eventYear, folderPath))
    {
        centerText(purpleColor + "          This is the latest event in this era!" + resetColor);
        printEndl(2);
    }
    else
    {
        if (atBeginning)
        {
            centerText(purpleColor + "          This event is NOT the earliest in this era." + resetColor);
            printEndl(2);
        }
        else
        {
            centerText(purpleColor + "          This event is NOT the latest in this era." + resetColor);
            printEndl(2);
        }
    }

    createEventFile(folderPath, title, date, description);
}

// Add a new event at the beginning of the specified era
void addEventAtBeginning(int page)
{
    addEventGeneric(page, true);
}

// Add a new event at the end of the specified era
void addEventAtEnd(int page)
{
    addEventGeneric(page, false);
}
