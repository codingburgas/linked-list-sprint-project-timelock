#include "favourites.h"
#include "accessData.h"
#include "events.h"

void saveFavourite(const string& era, const string& title, INFONODE* list) {
    string redColor = "\033[31m";
    string greenColor = "\033[32m";
    string resetColor = "\033[37m";

    ofstream file("../data/favourites.csv", ios::app);
    if (file.is_open()) {
        INFONODE* current = list;
        int lineNumber = 0;
        while (current != nullptr) {
            string content = current->data;
            string escapedContent;
            for (char c : content) {
                if (c == '"') {
                    escapedContent += "\"\"";
                }
                else if (c == ',') {
                    escapedContent += "\\,";
                }
                else {
                    escapedContent += c;
                }
            }
            file << "\"" << currentUser << "\",\"" << era << "\",\"" << title << "\",\"" << escapedContent << "\"," << lineNumber << "\n";
            current = current->next;
            lineNumber++;
        }
        file.close();

        printEndl(2);
        centerText(greenColor + "           Article saved to favourites!" + resetColor);
        printEndl(3);
    }
    else 
    {
        printEndl(2);
        centerText(redColor + "         Unable to save favourite." + resetColor);
        cout << endl;
    }
}

void askToAddToFavourites(const string& era, INFONODE* node) {
    string purpleColor = "\033[35m";
    string resetColor = "\033[37m";

    string input;
    centerText(purpleColor + "     Did you enjoy this article? Add it to favourites? (Y/N): " + resetColor);
    cin >> input;

    if ((input == "Y" || input == "y") && node != nullptr) {
        string title = node->data;
        if (title.length() > 100) {
            title = title.substr(0, 100);
        }
        saveFavourite(era, title, node);
    }
    printEndl(2);

}

void displayFavouritesByEra(const string& era) {
    string purpleColor = "\033[35m";
    string resetColor = "\033[37m";
    string redColor = "\033[31m";

    ifstream file("../data/favourites.csv");
    if (!file.is_open()) {
        centerText(redColor + "     No favourites found." + resetColor);
        return;
    }

    string line, username, favEra, title, content, lineNumberStr;
    bool found = false;
    INFONODE* head = nullptr;
    INFONODE* tail = nullptr;
    string lastTitle = "";

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, username, ',');
        getline(ss, favEra, ',');
        getline(ss, title, ',');
        getline(ss, content, ',');
        getline(ss, lineNumberStr);

        // Remove quotes
        if (!username.empty() && username.front() == '"' && username.back() == '"') {
            username = username.substr(1, username.length() - 2);
        }
        if (!favEra.empty() && favEra.front() == '"' && favEra.back() == '"') {
            favEra = favEra.substr(1, favEra.length() - 2);
        }
        if (!title.empty() && title.front() == '"' && title.back() == '"') {
            title = title.substr(1, title.length() - 2);
        }
        if (!content.empty() && content.front() == '"' && content.back() == '"') {
            content = content.substr(1, content.length() - 2);
        }

        // Unescape
        string unescapedContent;
        for (size_t i = 0; i < content.length(); ++i) {
            if (content[i] == '\\' && i + 1 < content.length() && content[i + 1] == ',') {
                unescapedContent += ",";
                i++;
            }
            else if (content[i] == '"' && i + 1 < content.length() && content[i + 1] == '"') {
                unescapedContent += "\"";
                i++;
            }
            else {
                unescapedContent += content[i];
            }
        }

        if (username == currentUser && favEra == era) {
            found = true;
            INFONODE* newNode = new INFONODE;
            newNode->data = unescapedContent;
            newNode->next = nullptr;

            if (!head) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }

            if (lastTitle != title && !lastTitle.empty()) {
                centerText(purpleColor + "     =======================================");
                cout << endl;
                centerText("              Favourite from: " + resetColor + favEra + purpleColor + "       Title: " + resetColor + lastTitle);
                cout << endl;
                centerText(purpleColor + "      =======================================" + resetColor);
                displayInfo(head);
                deleteInfoList(head);
                head = newNode;
                tail = newNode;
            }
            lastTitle = title;
        }
    }

    if (found && head) {
        centerText(purpleColor + "     =======================================");
        cout << endl;
        centerText("              Favourite from: " + resetColor + era + purpleColor + "       Title: " + resetColor + lastTitle);
        cout << endl;
        centerText(purpleColor + "      =======================================" + resetColor);
        displayInfo(head);
        deleteInfoList(head);
    }

    if (!found) {
        centerText(redColor + "                 You have no favourites yet in this era." + resetColor);
    }

    file.close();
}
