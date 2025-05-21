#pragma once

#include <string>
using namespace std;

struct Account {
    string username;
    string password;
    string role; 
    Account* next;
};


void loadAccounts();
bool doesAccountExist(const string& username);
bool registerAccount(const string& username, const string& password, const string& role);
bool login(const string& username, const string& password, string& roleOut);
//void saveAccounts();