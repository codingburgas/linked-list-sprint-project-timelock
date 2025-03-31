#include "pch.h"

#pragma once

struct ERANODE {
    int id;
    string name;
    ERANODE* next;
};

void addEra(int id, string name);
void editEra();
void deleteEra();
void displayTimeline();
void displayEras();