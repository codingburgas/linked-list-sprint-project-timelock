#include "dateUtils.h"
#include "pch.h"
using namespace std;

int extractYear(const string& text) 
{
    for (size_t i = 0; i < text.length(); i++) 
    {
        if (isdigit(text[i]))
        {
            string numStr;
            while (i < text.length() && isdigit(text[i]))
            {
                numStr += text[i];
                i++;
            }
            return stoi(numStr);
        }
    }
    return -1;
}

int findExtremeYear(const string& folderPath, bool findMin)
{
    DIR* dir = opendir(folderPath.c_str());
    if (dir == nullptr) 
    {
        return -1;
    }

    dirent* entry;
    int extremeYear = findMin ? 9999 : 0;
    bool found = false;

    while ((entry = readdir(dir)) != nullptr) 
    {
        string fileName = entry->d_name;

        if (fileName == "." || fileName == "..")
        {
            continue;
        }

        if (fileName.find(".txt") == string::npos)
        {
            continue;
        }

        if (fileName.find("quiz") != string::npos || fileName.find("Quiz") != string::npos)
        {
            continue;
        }

        ifstream file(folderPath + "/" + fileName);
        if (!file.is_open()) 
        {
            continue;
        }

        string line, content;
        while (getline(file, line))
        {
            content += line + "\n";
        }
        file.close();

        int year = extractYear(content);
        if (year != -1)
        {
            found = true;
            if (findMin) {
                if (year < extremeYear)
                {
                    extremeYear = year;
                }
            }
            else
            {
                if (year > extremeYear)
                {
                    extremeYear = year;
                }
            }
        }
    }

    closedir(dir);
    if (found) 
    {
        return extremeYear;
    }
    else 
    {
        return -1;
    }
}

bool isEarliestYear(int year, const string& folderPath)
{
    int minYear = findExtremeYear(folderPath, true);
    if (minYear == -1 || year < minYear)
    {
        return true;
    }
    return false;
}

bool isLatestYear(int year, const string& folderPath)
{
    int maxYear = findExtremeYear(folderPath, false);
    if (maxYear == -1 || year > maxYear)
    {
        return true;
    }
    return false;
}

