#include "movies.h"
#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void viewMovies() {
    string purpleColor = "\033[35m";
    string whiteColor = "\033[37m";
    string resetColor = "\033[0m";

    printEndl(1);
    centerText(purpleColor + "========== AVAILABLE MOVIES ==========" + resetColor);
    printEndl(1);

    ifstream file("../Data/addMovies.csv");
    string line;
    int count = 1;

    if (!file.is_open()) {
        centerText("\033[31mFailed to open movies file.\033[0m");
        printEndl(2);
        return;
    }

    while (getline(file, line)) {
        stringstream ss(line);
        string title, year, showtime, price;

        getline(ss, title, '|');
        getline(ss, year, '|');
        getline(ss, showtime, '|');
        getline(ss, price, '|');

        string display = to_string(count) + ". " + title + " (" + year + ") - " + showtime + " - " + price + " BGN";
        centerText(whiteColor + display + resetColor);
        count++;
    }

    if (count == 1) {
        centerText(whiteColor + "No movies available." + resetColor);
    }

    printEndl(2);
    file.close();
    system("pause");
}
