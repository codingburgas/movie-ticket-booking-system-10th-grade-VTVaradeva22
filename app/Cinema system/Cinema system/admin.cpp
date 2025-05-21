#include "admin.h"
#include <iostream>
using namespace std;

void showAdminMenu(const string& username) {
    int choice;
    do {
        cout << "\n=== ADMIN MENU ===\n";
        cout << "1. Add movie\n";
        cout << "2. Remove movie\n";
        cout << "3. View movies\n";
        cout << "4. Book a movie\n";
        cout << "5. Logout\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
           // addMovie();
            break;
        case 2:
            //removeMovie();
            break;
        case 3:
            //viewMovies();
            break;
        case 4:
           // bookMovie(username); 
            break;
        case 5:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);
}
