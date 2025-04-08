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
    string searchPath = folderPath + "\\*.txt";
    WIN32_FIND_DATAA findFileData;
    HANDLE hFind = FindFirstFileA(searchPath.c_str(), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE)
    {
        return -1;
    }

    int extremeYear = findMin ? 9999 : 0;
    bool found = false;

    do
    {
        string fileName = findFileData.cFileName;


        string lowerFileName = fileName;
        transform(lowerFileName.begin(), lowerFileName.end(), lowerFileName.begin(), ::tolower);

        if (lowerFileName.find("quiz") != string::npos)
        {
            continue;
        }

        string filePath = folderPath + "\\" + fileName;
        ifstream file(filePath);
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
            if (findMin)
                extremeYear = min(extremeYear, year);
            else
                extremeYear = max(extremeYear, year);
        }

    } while (FindNextFileA(hFind, &findFileData) != 0);

    FindClose(hFind);
    return found ? extremeYear : -1;
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

