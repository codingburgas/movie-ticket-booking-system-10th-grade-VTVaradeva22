#include "pch.h"

using namespace std;


void centerText(const string& text)
{
    int width = 80;
    int padding = (width - text.length()) / 2;
    if (padding > 0)
        cout << string(padding, ' ');
    cout << text << endl;
}


void printEndl(int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << endl;
    }
}

void printStrRepeat(const string& str, int count)
{
    for (int i = 0; i < count; ++i)
    {
        cout << str;
    }
}


void clearScreen()
{

    system("cls");

}