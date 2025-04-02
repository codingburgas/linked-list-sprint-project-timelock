#include "pch.h"
#include "startingScreen.h"

int main()
{
    HWND console = GetConsoleWindow();
    RECT r;

    GetWindowRect(console, &r); 
    MoveWindow(console, r.left, r.top, 1110, 555, TRUE); 

    displayStartingScreen();
    void chooseAnswer();
}

