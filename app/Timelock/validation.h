#include "pch.h"
#include "accessData.h"

#pragma once

bool doesAccountExist(const string& username);
bool isPasswordCorrect(const string& username, const string& password);
string getCurrentUserRole();