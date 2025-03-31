#include "pch.h"
#include "startingScreen.h"

int main()
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions

    MoveWindow(console, r.left, r.top, 1100, 550, TRUE); // 800 width, 100 height
    displayStartingScreen();
    void chooseAnswer();
}

