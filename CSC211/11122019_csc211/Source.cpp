#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int countDays();
const void injectDays(int * arr);
const double calcAvg(int * arr, const int len);

int main() {
	int * Temperature = NULL;
	const int numDays = countDays();
	Temperature = new int[numDays];

	injectDays(Temperature);
	cout << "Average Temperature: " << calcAvg(Temperature, numDays) << endl;
		
	delete[] Temperature;
	Temperature = NULL;

	system("pause");
	return 0;
}

const int countDays() {
	string line;
	int counter = 0;
	ifstream inFile;
	inFile.open("data.txt");
	while (getline(inFile, line)) {

		counter++;
	}
	inFile.close();
	
	return counter;
}

const void injectDays(int * arr) {
	string line;
	int counter = 0;
	ifstream inFile;
	inFile.open("data.txt");
	while (getline(inFile, line)) {
		arr[counter] = stoi(line);
		counter++;
	}
	inFile.close();
}

const double calcAvg(int * arr, const int len) {
	double sum = 0;
	for (int i = 0; i < len; i++) {
		sum += arr[i];
	}

	return sum /= len;
}