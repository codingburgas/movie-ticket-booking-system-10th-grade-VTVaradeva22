#include "startingScreen.h"
#include "pch.h"
#include <iostream>
using namespace std;

void displayStartingScreen()
{
    string purpleColor = "\033[35m"; 
    string whiteColor = "\033[37m";  
    string resetColor = "\033[0m";   

    printEndl(2);

    centerText(purpleColor + "===========================================" + resetColor);
    centerText(purpleColor + "        MOVIE TICKET BOOKING SYSTEM         " + resetColor);
    centerText(purpleColor + "===========================================" + resetColor);

    printEndl(2);
    centerText(whiteColor + "Select a choice:" + resetColor);
    printEndl(1);

    centerText(whiteColor + "1. SIGN UP" + resetColor);
    centerText(whiteColor + "2. LOGIN" + resetColor);

    chooseAnswer();
    printEndl(2);
}

void chooseAnswer()
{
    string redColor = "\033[31m";     
    string resetColor = "\033[0m";    

    int choice;
    bool isValid = false;

    while (!isValid)
    {
        printEndl(1);
        printStrRepeat(" ", 2);
        cout << "Your choice: ";
        cin >> choice;
        cout << endl;

        if (choice == 1)
        {
            isValid = true;
            clearScreen();
            displaySignUp();
        }
        else if (choice == 2)
        {
            isValid = true;
            clearScreen();
            displayLogin();
        }
        else
        {
            cout << redColor << "Invalid choice! Choose 1 for SIGN UP or 2 for LOGIN." << resetColor << endl;
        }
    }
}
