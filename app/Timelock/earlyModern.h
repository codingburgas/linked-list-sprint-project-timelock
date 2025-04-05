#include "pch.h"

#pragma once

struct EARLYMODERN
{
    string data;
    EARLYMODERN* next;
};

void displayEarlyModern();
void displayEarlyModernInfo(EARLYMODERN* head);
EARLYMODERN* loadEarlyModernInfo();
void displayearlyModernQuiz();
void displayearlyModernEvents();

