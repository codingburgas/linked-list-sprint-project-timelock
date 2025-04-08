#include "search.h"

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
        { continue;
        }

        string lowerFileName = fileName;
        transform(lowerFileName.begin(), lowerFileName.end(), lowerFileName.begin(), ::tolower);
        if (lowerFileName.find("quiz") != string::npos)
        { continue;
        }

        ifstream file(folderPath + "/" + fileName);
        if (!file.is_open())
        { continue;
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
    SEARCH* head = loadEventsFromFolder(folderPath);
    if (!head)
    {
        return;
    }

    string searchYear;
    cout << "Enter year: ";
    cin >> searchYear;

    SEARCH* current = head;
    bool found = false;
    while (current) 
    {
        if (current->content.find(searchYear) != string::npos)
        {
            cout << "\n=== Match Found in " << current->fileName << " ===" << endl;
            cout << current->content << "\n" << endl;
            found = true;
        }
        current = current->next;
    }

    if (!found) 
    {
        cout << "\nNo events found for year " << searchYear << endl;
    }
}

void searchByEvent(const string& folderPath)
{
    SEARCH* head = loadEventsFromFolder(folderPath);
    if (!head) 
    {
        return; 
    }

    cin.ignore();
    string keyword;
    cout << "Enter event keyword: ";
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
            cout << "\n=== Match Found in " << current->fileName << " ===" << endl;
            cout << current->content << "\n" << endl;
            found = true;
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "\nNo events found containing \"" << keyword << "\"\n";
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
