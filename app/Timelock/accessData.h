#include "pch.h"

#pragma once

struct ACCOUNT {
    string username;
    string password;
    string role;
    int progress;
    ACCOUNT* next;
};


extern ACCOUNT* head;
extern char currentUser[25];

void saveAccount(const string& username, const string& password, const string& role,int progress);
void loadAccounts();
void loadUserProgress();
void saveUserProgress();

