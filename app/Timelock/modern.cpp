#include "modern.h"
#include "timeline.h"
#include "validation.h"
#include "admin.h"
#include "user.h"

MODERN* loadModernInfo()
{
    ifstream file("../data/modern/modern.txt");

    if (!file)
    {
        cout << "Error: Could not open modern.txt" << endl;
        return nullptr;
    }

    MODERN* head = nullptr;
    MODERN* tail = nullptr;
    string line;

    while (getline(file, line))
    {
        MODERN* newNode = new MODERN{ line, nullptr };

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

void displayModernInfo(MODERN* head) {
    MODERN* current = head;

    while (current)
    {
        centerText(current->data);
        cout << endl;

        current = current->next;
    }
}

void displayModernQuiz() {
    ifstream file("../data/modern/ModernQuiz.txt");

    if (!file) {
        cout << "Error: Could not open ModernQuiz.txt" << endl;
        return;
    }
    string resetColor = "\033[37m";   // White 
    string greenColor = "\033[32m";  // Green
    string blueColor = "\033[36m";  // Green
    string redColor = "\033[31m";  // Red

    char correctAnswers[] = { 'C', 'B', 'D', 'C', 'B' };
    int counter = 0;
    string line;
    int index = 0;
    bool passed = false;

    while (getline(file, line)) {
        printStrRepeat(" ", 2);
        cout << line << endl;

        if (line.find(':') != string::npos) {
            char answer;
            bool answerGiven = false;

            while (!answerGiven) {
                cin >> answer;
                cout << endl;

                if (toupper(answer) == correctAnswers[index]) {
                    cout << "Correct answer\n";
                    counter += 1;
                    answerGiven = true;
                    progres += 1;
                }
                else {
                    cout << "Incorrect answer.\n";
                    answerGiven = true;
                }
            }
            index++;
        }
    }
    if (counter >= 3) {
        centerText("           Exam score: " + blueColor + to_string(counter) + "/5\n" + resetColor);
        centerText("            Exam " + greenColor + "PASSED! " + resetColor + "Congrats on passing the last quiz!\n");
        passed = true;

    }
    else {
        centerText("           Exam score: " + blueColor + to_string(counter) + "/5\n" + resetColor);
        centerText("            Exam " + redColor + "FAILED! " + resetColor + "You shall read more carefully and try again!\n");
    }
    file.close();
}


void displayModern()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    cout << endl;
    printStrRepeat(" ", 2);
    cout << "PRESS " << purpleColor << "ESC" << resetColor << " TO GO BACK";

    string title[11] = {
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

    for (int i = 0; i < 11; i++)
    {
        centerText(purpleColor + title[i] + resetColor);
        cout << endl;
    }

    printEndl(3);

    centerText("                Start exploring " + purpleColor + "Modern " + resetColor + "era events!");

    printEndl(3);


    MODERN* infoList = loadModernInfo();
    if (infoList)
    {
        displayModernInfo(infoList);
    }

    printEndl(4);

    string role = getCurrentUserRole();
    if (role == "admin")
    {
        adminPanel();
    }
    else
    {
        userPanel(5);
    }

    while (!_kbhit()) 
    {

    }

    char ch = _getch();

    if (ch == 27) {
        system("cls");
        displayTimeline();
    }
}
