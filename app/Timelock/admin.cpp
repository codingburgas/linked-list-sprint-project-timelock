#include "admin.h"
#include "timeline.h"

int choose() {

    cout << "Admin Panel:" << endl;
    cout << "1. View Eras" << endl;
    cout << "2. Add Era" << endl;
    cout << "3. Edit Era" << endl;
    cout << "4. Delete Era" << endl;
    cout << "5. Logout" << endl;
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        displayEras();
        break;
    case 2: {
        int id;
        string name;
        cout << "Enter Era ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Era Name: ";
        getline(cin, name);
        addEra(id, name);
        cout << "Returning to Admin Panel..." << endl;
        break;
    }
    case 3:
        editEra();
        break;
    case 4:
        deleteEra();
        break;
    case 5:
        cout << "Logging out..." << endl;
        break;
    default:
        cout << "Invalid choice!" << endl;
    }
    return choice;
} 


void adminPanel() {
    int choice;
    do {
        choice = choose();
    }
    while (choice != 5);
}
