#include "pch.h"

int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int width;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    return width;
}

void centerText(string text) { // The centerText() function does not adapt in real time and needs contextual adjustments
    int consoleWidth = getConsoleWidth();
    int paddingLeft = (consoleWidth - text.length()) / 2;
    if (paddingLeft < 0) paddingLeft = 0;

    cout << string(paddingLeft, ' ') << text;
}