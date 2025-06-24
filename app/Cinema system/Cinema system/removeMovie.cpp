#include "pch.h"
#include "removeMovie.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void removeMovie() {
    string purpleColor = "\033[35m";
    string whiteColor = "\033[37m";
    string redColor = "\033[31m";
    string greenColor = "\033[32m";
    string resetColor = "\033[0m";

    ifstream inFile("../Data/addMovies.csv");
    vector<string> movies;
    string line;

    while (getline(inFile, line)) {
        movies.push_back(line);
    }
    inFile.close();

    if (movies.empty()) {
        printEndl(1);
        centerText(redColor + "No movies available to remove." + resetColor);
        printEndl(2);
        system("pause");
        return;
    }

    printEndl(1);
    centerText(purpleColor + "========== REMOVE A MOVIE ==========" + resetColor);
    printEndl(1);

    for (size_t i = 0; i < movies.size(); ++i) {
        stringstream ss(movies[i]);
        string title, year, showtime, price;

        getline(ss, title, '|');
        getline(ss, year, '|');
        getline(ss, showtime, '|');
        getline(ss, price, '|');

        string display = to_string(i + 1) + ". " + title + " (" + year + ") - " + showtime + " - " + price + " BGN";
        centerText(whiteColor + display + resetColor);
    }

    printEndl(1);
    int choice;
    cout << whiteColor << "Enter the number of the movie to remove: " << resetColor;
    cin >> choice;

    if (choice < 1 || choice >(int)movies.size()) {
        printEndl(1);
        centerText(redColor + "Invalid selection." + resetColor);
        printEndl(2);
        system("pause");
        return;
    }

    string removedMovie = movies[choice - 1];
    movies.erase(movies.begin() + choice - 1);

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