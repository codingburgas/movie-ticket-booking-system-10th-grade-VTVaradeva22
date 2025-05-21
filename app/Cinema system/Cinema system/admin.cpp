#include "admin.h"
#include "pch.h"
#include <iostream>
using namespace std;



void showAdminMenu(const string& username) {
    int choice;
    do {
        cout << "\n";
        centerText( "===========================================");
        centerText( "             ADMIN MENU                    ");
        centerText( "===========================================");

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
            cout << "Logging out and returning to the main screen...\n";
            system("pause");
            return; 
        default:
            cout << "Invalid choice! Enter a number between 1 and 5.\n";
            system("pause");
            break;
        }

    } while (true);
}