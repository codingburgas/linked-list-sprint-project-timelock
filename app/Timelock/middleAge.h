#include "pch.h"

#pragma once

struct MIDDLEAGE
{
    string data;
    MIDDLEAGE* next;
};

void displayMiddleAge();
void displayMiddleAgeInfo(MIDDLEAGE* head);
MIDDLEAGE* loadMiddleAgeInfo();
