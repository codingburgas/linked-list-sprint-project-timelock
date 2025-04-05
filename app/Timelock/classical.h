#include "pch.h"

#pragma once

struct CLASSICAL
{
    string data;
    CLASSICAL* next;
};

void displayClassical();
void displayClassicalInfo(CLASSICAL* head);
CLASSICAL* loadClassicalInfo();
void displayClassicalQuiz();
void displayClassicalEvents();
