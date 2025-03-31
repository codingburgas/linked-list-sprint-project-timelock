#include "timeline.h"
#include "prehistoric.h"
#include "classical.h"
#include "middleAge.h"
#include "earlyModern.h"
#include "modern.h"


ERANODE* headEra = nullptr;
void testEraData() {
    addEra(1, "Prehistoric era");
    addEra(2, "Classical era");
    addEra(3, "The Middle Age era");
    addEra(4, "Early Modern era");
    addEra(5, "Modern era");
}


string eras[5] = {
    "1. Prehistoric era",
    "2. Classical era",
    "3. The Middle Age era",
    "4. Early Modern era",
    "5. Modern era"
};

string resetColor = "\033[37m";   // White 
string purpleColor = "\033[35m";  // Purple


void displayEras(){
    for (string str : eras) {
        cout << str << endl;
    }
}


void displayTimeline()
{
    string title[11] = {
    "",
    "      .**************..*********..****************..*************..*************..*********..*************..**************.",
    "      *   .________.      .__.       _.      ._      .________.      .__.           .__.       ._.   ._       .________.   *",
    "      *   |___  ___|      |  |      |  \\    /  |     |  ______|      |  |           |  |      |   \\ |  |      |  ______|   *",
    "      *      |  |         |  |      |   \\  /   |     |  |_____       |  |           |  |      |    \\|  |      |  |_____    *",
    "      *      |  |         |  |      |    \\/    |     |  ______|      |  |           |  |      |  .     |      |  ______|   *",
    "      *      |  |         |  |      |  |\\  /|  |     |  |_____       |  |____.      |  |      |  |\\    |      |  |_____    *",
    "      *      |__|         |__|      |__| \\/ |__|     |________|      |_______|      |__|      |__| \\.__|      |________|   *",
    "      *.              ..        ..                ..             ..             ..         ..             ..              .*",
    "      **************  ********  ****************  *************  *************  *********  *************  **************",
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

    printEndl(3);
    printStrRepeat(" ", 2);
    cout << "Choose an era to explore: ";

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

void addEra(int id, string name) {
    headEra = new ERANODE{ id, name, headEra };
     
    cout << "Era added successfully!" << endl;
}

void editEra() {
    if (!headEra) { 
        cout << "No eras available to edit!" << endl;
        return;
    }

    int id;
    cout << "Enter the ID of the Era to edit: ";
    cin >> id;
    cin.ignore();

    ERANODE* temp = headEra;
    while (temp) {
        if (temp->id == id) {
            cout << "Enter new name: ";
            getline(cin, temp->name);
            cout << "Era updated successfully!" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Era not found!" << endl;

}

void deleteEra() {
    if (!headEra) {
        cout << "No eras available to delete!" << endl;
        return;
    }

    int id;
    cout << "Enter the ID of the Era to delete: ";
    cin >> id;

    ERANODE* temp = headEra, * prev = nullptr;
    while (temp && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Era not found!" << endl;
        return;
    }

    if (!prev) headEra = temp->next;
    else prev->next = temp->next;

    delete temp;
    cout << "Era deleted successfully!" << endl;
}
