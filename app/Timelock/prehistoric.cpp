#include "prehistoric.h"
#include "validation.h"
#include "admin.h"
#include "user.h"
#include "timeline.h"
#include "events.h"

INFONODE* loadPrehistoricInfo()
{
    ifstream file("../data/prehistoric/prehistoric.txt");

    if (!file) 
    {
        cout << "Error: Could not open prehistoric.txt" << endl;
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

void displayPrehistoricInfo(INFONODE* head)
{
    INFONODE* current = head;

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

        INFONODE* infoList = loadPrehistoricInfo();
        if (infoList)
        {
            displayPrehistoricInfo(infoList);
        }

        printEndl(4);

        string PrehistoricEvents[3] = { "Stone Age", "Bronze Age", "Iron Age" };

        printStrRepeat(" ", 48);

        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << ". " << PrehistoricEvents[i];
            printStrRepeat(" ", 9);
        }

        printEndl(4);

        displayPrehistoricEventsInfo();
}


void displayPrehistoricQuiz() 
{
    ifstream file("../data/prehistoric/prehistoricQuiz.txt");
    if (!file) 
    {
        cout << "Error: Could not open prehistoric.txt" << endl;
        return;
    }

    string resetColor = "\033[37m";
    string greenColor = "\033[32m";
    string purpleColor = "\033[35m";
    string redColor = "\033[31m";

    char correctAnswers[] = { 'C', 'B', 'B', 'B', 'B' };
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
                    centerText("          "+redColor+"Incorrect answer! "+resetColor);
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
        if (progres == 0)
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