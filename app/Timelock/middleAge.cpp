#include "middleAge.h"
#include "timeline.h"
#include "user.h"
#include "admin.h"
#include "validation.h"
#include "events.h"

INFONODE* loadMiddleAgeInfo()
{
    ifstream file("../data/middleAge/middleAge.txt");

    if (!file)
    {
        cout << "Error: Could not open middleAge.txt" << endl;
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

void displayMiddleAgeInfo(INFONODE* head)
{
    INFONODE* current = head;

    while (current)
    {
        centerText(current->data);
        cout << endl;

        current = current->next;
    }
}

void displaymiddleAgeEvents()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    centerText("            Start exploring " + purpleColor + "Middle Age " + resetColor + "era!");

    printEndl(3);

    INFONODE* infoList = loadMiddleAgeInfo();
    if (infoList)
    {
        displayMiddleAgeInfo(infoList);
        deleteInfoList(infoList);
    }

    printEndl(4);

    string MissdleAgeEvents[4] = { "Viking Age", "Battle of Hastings", "Hundred Years' War", "Black Death" };

    printStrRepeat(" ", 25);

    for (int i = 0; i < 4; i++)
    {
        cout << i + 1 << ". " << MissdleAgeEvents[i];
        printStrRepeat(" ", 10);
    }

    printEndl(4);
}

void displaymiddleAgeQuiz() 
{

    ifstream file("../data/middleAge/middleAgeQuiz.txt");
    if (!file) 
    {
        cout << "Error: Could not open middleAgeQuiz.txt" << endl;
        return;
    }

    string resetColor = "\033[37m";
    string greenColor = "\033[32m";
    string purpleColor = "\033[35m";
    string redColor = "\033[31m";

    char correctAnswers[] = { 'B', 'C', 'B', 'C', 'D' };
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


    centerText("           Exam score: " + purpleColor + to_string(counter) + "/5" + resetColor); cout << endl;

    if (counter >= 3)
    {
        centerText("            Exam " + greenColor + "PASSED! " + resetColor + "You can continue to the next era!");
        if (progres == 2)
        {
            progres += 1;
            saveUserProgress();
        }
        else
        {

        }

    }
    else
    {
        centerText("            Exam " + redColor + "FAILED! " + resetColor + "You shall read more carefully and try again!");
        cout << endl;

    }

    deleteList(head);
}

void displayMiddleAge()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    cout << endl;
    printStrRepeat(" ", 2);
    cout << "PRESS " << purpleColor << "ESC" << resetColor << " TO GO BACK";

    string title[21] = {
    "",
    "           .****************..********..**************..***************..**************..**************.",
    "           *    _.      ._       .__.       ________         _______         .__.           .________.   *",
    "           *   |  \\    /  |      |  |      |   __   \\       |   __   \\       |  |           |  ______|   *",
    "           *   |   \\  /   |      |  |      |  |   |  |      |  |   |  |      |  |           |  |_____    *",
    "           *   |    \\/    |      |  |      |  |   |  |      |  |   |  |      |  |           |  ______|   *",
    "           *   |  |\\  /|  |      |  |      |  |___|  |      |  |___|  |      |  |____.      |  |_____    *",
    "           *   |__| \\/ |__|      |__|      |_______./       |_______./       |_______|      |________|   *",
    "           *.                ..        ..              ..               ..              ..              .*",
    "           ****************  ********  **************  ***************  **************  **************",
    "",
    "           .***************..*************..**************.",
    "           *   .________.       ________       .________.   *",
    "           *   |   __   |      /   _____|      |  ______|   *",
    "           *   |  |__|  |      |  |            |  |_____    *",
    "           *   |   __   |      |  |  .__.      |  ______|   *",
    "           *   |  |  |  |      |  |__|  |      |  |_____    *",
    "           *   |__|  |__|      \\________/      |________|   *",
    "            *.               ..             ..              .* ",
    "           ***************  *************  **************  ",
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
        adminPanel(3);
    }
    else
    {
        userPanel(3);
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