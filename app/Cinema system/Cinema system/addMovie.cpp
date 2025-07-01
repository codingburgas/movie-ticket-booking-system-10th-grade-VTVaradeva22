#include "addMovie.h"
#include "utils.h"
#include <fstream>

// Displays the title
void displayAddMovieTitle() {

    string resetColor = "\033[0m"; // Reset color to default
    string purpleColor = "\033[35m"; // Purple text color

    printEndl(1);
    centerText(purpleColor + "========== ADD A NEW MOVIE ==========" + resetColor);
    printEndl(2);
}

// Saves movie to a CSV file
void createMovieFileEntry(const string& title, const string& year, const string& showtime, const string& price) {
    string resetColor = "\033[0m";
    string purpleColor = "\033[35m";
    string greenColor = "\033[32m";
    string redColor = "\033[31m";

    ofstream out("../Data/addMovies.csv", ios::app);
    if (out.fail()) {
        centerText(redColor + "Failed to open movies file for writing." + resetColor);
        printEndl(2);
        return;
    }

    out << title << "|" << year << "|" << showtime << "|" << price << "\n";
    out.close();

    centerText(greenColor + "Movie added successfully: " + resetColor + title);
    printEndl(2);
}

// Adds a new movie
void addMovie() {
    string resetColor = "\033[0m";
    string purpleColor = "\033[35m";
    string whiteColor = "\033[37m";

    displayAddMovieTitle();

    cin.ignore(); // Clear input buffer
    string title, year, showtime, price;

    centerText(purpleColor + " Enter movie title: " + resetColor);
    getline(cin, title);
    printEndl(1);

    centerText(purpleColor + " Enter release year: " + resetColor);
    getline(cin, year);
    printEndl(1);

    centerText(purpleColor + " Enter showtime (e.g. 18:30): " + resetColor);
    getline(cin, showtime);
    printEndl(1);

    centerText(purpleColor + " Enter ticket price (BGN): " + resetColor);
    getline(cin, price);
    printEndl(2);

    createMovieFileEntry(title, year, showtime, price);

    // Waits for user to press a key
    system("pause");
}
