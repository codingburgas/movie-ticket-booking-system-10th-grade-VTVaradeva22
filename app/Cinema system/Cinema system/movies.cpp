#include "movies.h"
#include "pch.h"
#include <iostream>
using namespace std;

void viewMovies() {
    string movies[10] = {
    "1. Dune: Part Two (2024)",
    "2. Oppenheimer (2023)",
    "3. Barbie (2023)",
    "4. The Batman (2022)",
    "5. Spider-Man: No Way Home (2021)",
    "6. Top Gun: Maverick (2022)",
    "7. Avatar: The Way of Water (2022)",
    "8. John Wick: Chapter 4 (2023)",
    "9. Mission: Impossible – Dead Reckoning (2023)",
    "10. Wonka (2023)"
    };

    string purpleColor = "\033[35m";
    string whiteColor = "\033[37m";
    string resetColor = "\033[0m";

    printEndl(1);
    centerText(purpleColor + "========== AVAILABLE MOVIES ==========" + resetColor);
    printEndl(1);

    for (const auto& movie : movies) {
        centerText(whiteColor + movie + resetColor);
    }

    printEndl(2);
    system("pause");
}
