#include "middleAge.h"
#include "timeline.h"
#include "user.h"
#include "admin.h"
#include "validation.h"

MIDDLEAGE* loadMiddleAgeInfo()
{
    ifstream file("../data/middleAge/middleAge.txt");

    if (!file)
    {
        cout << "Error: Could not open middleAge.txt" << endl;
        return nullptr;
    }

    MIDDLEAGE* head = nullptr;
    MIDDLEAGE* tail = nullptr;
    string line;

    while (getline(file, line))
    {
        MIDDLEAGE* newNode = new MIDDLEAGE{ line, nullptr };

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

void displayMiddleAgeInfo(MIDDLEAGE* head) {
    MIDDLEAGE* current = head;

    while (current)
    {
        centerText(current->data);
        cout << endl;

        current = current->next;
    }
}

void displaymiddleAgeQuiz() {
    ifstream file("../data/middleAge/middleAgeQuiz.txt");

    if (!file) {
        cout << "Error: Could not open middleAgeQuiz.txt" << endl;
        return;
    }
    string resetColor = "\033[37m";   // White 
    string greenColor = "\033[32m";  // Green
    string blueColor = "\033[36m";  // Green
    string redColor = "\033[31m";  // Red

    char correctAnswers[] = { 'B', 'C', 'B', 'C', 'D' };
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
        centerText("            Exam " + greenColor + "PASSED! " + resetColor + "You can continuo to the next era!\n");
        passed = true;

    }
    else {
        centerText("           Exam score: " + blueColor + to_string(counter) + "/5\n" + resetColor);
        centerText("            Exam " + redColor + "FAILED! " + resetColor + "You shall read more carefully and try again!\n");
    }
    file.close();
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

    centerText("               Start exploring " + purpleColor + "Middle Age " + resetColor + "era events!");

    printEndl(3);


    MIDDLEAGE* infoList = loadMiddleAgeInfo();
    if (infoList)
    {
        displayMiddleAgeInfo(infoList);
    }

    printEndl(4);

    string role = getCurrentUserRole();
    if (role == "admin")
    {
        adminPanel();
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





