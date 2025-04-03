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

void displayClassicalInfo(CLASSICAL* head) {
    CLASSICAL* current = head;

    while (current)
    {
        centerText(current->data);
        cout << endl;

        current = current->next;
    }
}

void displayClassicalQuiz() {
    ifstream file("../data/classical/classicalEraQuiz.txt");

    if (!file) {
        cout << "Error: Could not open prehistoric.txt" << endl;
        return;
    }
    string resetColor = "\033[37m";   // White 
    string greenColor = "\033[32m";  // Green
    string blueColor = "\033[36m";  // Green
    string redColor = "\033[31m";  // Red

    char correctAnswers[] = { 'C', 'C', 'B', 'C', 'B' };
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

    centerText("            Start exploring " + purpleColor + "Classical " + resetColor + "era events!");
    
    printEndl(3);


    CLASSICAL* infoList = loadClassicalInfo();
    if (infoList)
    {
        displayClassicalInfo(infoList);
    }

    printEndl(4);

    string role = getCurrentUserRole();
    if (role == "admin")
    {
        adminPanel();
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
