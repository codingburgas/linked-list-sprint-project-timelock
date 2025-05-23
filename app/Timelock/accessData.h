#include "pch.h"

#pragma once

// Accounts' struct with data
struct ACCOUNT 
{
    string username;
    string password;
    string role;
    int progress;
    ACCOUNT* next;
};


// Extern functions
extern ACCOUNT* head;
extern char currentUser[25];

// Accounts' data functions
void saveAccount(const string& username, const string& password, const string& role,int progress);
void loadAccounts();
void loadUserProgress();
void saveUserProgress();
void approveAdmin();

