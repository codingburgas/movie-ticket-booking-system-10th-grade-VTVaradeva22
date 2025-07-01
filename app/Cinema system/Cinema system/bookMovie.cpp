#include "bookMovie.h"
#include "utils.h"
#include <fstream>
#include <sstream>
#include <vector>

// Function to book a movie
void bookMovie(const string& username) {
    string purpleColor = "\033[35m"; // Purple text color
    string whiteColor = "\033[37m"; // White text color
    string resetColor = "\033[0m"; // Reset color to default


    vector<string> movies;

    // Read movies from file
    ifstream file("../Data/addMovies.csv");
    string line;

    // Parse each movie line and add to vector
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

    // If no movies available, show message and exit
    if (movies.empty()) {
        printEndl(1);
        centerText("\033[31mNo movies available for booking.\033[0m");
        printEndl(2);
        return;
    }

    // Display booking header
    printEndl(1);
    centerText(purpleColor + "========== BOOK A MOVIE ==========" + resetColor);
    printEndl(1);

    // Show list of movies with numbers
    for (size_t i = 0; i < movies.size(); i++) {
        centerText(whiteColor + to_string(i + 1) + ". " + movies[i] + resetColor);
    }

    printEndl(1);

    // Ask user to select a movie by number
    int choice;
    cout << whiteColor << "Enter the number of the movie you want to book: " << resetColor;
    cin >> choice;

    // Validate the movie choice
    if (choice < 1 || choice >(int)movies.size()) {
        printEndl(1);
        cout << purpleColor << "Invalid movie selection." << resetColor;
        printEndl(2);
        return;
    }

    string selectedMovie = movies[choice - 1];

    // Ask user for booking type
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

        // Ask for payment method if walk-in
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

    // Save booking info to CSV file
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
    out.close();
    system("pause");
}
