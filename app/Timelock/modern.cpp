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

void displayModernInfo(MODERN* head) 
{
    MODERN* current = head;

    while (current)
    {
        centerText(current->data);
        cout << endl;

        current = current->next;
    }
}

void displayModernEvents()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    centerText("             Start exploring " + purpleColor + "Modern " + resetColor + "era!");

    printEndl(3);

    MODERN* infoList = loadModernInfo();
    if (infoList)
    {
        displayModernInfo(infoList);
    }

    printEndl(5);

    string ModernEvents[5] = { "Industrial Revolution", "World War I", "Great Depression", "World War II", "Cold War" };

    printStrRepeat(" ", 13);

    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << ModernEvents[i];
        printStrRepeat(" ", 9);
    }

    printEndl(3);
    centerText(purpleColor + "            Choose an event to explore! " + resetColor);
    int event;
    cin >> event;
}


void displayModernQuiz()
{

    ifstream file("../data/modern/ModernQuiz.txt");
    if (!file) {
        cout << "Error: Could not open ModernQuiz.txt" << endl;
        return;
    }

    string resetColor = "\033[37m";
    string greenColor = "\033[32m";
    string purpleColor = "\033[35m";
    string redColor = "\033[31m";

    char correctAnswers[] = { 'C', 'B', 'D', 'C', 'B' };
    int counter = 0, index = 0;

    QUIZNODE* head = nullptr;
    string line;
    while (getline(file, line)) appendNode(head, line);
    file.close();

    QUIZNODE* current = head;
    while (current) {
        printStrRepeat(" ", 2);
        cout << current->line << endl;

        if (current->line.find(':') != string::npos) {
            char answer;
            bool answered = false;
            while (!answered) {
                cin >> answer;
                cout << endl;
                if (toupper(answer) == correctAnswers[index]) {
                    printEndl(2);
                    centerText("          " + greenColor + "Correct answer! " + resetColor);
                    printEndl(2);
                    counter++;


                }
                else {
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
        centerText("            Exam " + greenColor + "PASSED! " + resetColor + "Congrats on passing the last quiz!");
        
    }
    else
    {
        centerText("            Exam " + redColor + "FAILED! " + resetColor + "You shall read more carefully and try again!");
        cout << endl;
    }

    deleteList(head);
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

    string role = getCurrentUserRole();
    if (role == "admin")
    {
        adminPanel(5);
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
