#include "account.h"
#include <fstream>
#include <sstream>


Account* head = nullptr;

// Loads all accounts from file into the linked list
void loadAccounts() {
    ifstream file("../Data/accounts.csv");
    string line, username, password, role;

    head = nullptr;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, role, ',');

        // Create and add new account to the front of the list
        Account* newAcc = new Account{ username, password, role, head };
        head = newAcc;
    }
    file.close();
}

// Checks if an account with the given username exists
bool doesAccountExist(const string& username)
{
    return false;
}

// Log in with username and password
bool login(const string& username, const string& password, string& roleOut) {
    Account* temp = head;
    while (temp) {
        if (temp->username == username && temp->password == password) {
            roleOut = temp->role; // Set the user's role
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Register a new account (if username is free)
bool registerAccount(const string& username, const string& password, const string& role) {
    
    Account* temp = head;
    while (temp) {
        if (temp->username == username) return false;
        temp = temp->next;
    }

    // Save the account to the CSV file
    ofstream file("../Data/accounts.csv", ios::app);
    file << username << "," << password << "," << role << endl;
    file.close();

    Account* newAcc = new Account{ username, password, role, head };
    head = newAcc;

    return true;
}