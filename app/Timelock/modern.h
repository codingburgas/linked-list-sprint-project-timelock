#include "pch.h"

#pragma once

struct MODERN
{
    string data;
    MODERN* next;
};

void displayModern();
void displayModernInfo(MODERN* head);
MODERN* loadModernInfo();
void displayModernQuiz();
void displayModernEvents();
