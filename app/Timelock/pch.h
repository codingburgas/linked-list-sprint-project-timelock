#include <iostream>
#include <windows.h> 
#include <fstream>
#include <sstream>
#include <cstring>
#include <chrono>   
#include <thread>
#include <limits>  
#include <conio.h> 

using namespace std;
using std::this_thread::sleep_for;
using std::chrono::seconds;

#pragma once
extern int progres;
int getConsoleWidth();
void centerText(string text);
void printEndl(int num);
void printStrRepeat(string str, int num);
void displayQuizTitle();
void displayEventsTitle();

