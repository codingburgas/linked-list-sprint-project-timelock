#include <iostream>
#include <windows.h> 
#include <fstream>
#include <sstream>
#include <cstring>
#include <chrono>   
#include <thread>
#include <limits>  
#include <conio.h> 
#include <vector>

using namespace std;
using std::this_thread::sleep_for;
using std::chrono::seconds;

#pragma once

struct INFONODE
{
    string data;
    INFONODE* next;
};

struct QUIZNODE 
{
    string line;
    QUIZNODE* next;
};

extern int progres;

int getConsoleWidth();

void centerText(string text);
void printEndl(int num);
void printStrRepeat(string str, int num);
void displayQuizTitle();
void displayEventsTitle();
void displaySearchTitle();

void appendNode(QUIZNODE*& head, const string& line);
void deleteList(QUIZNODE* head);

INFONODE* loadInfoFromFile(const string& filepath);
void displayInfo(INFONODE* head);
void deleteInfoList(INFONODE* head);

void editEventFile(const string& filepath);
void deleteEventFile(const string& filepath);

