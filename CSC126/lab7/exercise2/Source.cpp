#include <iostream>

using namespace std;

void initializeMap();
void displayMap();
void makeReservation();
void validateFunction(int seat, int row);
void prompt();
char seatChart[13][6];
int num = 0;

int main() {
	bool ended = false;
	initializeMap();

	while (!ended) {
		prompt();
		switch (num) {
			case 1:
				displayMap();
				cout << "\n";
				break;
			case 2:
				makeReservation();
				cout << "\n";
				break;
			case 3:
				ended = true;
				break;
			default:
				break;
		}
	}

	system("pause");
	return 0;
}

void initializeMap() {
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 6; j++) {
			seatChart[i][j] = '*';
		}
	}
}

void displayMap() {
	cout << "\t\tA\tB\tC\tD\tE\tF\n";
	for (int j = 0; j < 13; j++) {
		cout << "\nRow " << j+1 << "\t\t";
		for (int i = 0; i < 6; i++) {
			cout << seatChart[j][i] << "\t";
		}
	}
}

void makeReservation() {
	int row;
	char seatL;
	int seat = 0;
	cout << "To reserve a seat enter the seat letter (A-F) and the row number (1-13)\n";
	cin >> seatL;
	cin >> row;

	switch (seatL) {
		case 'A':
			seat = 0;
			break;
		case 'B':
			seat = 1;
			break;
		case 'C':
			seat = 2;
			break;
		case 'D':
			seat = 3;
			break;
		case 'E':
			seat = 4;
			break;
		case 'F':
			seat = 5;
			break;
		default:
			cout << "Error no letter";
			break;
	}
	validateFunction(seat, row);
}


void validateFunction(int seat, int row) {
	if (seatChart[row - 1][seat] != 'X') {
		seatChart[row - 1][seat] = 'X';
		cout << "Seat Reserved\n";
	}
	else {
		cout << "Seat Already Taken. Please Try Again.\n";
		makeReservation();
	}
}

void prompt() {
	cout << "Enter 1 to display a map of all seats.\nEnter 2 to reserve a seat.\nEnter 3 to exit\n";
	num = 99;
	cin >> num;
}