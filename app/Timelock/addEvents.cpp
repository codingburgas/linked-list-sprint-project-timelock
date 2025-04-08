#include "addEvents.h"
#include "pch.h"
#include "dateUtils.h"

using namespace std;

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

void createEventFile(const string& folderPath, const string& title, const string& date, const string& description) {
    string filename = folderPath + "/" + title + ".txt";
    ofstream out(filename);
    if (!out) 
    {
        cout << "Failed to create file." << endl;
        return;
    }

    out << "Title: " << title << endl;
    out << "Date: " << date << endl;
    out << "Description: " << description << endl;
    out.close();
    cout << "Event added successfully: " << filename << endl;
}
void addEventGeneric(int page, bool atBeginning) 
{
    cin.ignore();
    string title, date, description;
    cout << "Enter event title: ";
    getline(cin, title);
    cout << "Enter event year: ";
    getline(cin, date);
    cout << "Enter event description: ";
    getline(cin, description);

    string folderPath = getEraPath(page);
    int eventYear = stoi(date);

    
    if (isEarliestYear(eventYear, folderPath)) 
    {
        cout << "This is the earliest event in this era!" << endl;
    }
    else if (isLatestYear(eventYear, folderPath))
    {
        cout << "This is the latest event in this era!" << endl;
    }
    else
    {
        if (atBeginning) 
        {
            cout << "This event is NOT the earliest in this era." << endl;
        }
        else
        {
            cout << "This event is NOT the latest in this era." << endl;
        }
    }

    createEventFile(folderPath, title, date, description);
}
void addEventAtBeginning(int page)
{
    addEventGeneric(page, true);
}

void addEventAtEnd(int page) 
{
    addEventGeneric(page, false);
}
