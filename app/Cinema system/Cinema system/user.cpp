#include "user.h"
#include "pch.h"
#include <iostream>
using namespace std;


void showUserMenu(const string& username) {

    int choice;
    do {
        cout << "\n";
        centerText( "===========================================" );
        centerText( "             USER MENU                     " );
        centerText( "===========================================" );


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