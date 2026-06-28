#pragma once
#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <iostream>
#include <map>
#include <string>

using namespace std;

class GroceryTracker {
public:
	GroceryTracker();

	void LoadData();
	void CreateBackupFile();

	int GetItemFrequency(string item);
	void PrintAllFrequencies();
	void PrintHistogram();

private:
	map<string, int> itemFrequency;
	string inputFileName;
	string backupFileName;
};

#endif