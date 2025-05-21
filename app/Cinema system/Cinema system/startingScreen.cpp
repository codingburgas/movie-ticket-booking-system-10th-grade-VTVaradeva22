#include "startingScreen.h"
#include "pch.h"
#include <iostream>
using namespace std;

void displayStartingScreen()
{
    printEndl(2);

    
    centerText("===========================================");
    centerText("        MOVIE TICKET BOOKING SYSTEM         ");
    centerText("===========================================");

    printEndl(2);
    centerText("Select a choice:");
    printEndl(1);

    centerText("1. SIGN UP");
    centerText("2. LOGIN");

    chooseAnswer();
    printEndl(2);
}

void chooseAnswer()
{
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
            cout << "Invalid choice! Choose 1 for SIGN UP or 2 for LOGIN." << endl;
        }
    }
};