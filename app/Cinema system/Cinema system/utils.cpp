#include "utils.h"

// Prints the given text centered in an 80-character wide console
void centerText(const string& text)
{
    int width = 80;
    int padding = (width - text.length()) / 2; // Calculate left padding
    if (padding > 0)
        cout << string(padding, ' '); // Print spaces for padding
    cout << text << endl;
}

// Prints empty lines to the console
void printEndl(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << endl;
    }
}

// Prints the given text multiple times on the same line (without going to a new line)
void printStrRepeat(const string& str, int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << str;
    }
}

// Clears the console screen
void clearScreen()
{

    system("cls");

}