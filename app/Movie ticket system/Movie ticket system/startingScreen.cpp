#include "startingScreen.h"
using namespace std;
void displayStartingScreen()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    const string title[11] = {

     cout << "   ____ ___ _   _ _____ __  __    _    " << endl;
     cout << "  / ___|_ _| \\ | | ____|  \\/  |  / \\   " << endl;
     cout << " | |    | ||  \\| |  _| | |\\/| | / _ \\  " << endl;
     cout << " | |___ | || |\\  | |___| |  | |/ ___ \\ " << endl;
    cout << "  \\____|___|_| \\_|_____|_|  |_/_/   \\_\\" << endl;
     cout << "                                        " << endl;
    };

    printEndl(2);

    for (int i = 0; i < 11; i++)
    {
        centerText(purpleColor + title[i] + resetColor);
        cout << endl;
    }

    printEndl(4);

    printStrRepeat(" ", 2);
    cout << "Select a choice!";

    printStrRepeat(" ", 33);
    cout << "1.SIGN UP";
    printStrRepeat(" ", 30);
    cout << "2.LOGIN" << endl;

    chooseAnswer();

    printEndl(2);
}
void chooseAnswer()
{
    string redColor = "\033[31m";     // Red
    string resetColor = "\033[37m";   // White 

    int choice;
    bool isValid = false;

    while (!isValid)
    {
        cout << endl;
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
            cout << redColor << "Invalid choice! Choose 1. to SIGN UP or 2. to LOGIN" << resetColor << endl;
        }
    }
}