# include "pch.h"

#pragma once

// Detect dates and time functions
int extractYear(const string& text);
int findExtremeYear(const string& folderPath, bool findMin);
bool isEarliestYear(int year, const string& folderPath);
bool isLatestYear(int year, const string& folderPath);

