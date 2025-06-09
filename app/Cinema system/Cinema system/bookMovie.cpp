#include "bookMovie.h"
#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

void bookMovie(const string& username) {
    string purpleColor = "\033[35m";
    string whiteColor = "\033[37m";
    string resetColor = "\033[0m";

    string movies[10] = {
        "Dune: Part Two (2024) - 18:00 - 12.00 BGN",
        "Oppenheimer (2023) - 20:00 - 11.00 BGN",
        "Barbie (2023) - 16:00 - 10.00 BGN",
        "The Batman (2022) - 21:30 - 11.50 BGN",
        "Spider-Man: No Way Home (2021) - 19:00 - 11.00 BGN",
        "Top Gun: Maverick (2022) - 17:00 - 10.50 BGN",
        "Avatar: The Way of Water (2022) - 18:30 - 12.50 BGN",
        "John Wick: Chapter 4 (2023) - 20:30 - 11.50 BGN",
        "Mission: Impossible – Dead Reckoning (2023) - 19:30 - 11.00 BGN",
        "Wonka (2023) - 15:30 - 9.50 BGN"
    };

    printEndl(1);
    centerText(purpleColor + "========== BOOK A MOVIE ==========" + resetColor);
    printEndl(1);

    for (int i = 0; i < 10; ++i) {
        centerText(whiteColor + to_string(i + 1) + ". " + movies[i] + resetColor);
    }

    printEndl(1);
    int choice;
    cout << whiteColor << "Enter the number of the movie you want to book: " << resetColor;
    cin >> choice;

    if (choice < 1 || choice > 10) {
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
