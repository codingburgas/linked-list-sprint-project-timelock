#include "prehistoric.h"
#include "validation.h"
#include "admin.h"
#include "user.h"
#include "timeline.h"

PREHISTORIC* loadPrehistoricInfo()
{
    ifstream file("../data/prehistoric/prehistoric.txt");

    if (!file) 
    {
        cout << "Error: Could not open prehistoric.txt" << endl;
        return nullptr;
    }

    PREHISTORIC* head = nullptr;
    PREHISTORIC* tail = nullptr;
    string line;

    while (getline(file, line)) 
    {
        PREHISTORIC* newNode = new PREHISTORIC{ line, nullptr };

        if (!head) 
        {
            head = newNode;
            tail = newNode;
        }
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    file.close();
    return head;
}

void displayPrehistoricInfo(PREHISTORIC* head) 
{
    PREHISTORIC* current = head;

    while (current) 
    {
        centerText(current->data);
        cout << endl;

        current = current->next;
    }
}

void displayPrehistoricEvents()
{
        string resetColor = "\033[37m";   // White 
        string purpleColor = "\033[35m";  // Purple

        centerText("            Start exploring " + purpleColor + "Prehistoric " + resetColor + "era!");

        printEndl(3);

        PREHISTORIC* infoList = loadPrehistoricInfo();
        if (infoList)
        {
            displayPrehistoricInfo(infoList);
        }

        printEndl(5);

        string PrehistoricEvents[3] = { "Stone Age", "Bronze Age", "Iron Age" };

        printStrRepeat(" ", 48);

        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << ". " << PrehistoricEvents[i];
            printStrRepeat(" ", 9);
        }

        printEndl(3);
        centerText(purpleColor + "            Choose an event to explore! " + resetColor);
        int event;
        cin >> event;
}


void displayPrehistoricQuiz() 
{
    ifstream file("../data/prehistoric/prehistoricQuiz.txt");

    if (!file) 
    {
        cout << "Error: Could not open prehistoric.txt" << endl;
        return;
    }

    string resetColor = "\033[37m";   // White 
    string greenColor = "\033[32m";  // Green
    string purpleColor = "\033[35m";  // Purple
    string redColor = "\033[31m";  // Red

    char correctAnswers[] = { 'C', 'B', 'B', 'B', 'B' };
    int counter = 0;
    string line;
    int index = 0;
    bool passed = false;

    while (getline(file, line)) 
    {
        printStrRepeat(" ", 2);
        cout << line << endl;

        if (line.find(':') != string::npos) 
        {
            char answer;
            bool answerGiven = false;

            while (!answerGiven) {
                cin >> answer;
                cout << endl;

                if (toupper(answer) == correctAnswers[index]) 
                {
                    cout << "Correct answer";
                    cout << endl;
                    counter += 1;
                    answerGiven = true;
                    progres += 1;
                }
                else 
                {
                    cout << "Incorrect answer.";
                    cout << endl;
                    answerGiven = true;
                }
            }
            index++;
        }
    }
    if (counter >= 3) 
    {
        centerText("           Exam score: " + purpleColor + to_string(counter) + "/5" + resetColor);
        cout << endl;
        centerText("            Exam " + greenColor + "PASSED! " + resetColor + "You can continuo to the next era!");
        cout << endl;
        passed = true;
        
    }
    else 
    {
        centerText("           Exam score: " + purpleColor + to_string(counter) + "/5" + resetColor);
        cout << endl;
        centerText("            Exam " + redColor + "FAILED! " + resetColor + "You shall read more carefully and try again!");
        cout << endl;
    }
    file.close();
}

void displayPrehistoric() 
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    cout << endl;
    printStrRepeat(" ", 2);
    cout << "PRESS " << purpleColor << "ESC" << resetColor << " TO GO BACK";

    const string title[21] = {
    "",
    "           .**************..*************..**************.",
    "           *    _______         _______       .________.   *",
    "           *   |   __  \\       |   __  \\      |  ______|   *",
    "           *   |  |__|  |      |  |__|  |     |  |_____    *",
    "           *   |   ____/       |   _   /      |  ______|   *",
    "           *   |  |            |  |\\  \\       |  |_____    *",
    "           *   |__|            |__| \\__\\      |________|   *",
    "           *.              ..             ..              .*",
    "           **************  *************  **************",
    "",
    "         .**************..********..**************..*************..**************..**************..********..**************.",
    "         *   .__.  .__.      .__.        ______       .________.       ________        _______        .__.      .________.   *",
    "         *   |  |  |  |      |  |       '  ____|      |___  ___|      /  .__.  \\      |   __  \\       |  |      |  ______|   *",
    "         *   |  |__|  |      |  |      |  (__            |  |         |  |  |  |      |  |__|  |      |  |      |  |         *",
    "         *   |   __   |      |  |       '.___ `.         |  |         |  |  |  |      |   _   /       |  |      |  |         *",
    "         *   |  |  |  |      |  |       _____)  |        |  |         |  |__|  |      |  |\\  \\        |  |      |  |_____.   *",
    "         *   |__|  |__|      |__|      |______.'         |__|         \\________/      |__| \\__\\       |__|      |________|   *",
    "         *.              ..        ..              ..             ..              ..              ..        ..              .*",
    "         **************  ********  **************  *************  **************  **************  ********  **************",
    ""
    };

    printEndl(2);

    for (int i = 0; i < 21; i++)
    {
        centerText(purpleColor + title[i] + resetColor);
        cout << endl;
    }

    printEndl(3);

    string role = getCurrentUserRole();
    if (role == "admin")
    {
        adminPanel(1);
    }
    else
    {
        userPanel(1);
    }

    while (!_kbhit()) 
    {

    }

    char ch = _getch();

    if (ch == 27) 
    {
        system("cls");
        displayTimeline();
    }
}