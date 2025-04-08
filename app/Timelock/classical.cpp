#include "classical.h"
#include "timeline.h"
#include "validation.h"
#include "admin.h"
#include "user.h"
#include "events.h"

// Load information about the Classical era from a file
INFONODE* loadClassicalInfo()
{
    ifstream file("../data/classical/classical.txt");

    if (!file)
    {
        cout << "Error: Could not open classical.txt" << endl;
        return nullptr;
    }

    INFONODE* head = nullptr;
    INFONODE* tail = nullptr;
    string line;

    while (getline(file, line))
    {
        INFONODE* newNode = new INFONODE{ line, nullptr };

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

// Display information about the Classical era
void displayClassicalInfo(INFONODE* head)
{
    INFONODE* current = head;

    while (current)
    {
        centerText(current->data);
        cout << endl;

        current = current->next;
    }
}

// Display events from the Classical era
void displayClassicalEvents()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    centerText("            Start exploring " + purpleColor + "Classical " + resetColor + "era!");

    printEndl(3);

    INFONODE* infoList = loadClassicalInfo();
    if (infoList)
    {
        displayClassicalInfo(infoList);
        deleteInfoList(infoList);
    }

    printEndl(4);

    string ClassicalEvents[4] = { "The Greco - Persian Wars", "The Peloponnesian War", "The Roman Revolution", "The Decline and Fall of the Roman Empire" };

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
    printEndl(4);
}

// Display a quiz about the Classical era
void displayClassicalQuiz()
{
    ifstream file("../data/classical/classicalEraQuiz.txt");
    if (!file)
    {
        cout << "Error: Could not open classicalEraQuiz.txt" << endl;
        return;
    }

    string resetColor = "\033[37m";
    string greenColor = "\033[32m";
    string purpleColor = "\033[35m";
    string redColor = "\033[31m";

    char correctAnswers[] = { 'C', 'C', 'B', 'C', 'B','C','C' };
    int counter = 0, index = 0;

    QUIZNODE* head = nullptr;
    string line;
    while (getline(file, line)) appendNode(head, line);
    file.close();

    QUIZNODE* current = head;
    while (current)
    {
        printStrRepeat(" ", 2);
        cout << current->line << endl;

        if (current->line.find(':') != string::npos)
        {
            char answer;
            bool answered = false;
            while (!answered)
            {
                cin >> answer;
                cout << endl;
                if (toupper(answer) == correctAnswers[index])
                {
                    printEndl(2);
                    centerText("              " + greenColor + "Correct answer! " + resetColor);
                    printEndl(2);
                    counter++;
                }
                else
                {
                    printEndl(2);
                    centerText("              " + redColor + "Incorrect answer! " + resetColor);
                    printEndl(2);
                    centerText("             Correct answer was: " + greenColor + correctAnswers[index] + resetColor);
                    printEndl(2);
                }
                answered = true;
                index++;
            }
        }
        current = current->next;
    }

    centerText("           Exam score: " + purpleColor + to_string(counter) + "/7" + resetColor); cout << endl;

    if (counter >= 5)
    {
        centerText("            Exam " + greenColor + "PASSED! " + resetColor + "You can continue to the next era!");
        if (progres == 1)
        {
            progres += 1;
            saveUserProgress();
        }
    }
    else
    {
        centerText("            Exam " + redColor + "FAILED! " + resetColor + "You shall read more carefully and try again!");
        cout << endl;
    }

    deleteList(head);
}

// Display the Classical era section and handle user interactions
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
        clearScreen();
        displayClassical();
    }
}