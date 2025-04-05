#include "earlyModern.h"
#include "timeline.h"
#include "validation.h"
#include "admin.h"
#include "user.h"

EARLYMODERN* loadEarlyModernInfo()
{
    ifstream file("../data/earlyModern/earlyModern.txt");

    if (!file)
    {
        cout << "Error: Could not open earlyModern.txt" << endl;
        return nullptr;
    }

    EARLYMODERN* head = nullptr;
    EARLYMODERN* tail = nullptr;
    string line;

    while (getline(file, line))
    {
        EARLYMODERN* newNode = new EARLYMODERN{ line, nullptr };

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

void displayEarlyModernInfo(EARLYMODERN* head) 
{
    EARLYMODERN* current = head;

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

    EARLYMODERN* infoList = loadEarlyModernInfo();
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

    printEndl(3);
    centerText(purpleColor + "            Choose an event to explore! " + resetColor);
    int event;
    cin >> event; 
}

void displayearlyModernQuiz() 
{
    ifstream file("../data/earlyModern/earlyModernQuiz.txt");

    if (!file) 
    {
        cout << "Error: Could not open earlyModernQuiz.txt" << endl;
        return;
    }
    string resetColor = "\033[37m";   // White 
    string greenColor = "\033[32m";  // Green
    string purpleColor = "\033[35m";  // Purple
    string redColor = "\033[31m";  // Red

    char correctAnswers[] = { 'B', 'C', 'B', 'C', 'B' };
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