#include "signUp.h"
#include "utils.h"
#include "user.h"
#include "admin.h"
#include "account.h"

// Function to display the sign up screen
void displaySignUp()
{
    // Set color codes for console output
    string purpleColor = "\033[35m"; // Purple text color
    string redColor = "\033[31m"; // Red text color
    string whiteColor = "\033[37m"; // White text color
    string resetColor = "\033[0m"; // Reset color to default


    // Load all existing accounts from file
    loadAccounts();

    string username, password, confirmPassword, role;

    printEndl(2);
    centerText(purpleColor + "============== SIGN UP ==============" + resetColor);
    printEndl(2);


    bool validUsername = false;
    while (!validUsername)
    {
        cout << "Enter username: ";
        cin >> username;


        bool passwordsMatch = false;
        while (!passwordsMatch)
        {
            // Ask user to enter and confirm password
            cout << "Enter password: ";
            cin >> password;
            cout << "Confirm password: ";
            cin >> confirmPassword;

            // Check if passwords match
            if (password != confirmPassword)
                centerText("Passwords don't match! Try again.");
            else passwordsMatch = true;
        }

        bool validRole = false;
        while (!validRole)
        {
            // Ask the user to choose a role: admin or user
            cout << "Choose role (admin/user): ";
            cin >> role;

            for (auto& c : role) c = tolower(c);// Convert input to lowercase

            // Validate role input
            if (role == "admin" || role == "user")
                validRole = true;
            else
                centerText("Invalid role! Choose 'admin' or 'user'.");
        }

        // Register the new account
        if (registerAccount(username, password, role))
        {
            centerText("Sign-up successful! You are logged in as " + role + ".");
            printEndl(1);
            if (role == "admin")
                showAdminMenu(username); // Show admin menu
            else
                showUserMenu(username); // Show user menu
        }
        else
            centerText("Error during registration.");
    }
} 