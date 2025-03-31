#include "pch.h"

#pragma once

#include <string>
using namespace std;

struct EraNode {
    int id;
    string name;
    EraNode* next;
};

void addEra(int id, string name);
void editEra();
void deleteEra();
void displayTimeline(bool isAdmin = false);
