#include "login.h"
#include "pch.h"
#include "account.h"
#include "user.h"
#include "admin.h"
#include <iostream>
#include <string>
using namespace std;

void displayLogin()
{
    loadAccounts();

    string username, password, role;

    printEndl(2);
    centerText("=============== LOGIN ===============");
    printEndl(2);

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (login(username, password, role))
    {
        centerText("Login successful! Logged in as " + role + ".");
        printEndl(2);

        int sessionChoice;
        centerText("Choose how you want to proceed:");
        centerText("1. Continue as User");
        centerText("2. Continue as Admin");
        printEndl(1);
        cout << "Enter your choice: ";
        cin >> sessionChoice;

        if (sessionChoice == 1)
        {
            clearScreen();
            showUserMenu(username);  
        }
        else if (sessionChoice == 2)
        {
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
        printEndl(1);
        centerText("Invalid username or password.");
        printEndl(1);
    }
}
