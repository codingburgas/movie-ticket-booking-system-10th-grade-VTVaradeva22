#include "signUp.h"
#include "admin.h"
#include "user.h"

void displaySignUp()
{
    string resetColor = "\033[37m";   // White 
    string purpleColor = "\033[35m";  // Purple

    const string title[11] = {
    "",
    "       .*************..**********..*************..**************.               .**************..**************.",
    "       *     ______        .__.       ________       ._.    ._    *             *   .__.  .__.       _______     *",
    "       *    '  ____|       |  |      /   _____|      |   \\ |  |   *             *   |  |  |  |      |   __  \\    *",
    "       *   |  (__          |  |      |  |            |    \\|  |   *             *   |  |  |  |      |  |__|  |   *",
    "       *    '.___ `.       |  |      |  |  .__.      |  .     |   *             *   |  |  |  |      |   ____/    *",
    "       *    _____)  |      |  |      |  |__|  |      |  |\\    |   *             *   |  |__|  |      |  |         *",
    "       *   |______.'       |__|      \\________/      |__| \\.__|   *             *   \\________/      |__|         *",
    "       *.             ..          ..             ..              .*             *.              ..              .*",
    "       *************  **********  *************  **************                 **************  **************",
    ""
    };

    printEndl(2);

    for (int i = 0; i < 11; i++)
    {
        centerText(purpleColor + title[i] + resetColor);
        cout << endl;
    }

    printEndl(2);

    printStrRepeat(" ", 10);

    centerText(resetColor + "Start " + purpleColor + "SIGNING UP" + resetColor + ". Please fill the questions below." + resetColor);

    printEndl(4);

    signUp();
}
}

