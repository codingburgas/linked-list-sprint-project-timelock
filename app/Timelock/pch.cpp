#include "pch.h"

int getConsoleWidth() 
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int width;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    return width;
}

void centerText(string text) 
{ 
    int consoleWidth = getConsoleWidth();
    int paddingLeft = (consoleWidth - text.length()) / 2;
    if (paddingLeft < 0) 
    {
        paddingLeft = 0;
    }
    cout << string(paddingLeft, ' ') << text;
}

void printEndl(int num) 
{
    for (int i = 0; i < num; i++) 
    {
        cout << endl;
    }
}

void printStrRepeat(string str, int num) 
{
    for (int i = 0; i < num; i++) 
    {
        cout << str;
    }
}

