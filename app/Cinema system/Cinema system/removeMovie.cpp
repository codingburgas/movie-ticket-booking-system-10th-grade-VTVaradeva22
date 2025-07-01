#include "utils.h"
#include "removeMovie.h"
#include <fstream>
#include <sstream>
#include <vector>

void removeMovie() {
    // Set color codes for console output
    string purpleColor = "\033[35m"; // Purple text color
    string whiteColor = "\033[37m"; // White text color
    string redColor = "\033[31m"; // Red text color
    string greenColor = "\033[32m"; // Green text color
    string resetColor = "\033[0m"; // Reset color to default

    // Open the file and read all movies into a vector
    ifstream inFile("../Data/addMovies.csv");
    vector<string> movies;
    string line;

    while (getline(inFile, line)) {
        movies.push_back(line); // Add each movie line to the vector
    }
    inFile.close();

    // If there are no movies, show message and stop
    if (movies.empty()) {
        printEndl(1);
        centerText(redColor + "No movies available to remove." + resetColor);
        printEndl(2);
        system("pause");
        return;
    }

    // Show remove movie screen title
    printEndl(1);
    centerText(purpleColor + "========== REMOVE A MOVIE ==========" + resetColor);
    printEndl(1);

    // Print each movie with number, title, year, time, and price
    for (size_t i = 0; i < movies.size(); i++) {
        stringstream ss(movies[i]);
        string title, year, showtime, price;

        // Separate movie details using '|'
        getline(ss, title, '|');
        getline(ss, year, '|');
        getline(ss, showtime, '|');
        getline(ss, price, '|');

        // Create display string for the movie
        string display = to_string(i + 1) + ". " + title + " (" + year + ") - " + showtime + " - " + price + " BGN";
        centerText(whiteColor + display + resetColor);
    }

    printEndl(1);
    int choice;
    cout << whiteColor << "Enter the number of the movie to remove: " << resetColor;
    cin >> choice;

    // Check if the selected number is valid
    if (choice < 1 || choice >(int)movies.size()) {
        printEndl(1);
        centerText(redColor + "Invalid selection." + resetColor);
        printEndl(2);
        system("pause");
        return;
    }

    // Remove the selected movie from the vector
    string removedMovie = movies[choice - 1];
    movies.erase(movies.begin() + choice - 1);

    // Save the updated movie list back to the CSV file
    ofstream outFile("../Data/addMovies.csv");
    for (const string& movie : movies) {
        outFile << movie << "\n";
    }
    outFile.close();

    printEndl(1);
    centerText(greenColor + "Movie removed successfully." + resetColor);
    printEndl(2);
    system("pause");
}