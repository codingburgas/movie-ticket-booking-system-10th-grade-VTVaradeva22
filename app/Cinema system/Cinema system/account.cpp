#include "account.h"

#include <fstream>
#include <sstream>
#include <vector>

Account* head = nullptr;

void loadAccounts() {
    ifstream file("../Data/accounts.csv");
    string line, username, password, role;

    head = nullptr;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, role, ',');

        Account* newAcc = new Account{ username, password, role, head };
        head = newAcc;
    }
    file.close();
}

bool doesAccountExist(const string& username)
{
    return false;
}

bool login(const string& username, const string& password, string& roleOut) {
    Account* temp = head;
    while (temp) {
        if (temp->username == username && temp->password == password) {
            roleOut = temp->role;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool registerAccount(const string& username, const string& password, const string& role) {
    
    Account* temp = head;
    while (temp) {
        if (temp->username == username) return false;
        temp = temp->next;
    }

    
    ofstream file("../Data/accounts.csv", ios::app);
    file << username << "," << password << "," << role << endl;
    file.close();

    Account* newAcc = new Account{ username, password, role, head };
    head = newAcc;

    return true;
}