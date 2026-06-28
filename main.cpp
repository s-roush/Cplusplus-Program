#include <iostream>
#include <limits>
#include "GroceryTracker.h"

using namespace std;

void DisplayMenu() {
	cout << "\n===== Corner Grocer Menu =====" << endl;
	cout << "1. Search for item frequency" << endl;
	cout << "2. Display all frequencies" << endl;
	cout << "3. Display histogram" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter your choice: ";
}

int main() {

	GroceryTracker grocery;

	grocery.LoadData();
	//Creates backup file
	grocery.CreateBackupFile();

	int choice = 0;

	while (choice != 4) {

		DisplayMenu();
		cin >> choice;

		// input validation
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid input. Enter 1-4: ";
			cin >> choice;
		}

		switch (choice) {

		case 1: {
			string item;
			cout << "Enter item name: ";
			cin >> item;

			cout << item << " was purchased " << grocery.GetItemFrequency(item) << " time(s)." << endl;

			break;
		}
		case 2: {
			grocery.PrintAllFrequencies();
			break;
		}
		case 3: {
			grocery.PrintHistogram();
			break;
		}
		case 4: {
			cout << "Exiting program " << endl;
			break;
		}
		default: {
			cout << "Please select 1-4." << endl;
		}

		}
	}

	return 0;
}