#include "user.h"
#include "movies.h"
#include "bookMovie.h"
#include "utils.h"

// Shows the user menu
void showUserMenu(const string& username) {

    string purpleColor = "\033[35m"; // Purple text color 
    string whiteColor = "\033[37m"; // White text color 
    string redColor = "\033[31m"; // Red text color  
    string resetColor = "\033[0m"; // Reset color to default


    int choice;

    // Keep showing the menu until the user chooses to log out
    do {
        printEndl(1);
        centerText(purpleColor + "===========================================" + resetColor);
        centerText(purpleColor + "             USER MENU                     " + resetColor);
        centerText(purpleColor + "===========================================" + resetColor);
        printEndl(1);

        // Display user menu options
        centerText(whiteColor + "1. View movies" + resetColor);
        centerText(whiteColor + "2. Book a movie" + resetColor);
        centerText(whiteColor + "3. Logout" + resetColor);
        printEndl(1);

        printStrRepeat(" ", 2);
        cout << whiteColor << "Choice: " << resetColor;
        cin >> choice;

        // Handle menu choice
        switch (choice) {
        case 1:
             viewMovies();  // Show the list of available movies
            break;
        case 2:
            bookMovie(username); // Book movie function
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

    } while (true); // Repeat until the user chooses to log out
}
