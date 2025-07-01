#include "utils.h"

#pragma once

// Accounts' struct with data
struct Account {
    string username;
    string password;
    string role; 
    Account* next;
};

// Accounts' data functions
void loadAccounts();
bool doesAccountExist(const string& username);
bool registerAccount(const string& username, const string& password, const string& role);
bool login(const string& username, const string& password, string& roleOut);
