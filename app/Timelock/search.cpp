#include "search.h"
#include "timeline.h"

SEARCH* loadEventsFromFolder(const string& folderPath)
{
    SEARCH* head = nullptr;
    SEARCH* tail = nullptr;

    DIR* dir = opendir(folderPath.c_str());
    if (!dir)
    {
        cout << "Failed to open directory: " << folderPath << endl;
        return nullptr;
    }

    dirent* entry;
    while ((entry = readdir(dir)) != nullptr)
    {
        string fileName = entry->d_name;

        if (fileName == "." || fileName == "..")
        {
            continue; 
        }
        if (fileName.find(".txt") == string::npos)
        { 
            continue;
        }

        string lowerFileName = fileName;
        transform(lowerFileName.begin(), lowerFileName.end(), lowerFileName.begin(), ::tolower);
        if (lowerFileName.find("quiz") != string::npos)
        { 
            continue;
        }

        ifstream file(folderPath + "/" + fileName);
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
    }

    closedir(dir);
    return head;
}

void searchByDate(const string& folderPath)
{
    string redColor = "\033[31m";
    string resetColor = "\033[37m";
    string purpleColor = "\033[35m";

    while (true) 
    {
    SEARCH* head = loadEventsFromFolder(folderPath);
    if (!head)
    {
        return;
    }

    string searchYear;
    centerText("        Enter year: ");
    cin >> searchYear;

    SEARCH* current = head;
    bool found = false;
    while (current) 
    {
        if (current->content.find(searchYear) != string::npos)
        {
            printEndl(2);
            centerText(purpleColor + "                  *** Match Found in " + current->fileName + " ***" + resetColor);
            printEndl(2);

            istringstream stream(current->content);
            string line;
            while (getline(stream, line))
            {
                centerText(line);
            }
            found = true;
        }
        current = current->next;
    }

    if (!found) 
    {
        printEndl(2);
        centerText(redColor + "                      No events found for year " + searchYear + "." + resetColor);
        printEndl(2);
        centerText(purpleColor + "                     Try another year? (Y/N)" + resetColor);
        while (!_kbhit()) {}
        char ch = _getch();

        if (ch == 27)  // ESC
        {
            system("cls");
            displayTimeline();
            return;
        }
        else if (ch == 'Y' || ch == 'y')
        {
            continue;
        }
        else
        {
            system("cls");
            displayTimeline();
            return;
        }
    }
    else
    {
        printEndl(2);
        centerText(purpleColor + "                  Search again? (Y/N)" + resetColor);
        while (!_kbhit())
        {

        }
        char ch = _getch();

        if (ch == 27)
        {
            system("cls");
            displayTimeline();
            return;
        }
        else if (ch == 'Y' || ch == 'y')
        {
            continue;
        }
        else
        {
            system("cls");
            displayTimeline();
            return;
        }
    }
    }
}

void searchByEvent(const string& folderPath)
{
    string redColor = "\033[31m";
    string resetColor = "\033[37m";
    string purpleColor = "\033[35m";

    while (true)
    { 
    SEARCH* head = loadEventsFromFolder(folderPath);
    if (!head) 
    {
        return; 
    }

    cin.ignore();
    string keyword;
    centerText("      Enter event keyword: ");
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
            centerText(purpleColor + "                  *** Match Found in " + current->fileName + " ***" + resetColor);
            printEndl(2);

            istringstream stream(current->content);
            string line;
            while (getline(stream, line))
            {
                centerText(line);
            }
            found = true;
        }
        current = current->next;
    }

    if (!found)
    {
        printEndl(2);
        centerText(redColor + "                    No events found containing \"" + keyword + "\"." + resetColor);
        printEndl(2);
        centerText(purpleColor + "                     Try another keyword? (Y/N) " + resetColor);
        printEndl(2);

        while (!_kbhit())
        {

        }
        char ch = _getch();

        if (ch == 27)
        {
            system("cls");
            displayTimeline();
            return;
        }
        else if (ch == 'Y' || ch == 'y')
        {
            continue;
        }
        else
        {
            system("cls");
            displayTimeline();
            return;
        }
    }
    else
    {
        printEndl(2);
        centerText(purpleColor + "                  Search again? (Y/N)" + resetColor);
        while (!_kbhit())
        {
        }
        char ch = _getch();

        if (ch == 27)
        {
            system("cls");
            displayTimeline();
            return;
        }
        else if (ch == 'Y' || ch == 'y')
        {
            continue;
        }
        else
        {
            system("cls");
            displayTimeline();
            return;
        }
    }
    }
}
  

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
