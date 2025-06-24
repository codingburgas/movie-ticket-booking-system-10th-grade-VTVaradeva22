#include "bookMovie.h"
#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void bookMovie(const string& username) {
    string purpleColor = "\033[35m";
    string whiteColor = "\033[37m";
    string resetColor = "\033[0m";

    vector<string> movies;

    ifstream file("../Data/addMovies.csv");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string title, year, showtime, price;

        getline(ss, title, '|');
        getline(ss, year, '|');
        getline(ss, showtime, '|');
        getline(ss, price, '|');

        movies.push_back(title + " (" + year + ") - " + showtime + " - " + price + " BGN");
    }
    file.close();

    if (movies.empty()) {
        printEndl(1);
        centerText("\033[31mNo movies available for booking.\033[0m");
        printEndl(2);
        return;
    }

    printEndl(1);
    centerText(purpleColor + "========== BOOK A MOVIE ==========" + resetColor);
    printEndl(1);

    for (size_t i = 0; i < movies.size(); ++i) {
        centerText(whiteColor + to_string(i + 1) + ". " + movies[i] + resetColor);
    }

    printEndl(1);
    int choice;
    cout << whiteColor << "Enter the number of the movie you want to book: " << resetColor;
    cin >> choice;

    if (choice < 1 || choice >(int)movies.size()) {
        printEndl(1);
        cout << purpleColor << "Invalid movie selection." << resetColor;
        printEndl(2);
        return;
    }

    string selectedMovie = movies[choice - 1];

    int method;
    printEndl(1);
    cout << whiteColor << "Booking type:" << resetColor << endl;
    cout << whiteColor << "1. Online" << resetColor << endl;
    cout << whiteColor << "2. Walk-in" << resetColor << endl;
    cout << whiteColor << "Choose: " << resetColor;
    cin >> method;

    string bookingType;
    string paymentMethod;

    if (method == 1) {
        bookingType = "Online";
        paymentMethod = "Credit Card";
    }
    else if (method == 2) {
        bookingType = "Walk-in";
        int payChoice;
        printEndl(1);
        cout << whiteColor << "Payment method:" << resetColor << endl;
        cout << whiteColor << "1. Cash" << resetColor << endl;
        cout << whiteColor << "2. Credit Card" << resetColor << endl;
        cout << whiteColor << "Choose: " << resetColor;
        cin >> payChoice;

        if (payChoice == 1)
            paymentMethod = "Cash";
        else if (payChoice == 2)
            paymentMethod = "Credit Card";
        else {
            printEndl(1);
            cout << purpleColor << "Invalid payment option." << resetColor;
            printEndl(2);
            return;
        }
    }
    else {
        printEndl(1);
        cout << purpleColor << "Invalid booking type." << resetColor;
        printEndl(2);
        return;
    }

    ofstream out("../Data/bookMovies.csv", ios::app);
    if (out.is_open()) {
        out << username << "," << selectedMovie << "," << bookingType << "," << paymentMethod << "\n";
        out.close();
        printEndl(1);
        cout << purpleColor << "Booking successful!" << resetColor;
    }
    else {
        printEndl(1);
        cout << purpleColor << "Failed to save booking." << resetColor;
    }

    printEndl(2);
    system("pause");
}
