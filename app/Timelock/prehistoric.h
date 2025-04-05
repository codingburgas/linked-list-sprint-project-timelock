#include "pch.h"

#pragma once

struct PREHISTORIC 
{
    string data;
    PREHISTORIC* next;
};

void displayPrehistoric();
void displayPrehistoricInfo(PREHISTORIC* head);
PREHISTORIC* loadPrehistoricInfo();
void editPrehistoricInfo(PREHISTORIC* head);
void savePrehistoricInfo(PREHISTORIC* head);
void deletePrehistoricFile();
void displayPrehistoricQuiz();
void displayPrehistoricEvents();

