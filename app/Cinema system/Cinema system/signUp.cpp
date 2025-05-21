#include "signUp.h"
#include "pch.h"
#include "user.h"
#include "admin.h"
#include "account.h"
#include <iostream>
#include <string>
using namespace std;
void displaySignUp()
{
    loadAccounts();

    string username, password, confirmPassword, role;

    printEndl(2);
    centerText("============== SIGN UP ==============");
    printEndl(2);

    bool validUsername = false;
    while (!validUsername)
    {
        cout << "Enter username: ";
        cin >> username;
        if (doesAccountExist(username))
        {
            centerText("Username already exists! Try another.");
        }
        else validUsername = true;
    }

    bool passwordsMatch = false;
    while (!passwordsMatch)
    {
        cout << "Enter password: ";
        cin >> password;
        cout << "Confirm password: ";
        cin >> confirmPassword;

        if (password != confirmPassword)
            centerText("Passwords don't match! Try again.");
        else passwordsMatch = true;
    }

    bool validRole = false;
    while (!validRole)
    {
        cout << "Choose role (admin/user): ";
        cin >> role;
        for (auto& c : role) c = tolower(c);
        if (role == "admin" || role == "user")
            validRole = true;
        else
            centerText("Invalid role! Choose 'admin' or 'user'.");
    }

    if (registerAccount(username, password, role))
    {
        centerText("Sign-up successful! You are logged in as " + role + ".");
        printEndl(1);
        if (role == "admin")
            showAdminMenu(username);
        else
            showUserMenu(username);
    }
    else
        centerText("Error during registration.");
}