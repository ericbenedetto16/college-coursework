#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int countDays();
const void injectDays(int * & arr, const int size, int & current_size);
const double calcAvg(int * arr, const int len);

int main() {
	int * Temperature = NULL;
	const int default_size = 5;
	int current_size = 5;
	Temperature = new int[5];

	injectDays(Temperature, default_size, current_size);
	cout << "Average Temperature: " << calcAvg(Temperature, current_size) << endl;

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

const void injectDays(int * & arr, const int size, int & current_size) {
	string line;
	int counter = 0;
	ifstream inFile;
	inFile.open("data.txt");
	while (getline(inFile, line)) {
		if (counter >= size) {
			int * temp = new int[counter+1];

			copy(arr, arr+counter, temp);

			delete [] arr;

			arr = temp;
		}
		arr[counter] = stoi(line);
		counter++;
		current_size = counter;
	}
	inFile.close();
}

const double calcAvg(int * arr, int len) {
	double sum = 0;
	for (int i = 0; i < len; i++) {
		sum += arr[i];
	}

	return sum /= len;
}