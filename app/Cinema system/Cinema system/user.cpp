#include "user.h"
#include <iostream>
using namespace std;

void showUserMenu(const string& username) {
    int choice;
    do {
        cout << "\n=== USER MENU ===\n";
        cout << "1. View movies\n";
        cout << "2. Book a movie\n";
        cout << "3. Logout\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
           // viewMovies();
            break;
        case 2:
            //bookMovie(username);
            break;
        case 3:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 3);
}
