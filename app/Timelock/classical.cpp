#include "classical.h"
#include "timeline.h"
#include "validation.h"
#include "admin.h"
#include "user.h"

CLASSICAL* loadClassicalInfo()
{
    ifstream file("../data/classical/classical.txt");

    if (!file)
    {
        cout << "Error: Could not open classical.txt" << endl;
        return nullptr;
    }

    CLASSICAL* head = nullptr;
    CLASSICAL* tail = nullptr;
    string line;

    while (getline(file, line))
    {
        CLASSICAL* newNode = new CLASSICAL{ line, nullptr };

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

void displayClassicalInfo(CLASSICAL* head) 
{
    CLASSICAL* current = head;

    while (current)
    {
        centerText(current->data);
        cout << endl;

        current = current->next;
    }
}

void displayClassicalEvents()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    centerText("            Start exploring " + purpleColor + "Classical " + resetColor + "era!");

    printEndl(3);

    CLASSICAL* infoList = loadClassicalInfo();
    if (infoList)
    {
        displayClassicalInfo(infoList);
    }

    printEndl(5);

    string ClassicalEvents[4] = { "The Greco - Persian Wars", "The Peloponnesian War", "The Roman Revolution", "The Decline and Fall of the Roman Empire"};

    printStrRepeat(" ", 28);

    for (int i = 0; i < 4; i++)
    {
        cout << i + 1 << ". " << ClassicalEvents[i];
        printStrRepeat(" ", 10);
        if (i == 2)
        {
            printEndl(3);
            printStrRepeat(" ", 52);
        }
    }

    printEndl(3);
    centerText(purpleColor + "            Choose an event to explore! " + resetColor);
    int event;
    cin >> event;
}


void displayClassicalQuiz() 
{
    ifstream file("../data/classical/classicalEraQuiz.txt");

    if (!file) 
    {
        cout << "Error: Could not open classicalEraQuiz.txt" << endl;
        return;
    }
    string resetColor = "\033[37m";   // White 
    string greenColor = "\033[32m";  // Green
    string purpleColor = "\033[35m";  // Purple
    string redColor = "\033[31m";  // Red

    char correctAnswers[] = { 'C', 'C', 'B', 'C', 'B' };
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

            while (!answerGiven) 
            {
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

void displayClassical()
{
    int page = 2;
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    cout << endl;
    printStrRepeat(" ", 2);
    cout << "PRESS " << purpleColor << "ESC" << resetColor << " TO GO BACK";

    string title[11] = {
    "",
    "       .*************..**************..**************..*************..*************..*********..**************..**************..*************.",
    "      *   .________.      .__.           .________.        ______         ______        .__.      .________.      .________.      .__.        *",
    "      *   |  ______|      |  |           |   __   |       '  ____|       '  ____|       |  |      |  ______|      |   __   |      |  |        *",
    "      *   |  |            |  |           |  |__|  |      |  (__         |  (__          |  |      |  |            |  |__|  |      |  |        *",
    "      *   |  |            |  |           |   __   |       '.___ `.       '.___ `.       |  |      |  |            |   __   |      |  |        *",
    "      *   |  |_____.      |  |____.      |  |  |  |       _____)  |      _____)  |      |  |      |  |_____.      |  |  |  |      |  |____.   *",
    "      *   |________|      |_______|      |__|  |__|      |______.'      |______.'       |__|      |________|      |__|  |__|      |_______|   *",
    "      *.             ..              ..              ..             ..             ..         ..              ..              ..             .*",
    "        *************  **************  **************  *************  *************  *********  **************  **************  *************  ",
    ""
    };

    printEndl(2);

    for (int i = 0; i < 11; i++)
    {
        centerText(purpleColor + title[i] + resetColor);
        cout << endl;
    }

    printEndl(3);

    string role = getCurrentUserRole();
    if (role == "admin")
    {
        adminPanel(2);
    }
    else
    {
        userPanel(2);
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
