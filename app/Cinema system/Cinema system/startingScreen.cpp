#include "startingScreen.h"
#include "utils.h"

// Shows the starting screen of the app
void displayStartingScreen()
{
    string purpleColor = "\033[35m"; // Purple text color
    string whiteColor = "\033[37m"; // White text color 
    string resetColor = "\033[0m"; // Reset color to default


    printEndl(2); // Adds 2 blank lines for spacing

    // Display the centered header text
    centerText(purpleColor + "===========================================" + resetColor);
    centerText(purpleColor + "        MOVIE TICKET BOOKING SYSTEM         " + resetColor);
    centerText(purpleColor + "===========================================" + resetColor);

    printEndl(2);
    centerText(whiteColor + "Select a choice:" + resetColor);
    printEndl(1);

    // Show the available options
    centerText(whiteColor + "1. SIGN UP" + resetColor);
    centerText(whiteColor + "2. LOGIN" + resetColor);

    chooseAnswer();
    printEndl(2);
}

// Sign Up or Login
void chooseAnswer()
{
    string redColor = "\033[31m";     
    string resetColor = "\033[0m";    

    int choice;
    bool isValid = false;  // Keeps looping until valid input

    while (!isValid)
    {
        printEndl(1);
        printStrRepeat(" ", 2);
        cout << "Your choice: ";
        cin >> choice;
        cout << endl;

        // If the user picks 1, show the Sign Up screen
        if (choice == 1)
        {
            isValid = true;
            clearScreen(); // Clears the console
            displaySignUp(); // Calls the Sign Up menu
        }

        // If the user picks 2, show the Login screen
        else if (choice == 2)
        {
            isValid = true;
            clearScreen(); // Clears the console
            displayLogin(); // Calls the Login menu
        }

        // If the input is invalid, show an error message
        else
        {
            cout << redColor << "Invalid choice! Choose 1 for SIGN UP or 2 for LOGIN." << resetColor << endl;
        }
    }
}
