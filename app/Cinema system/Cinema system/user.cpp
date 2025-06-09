#include "user.h"
#include "movies.h"
#include "bookMovie.h"
#include "pch.h"
#include <iostream>
using namespace std;

void showUserMenu(const string& username) {
    string purpleColor = "\033[35m"; 
    string whiteColor = "\033[37m";  
    string redColor = "\033[31m";    
    string resetColor = "\033[0m";   

    int choice;
    do {
        printEndl(1);
        centerText(purpleColor + "===========================================" + resetColor);
        centerText(purpleColor + "             USER MENU                     " + resetColor);
        centerText(purpleColor + "===========================================" + resetColor);
        printEndl(1);

        centerText(whiteColor + "1. View movies" + resetColor);
        centerText(whiteColor + "2. Book a movie" + resetColor);
        centerText(whiteColor + "3. Logout" + resetColor);
        printEndl(1);

        printStrRepeat(" ", 2);
        cout << whiteColor << "Choice: " << resetColor;
        cin >> choice;

        switch (choice) {
        case 1:
             viewMovies();
            break;
        case 2:
            bookMovie(username);
            break;
        case 3:
            cout << whiteColor << "Logging out and returning to the main screen..." << resetColor << endl;
            system("pause");
            return;
        default:
            cout << redColor << "Invalid choice! Enter a number between 1 and 3." << resetColor << endl;
            system("pause");
            break;
        }

    } while (true);
}
