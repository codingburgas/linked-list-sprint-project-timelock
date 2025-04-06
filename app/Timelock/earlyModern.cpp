#include "earlyModern.h"
#include "timeline.h"
#include "validation.h"
#include "admin.h"
#include "user.h"
#include "events.h"

INFONODE* loadEarlyModernInfo()
{
    ifstream file("../data/earlyModern/earlyModern.txt");

    if (!file)
    {
        cout << "Error: Could not open earlyModern.txt" << endl;
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

void displayEarlyModernInfo(INFONODE* head)
{
    INFONODE* current = head;

    while (current)
    {
        centerText(current->data);
        cout << endl;

        current = current->next;
    }
}

void displayearlyModernEvents()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    centerText("            Start exploring " + purpleColor + "Early Modern " + resetColor + "era!");

    printEndl(3);

    INFONODE* infoList = loadEarlyModernInfo();
    if (infoList)
    {
        displayEarlyModernInfo(infoList);
    }

    printEndl(5);

    string EarlyModernEvents[3] = { "Thirty Years' War", "Treaty of Utrecht ends War of Spanish Succession", "Turks defeated outside Vienna" };

    printStrRepeat(" ", 16);

    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ". " << EarlyModernEvents[i];
        printStrRepeat(" ", 9);
    }

    printEndl(4);
    displayEarlyModernEventsInfo();
}

void displayearlyModernQuiz()
{

    ifstream file("../data/earlyModern/earlyModernQuiz.txt");
    if (!file)
    {
        cout << "Error: Could not open earlyModernQuiz.txt" << endl;
        return;
    }

    string resetColor = "\033[37m";
    string greenColor = "\033[32m";
    string purpleColor = "\033[35m";
    string redColor = "\033[31m";

    char correctAnswers[] = { 'B', 'C', 'B', 'C', 'B' };
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
                    centerText("          " + greenColor + "Correct answer! " + resetColor);
                    printEndl(2);
                    counter++;


                }
                else 
                {
                    printEndl(2);
                    centerText("          " + redColor + "Incorrect answer! " + resetColor);
                    printEndl(2);
                    centerText("          Correct answer was:" + purpleColor + correctAnswers[index] + resetColor);
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
        if (progres == 3)
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


void displayEarlyModern()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    cout << endl;
    printStrRepeat(" ", 2);
    cout << "PRESS " << purpleColor << "ESC" << resetColor << " TO GO BACK";

    string title[21] = {
    "",
    "       .**************..**************..**************..*************..*************.",
    "       *   .________.      .________.       _______        .__.          .__    __.   *",
    "       *   |  ______|      |   __   |      |   __  \\       |  |          \\  \\  /  /   *",
    "       *   |  |_____       |  |__|  |      |  |__|  |      |  |           \\  \\/  /    *",
    "       *   |  ______|      |   __   |      |   _   /       |  |            \\    /     *",
    "       *   |  |_____       |  |  |  |      |  |\\  \\        |  |____.        |  |      *",
    "       *   |________|      |__|  |__|      |__| \\__\\       |_______|        |__|      *",
    "       *.              ..              ..              ..             ..             .*",
    "        **************  **************  **************  *************  ************* ",
    "",
    "           .****************..**************..**************..***************..**************..**************. ",
    "           *    _.      ._        ________        ________        .________.       _______         ._.   ._    *",
    "           *   |  \\    /  |      /  .__.  \\      |   __   \\       |  ______|      |   __  \\       |   \\ |  |   *",
    "           *   |   \\  /   |      |  |  |  |      |  |   |  |      |  |_____       |  |__|  |      |    \\|  |   *",
    "           *   |    \\/    |      |  |  |  |      |  |   |  |      |  ______|      |   _   /       |  .     |   *",
    "           *   |  |\\  /|  |      |  |__|  |      |  |___|  |      |  |_____       |  |\\  \\        |  |\\    |   *",
    "           *   |__| \\/ |__|      \\________/      |_______./       |________|      |__| \\__\\       |__| \\.__|   *",
    "           *.                ..              ..              ..               ..              ..              .*",
    "           ****************  **************  **************  ***************  **************  **************",
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
        adminPanel(4);
    }
    else
    {
        userPanel(4);
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