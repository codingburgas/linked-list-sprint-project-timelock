#include "pch.h"
#include "accessData.h"

#pragma once

// Validation functions
bool doesAccountExist(const string& username);
bool isPasswordCorrect(const string& username, const string& password);
string getCurrentUserRole();