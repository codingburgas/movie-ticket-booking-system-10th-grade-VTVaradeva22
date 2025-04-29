#include <iostream>
#include "mainMenu.h"
using namespace std;
class Menu
{
public:
	//Movie m;
	//Administrator a;

	void displayMenu() {
		//aboutPage();
		int enter;
		cin >> enter;
		if (enter == 1) {
			do
			{
				int check = 0;
				system("cls");
				cout << " 1. Add movie" << endl;
				cout << " 2. Display movie " << endl;
				cout << " 3.Admin settings" << endl;
				cout << " 4.Exit" << endl;
				cin >> check;
				switch (check) {
				case 1:
					system("cls");
					m.addMovie();
					break;
				case 2:
					system("cls");
					m.displayMovie();
					break;
				case 3:
					system("cls");
					a.changePass();
					break;
				case 4:
					exit(0);
					break;
				default:
					cout << "Invalid input!";
					getch();
					break;
					system("cls");
				} while (true);

			}
		else if (enter == 2) {
			exit(0);
		}
		else {
			cout << "Invalid inpyt!";
		}
		}
	}
};

void startMenu() {
	while (true) {
		int mainCheck = 0;
		int newCheck = 0;
		system("cls");
		//aboutPgae();
		cin >> newCheck;
		system("cls");
		if (newCheck == 1) {
			cout << " Welcome to..." << endl;
			cout << " 1. Administrator" << endl;
			cout << " 2. Customer" << endl;
			cin >> mainCheck;
			if (mainCheck == 1) {
				char userName[100];
				char pass[100];
				cout << "Enter username: ";
				cin >> userName;
				cout << "Enter password: ";
				cin >> pass;
				char user[100];
				char userPass[100];
				int nCheck = 0;
				int aCheck = 0;
				//ifstrean userData("admins.txt");
				{
					if (!userData) {
						cout << "Cannot open files!";
					}
					while (!(userData.eof())) {
						userData >> user >> userPass;
						if (compare(user, userName)) {

						}
					}
				}
			}
		}
	}
}