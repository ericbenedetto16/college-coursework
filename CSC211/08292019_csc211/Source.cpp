#include <iostream>
#include <Windows.h>
#include <string>
#include <array>
#include <fstream>

using namespace std;

void clearChars(int num);
void printResults();
bool checkPrevious(int baseIndex, int matchIndex, array <int,35> arr);

ifstream infile;
string inLine;

string scanText;
string compareText;
string matchText;
string trailText;

int compare;
int temp;

int main()
{
	SetConsoleTitle("Duplicate Finder - Eric Benedetto");
	system("color 02");

	ofstream outfile;
	outfile.open("repeated.txt");

	// 19, 19, 18, 18, 17, 16, 11, 20
	array <int,35> arr = { 1,2,3,4,5,6,7,8,9,0,10,19,18,17,16,18,13,12,11,11,22,23,24,19,26,27,28,29,20,20,19,18,17,16,16 };

	for (int baseIndex = 0; baseIndex < arr.size(); baseIndex++) {
		compare = arr[baseIndex];
		bool outSideMatch = true;
		scanText = "Scanning index " + to_string(baseIndex) + " ";
		cout << scanText;

		for (int matchIndex = baseIndex + 1; matchIndex < arr.size() ; matchIndex++) {
			compareText = "Comparing against index " + to_string(matchIndex);
			cout << compareText;
			Sleep(50);

			temp = arr[matchIndex];
			if (compare == temp) {
				matchText = "\nMatch Found (" + to_string(compare) + " " + to_string(temp) + ") at Index " + to_string(baseIndex) + " and " + to_string(matchIndex) + "\n";
				cout << matchText;

				bool unique = checkPrevious(baseIndex, matchIndex, arr);
				outSideMatch = false;

				if (unique) {
					(outfile.is_open()) ? outfile << arr[baseIndex] << '\n' : cerr << "Error: " << errno;
				}

				(unique) ? cout << "Match is Unique! Outputting to File\n\n" : cout <<"\nMatch Is Not Unique!\n\n";
			}
			else {
				clearChars(compareText.size());
			}
		}
		if (outSideMatch) {
			clearChars(scanText.size());
		}
	}

	outfile.close();

	printResults();

	cout << "Compiling and Outputting Final Results to repeated.txt...\n";

	system("notepad repeated.txt");

	system("pause");
	return 0;
}

bool checkPrevious(int baseIndex, int matchIndex, array <int, 35> arr) {
	for (int trailIndex = 0; trailIndex < matchIndex; trailIndex++) {
		trailText = "Checking if Number Has Already Been Matched at Index " + to_string(trailIndex);
		cout << trailText;
		Sleep(50);

		if (trailIndex != baseIndex) {
			int trailVal = arr[trailIndex];
			if (trailVal == compare) return false;
		}

		if (trailIndex != matchIndex - 1) {
			clearChars(trailText.size());
		}
		else {
			cout << '\n';
		}
	}

	return true;
}

void printResults() {
	infile.open("repeated.txt");

	cout << '\n';

	cout << "*-------------------*\n|  Numbers Repeated |\n*-------------------*\n";
	if (infile.is_open()) {
		while (getline(infile, inLine)) {
			cout << "|         " << inLine << "        |\n";
		}
	}
	cout << "*-------------------*\n";
}

void clearChars(int num) {
	for (int i = 0; i < num; i++) {
		cout << '\b';
	}
}