#include "search.h"
#include "timeline.h"

// Load events from files in the specified folder
SEARCH* loadEventsFromFolder(const string& folderPath)
{
    SEARCH* head = nullptr;
    SEARCH* tail = nullptr;

    string searchPath = folderPath + "\\*.txt";
    WIN32_FIND_DATAA findFileData;
    HANDLE hFind = FindFirstFileA(searchPath.c_str(), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE)
    {
        cout << "Failed to open directory: " << folderPath << endl;
        return nullptr;
    }

    do
    {
        string fileName = findFileData.cFileName;

        string lowerFileName = fileName;
        transform(lowerFileName.begin(), lowerFileName.end(), lowerFileName.begin(), ::tolower);
        if (lowerFileName.find("quiz") != string::npos)
        {
            continue;
        }

        string filePath = folderPath + "\\" + fileName;
        ifstream file(filePath);
        if (!file.is_open())
        {
            continue;
        }

        string line, fullContent;
        while (getline(file, line))
        {
            fullContent += line + "\n";
        }
        file.close();

        SEARCH* newNode = new SEARCH{ fileName, fullContent, nullptr };
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

    } while (FindNextFileA(hFind, &findFileData) != 0);

    FindClose(hFind);
    return head;
}

// Search for events by year in the specified folder
void searchByDate(const string& folderPath)
{
    string redColor = "\033[31m";
    string resetColor = "\033[37m";
    string purpleColor = "\033[35m";

    while (true)
    {
        SEARCH* head = loadEventsFromFolder(folderPath);
        if (!head) return;

        string searchYear;
        printEndl(2);
        centerText("   Enter year: ");
        cin >> searchYear;

        SEARCH* current = head;
        bool found = false;

        while (current)
        {
            if (current->content.find(searchYear) != string::npos)
            {
                printEndl(2);
                centerText(purpleColor + "              *** Match Found in " + current->fileName + " ***" + resetColor);
                printEndl(2);

                istringstream stream(current->content);
                string line;
                while (getline(stream, line))
                {
                    centerText(line);
                    printEndl(1);
                }
                found = true;
            }
            current = current->next;
        }

        printEndl(2);

        if (!found)
        {
            centerText(redColor + "                  No events found for year " + searchYear + "." + resetColor);
            printEndl(2);
            centerText(purpleColor + "                   Try another year? (Y/N): " + resetColor);
        }
        else
        {
            centerText(purpleColor + "             Search again? (Y/N): " + resetColor);
        }

        char ch;
        while (!_kbhit()) {}
        ch = _getch();

        if (ch == 27 || ch == 'n' || ch == 'N')
        {
            clearScreen();
            displayTimeline();
            return;
        }
    }
}

// Search for events by keyword in the specified folder
void searchByEvent(const string& folderPath)
{
    string redColor = "\033[31m";
    string resetColor = "\033[37m";
    string purpleColor = "\033[35m";

    while (true)
    {
        SEARCH* head = loadEventsFromFolder(folderPath);
        if (!head) return;

        cin.ignore();
        string keyword;
        printEndl(2);
        centerText("    Enter event keyword: ");
        getline(cin, keyword);
        transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);

        SEARCH* current = head;
        bool found = false;

        while (current)
        {
            string lowerContent = current->content;
            transform(lowerContent.begin(), lowerContent.end(), lowerContent.begin(), ::tolower);

            if (lowerContent.find(keyword) != string::npos)
            {
                printEndl(2);
                centerText(purpleColor + "              *** Match Found in " + current->fileName + " ***" + resetColor);
                printEndl(2);

                istringstream stream(current->content);
                string line;
                while (getline(stream, line))
                {
                    centerText(line);
                    printEndl(1);
                }
                found = true;
            }
            current = current->next;
        }

        printEndl(2);

        if (!found)
        {
            centerText(redColor + "                 No events found containing \"" + keyword + "\"." + resetColor);
            printEndl(2);
            centerText(purpleColor + "                Try another keyword? (Y/N): " + resetColor);
        }
        else
        {
            centerText(purpleColor + "             Search again? (Y/N): " + resetColor);
        }

        char ch;
        while (!_kbhit())
        {

        }
        ch = _getch();

        if (ch == 27 || ch == 'n' || ch == 'N')
        {
            clearScreen();
            displayTimeline();
            return;
        }
    }
}

// Search for events by year in the specified era
void searchByDate(int page)
{
    string folderPath;
    switch (page) {
    case 1:
    {
        folderPath = "../data/prehistoric";
        break;
    }
    case 2:
    {
        folderPath = "../data/classical";
        break;
    }
    case 3:
    {
        folderPath = "../data/middleAge";
        break;
    }
    case 4:
    {
        folderPath = "../data/earlyModern";
        break;
    }
    case 5:
    {
        folderPath = "../data/modern";
        break;
    }
    default:
    {
        return;
    }
    }
    searchByDate(folderPath);
}

// Search for events by keyword in the specified era
void searchByEvent(int page)
{
    string folderPath;
    switch (page)
    {
    case 1:
    {
        folderPath = "../data/prehistoric";
        break;
    }
    case 2:
    {
        folderPath = "../data/classical";
        break;
    }
    case 3:
    {
        folderPath = "../data/middleAge";
        break;
    }
    case 4:
    {
        folderPath = "../data/earlyModern";
        break;
    }
    case 5:
    {
        folderPath = "../data/modern";
        break;
    }
    default:
    {
        return;
    }
    }
    searchByEvent(folderPath);
}