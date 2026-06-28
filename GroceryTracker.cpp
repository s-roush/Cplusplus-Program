#include "GroceryTracker.h"
#include <fstream>

using namespace std;

// Constructor
GroceryTracker::GroceryTracker() {
	inputFileName = "CS210_Project_Three_Input_File.txt";
	backupFileName = "frequency.dat";
}

// Reads grocery items from file and counts their frequency
void GroceryTracker::LoadData() {
	ifstream inFS;
	string item;

	inFS.open(inputFileName);

	if (!inFS.is_open()) {
		cout << "Error opening file." << endl;
		return;
	}

	while (inFS >> item) {
		itemFrequency[item]++;
	}
	
	inFS.close();
}

// Creates backup file
void GroceryTracker::CreateBackupFile() {
	ofstream outFS;

	outFS.open(backupFileName);

	for (auto const& pair : itemFrequency) {
		outFS << pair.first << " " << pair.second << endl;
	}

	outFS.close();
}

//Return frequency for specific item
int GroceryTracker::GetItemFrequency(string item) {
	if (itemFrequency.find(item) != itemFrequency.end()) {
		return itemFrequency[item];
	}

	return 0;
}

// Prints all item frequencies
void GroceryTracker::PrintAllFrequencies() {
	for (auto const& pair : itemFrequency) {
		cout << pair.first << " " << pair.second << endl;
	}
}

//Print histogram
void GroceryTracker::PrintHistogram() {
	for (auto const& pair : itemFrequency) {
		cout << pair.first << " ";

		for (int i = 0; i < pair.second; i++) {
			cout << "*";
		}

		cout << endl;
	}
}

