#include "pch.h"
#include "startingScreen.h"

int main()
{
    HWND console = GetConsoleWindow();
    RECT r;

    GetWindowRect(console, &r); 
    MoveWindow(console, r.left, r.top, 1100, 550, TRUE); 

    displayStartingScreen();
    void chooseAnswer();
}

