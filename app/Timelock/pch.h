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
#include <algorithm>
#include <string>

using namespace std;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
using std::chrono::seconds;

#pragma once

// Structs
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

struct SEARCH 
{
    string fileName;
    string content;
    SEARCH* next;
};

struct FAVOURITE {
    string username;
    string era;
    string title;
    string content;
    FAVOURITE* next;
};

// Extern variable
extern int progres;

// Generally used functions
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

