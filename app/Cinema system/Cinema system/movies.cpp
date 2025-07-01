#include "movies.h"
#include "utils.h"
#include <fstream>
#include <sstream>

// Function to display the list of available movies
void viewMovies() {
    string purpleColor = "\033[35m"; // Purple text color
    string whiteColor = "\033[37m"; // White text color
    string resetColor = "\033[0m"; // Reset color to default


    printEndl(1);
    centerText(purpleColor + "========== AVAILABLE MOVIES ==========" + resetColor);
    printEndl(1);

    // Open the movies CSV file
    ifstream file("../Data/addMovies.csv");
    string line;
    int count = 1;

    if (!file.is_open()) {
        centerText("\033[31mFailed to open movies file.\033[0m");
        printEndl(2);
        return;
    }


    // Read each line from the file
    while (getline(file, line)) {
        stringstream ss(line);
        string title, year, showtime, price;

        getline(ss, title, '|');
        getline(ss, year, '|');
        getline(ss, showtime, '|');
        getline(ss, price, '|');

        // Prepare formatted movie string with number
        string display = to_string(count) + ". " + title + " (" + year + ") - " + showtime + " - " + price + " BGN";
        centerText(whiteColor + display + resetColor);
        count++;
    }

    // If no movies were found, notify the user
    if (count == 1) {
        centerText(whiteColor + "No movies available." + resetColor);
    }

    printEndl(2);
    file.close();
    system("pause");
}
