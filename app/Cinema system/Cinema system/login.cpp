#include "login.h"
#include "utils.h"
#include "account.h"
#include "user.h"
#include "admin.h"
 
// Function to display the login screen
void displayLogin()
{

    string purpleColor = "\033[35m"; // Purple text color
    string redColor = "\033[31m"; // Red text color
    string whiteColor = "\033[37m"; // White text color
    string resetColor = "\033[0m"; // Reset color to default


    // Load accounts from file into memory
    loadAccounts();

    string username, password, role;

    printEndl(2);
    centerText(purpleColor + "=============== LOGIN ===============" + resetColor);
    printEndl(2);

    // Ask user for username and password
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Check if login is valid
    if (login(username, password, role))
    {
        centerText("Login successful! Logged in as " + role + ".");
        printEndl(2);

        // Ask user how to continue after login
        int sessionChoice;
        centerText("Choose how you want to proceed:");
        centerText("1. Continue as User");
        centerText("2. Continue as Admin");
        printEndl(1);
        cout << "Enter your choice: ";
        cin >> sessionChoice;   

        // If user chooses to continue as a regular user
        if (sessionChoice == 1)
        {
            clearScreen();
            showUserMenu(username);  
        }
        // If user chooses to continue as admin
        else if (sessionChoice == 2)
        {
            // Check if the user has admin rights
            if (role == "admin")
            {
                clearScreen();
                showAdminMenu(username);  
            }
            else
            {
                printEndl(1);
                centerText("You do not have admin rights.");
                printEndl(1);
            }
        }
        else
        {
            printEndl(1);
            centerText("Invalid session choice.");
            printEndl(1);
        }
    }
    else
    {
        // Login failed
        printEndl(1);
        centerText("Invalid username or password.");
        printEndl(1);
    }
}
