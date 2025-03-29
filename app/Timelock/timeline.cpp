#include "timeline.h"
#include "title.h"

void displayTimeline()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    for (int i = 0; i < 4; i++)
    {
        cout << endl;
    }

    for (int i = 0; i < 11; i++)
    {
        cout << purpleColor << title[i] << resetColor << endl;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << endl;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << " ";
    }

    cout << "<<";
    for (int i = 1; i < 29; i++)
    {
        if (i % 5 == 0)
        {
            cout << "|";
        }
        else
        {
            cout << "-----";
        }        
    }
    cout << "->>" << endl;

    string eras[5] = {
        "1. Prehistoric era",
        "2. Classical era",
        "3. The Middle Age era",
        "4. Early Modern era",
        "5. Modern era"
    };


    for (int i = 0; i < 5; i++)
    {
        cout << "  ";
    } 
    for (int i = 0; i < 5; i++)
    {
        cout << eras[i] << "      ";
        
    }

    cout << endl << endl << endl << "Choose an era to explore: ";
    int era;
    cin >> era;

    if (era == 1)
    {
        cout << endl << "Start exploring " << purpleColor <<  "Prehistoric " << resetColor << "era events!";
    }
    else if (era == 2)
    {
        cout << endl << "Start exploring " << purpleColor << "Classical " << resetColor << "era events!";
    }
    else if (era == 3)
    {
        cout << endl << "Start exploring " << purpleColor << "The Middle Age " << resetColor << "era events!";
    }
    else if (era == 4)
    {
        cout << endl << "Start exploring " << purpleColor << "Early Modern " << resetColor << "era events!";
    }
    else if (era == 5)
    {
        cout << endl << "Start exploring " << purpleColor << "Modern " << resetColor << "era events!";
    }

}