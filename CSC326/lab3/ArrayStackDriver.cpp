#include <iostream>
#include <string>
#include <fstream>

#include "Car.h"
#include "Garage.h"

using namespace std;

void getData();

int main() {
	Garage<Car> g = Garage<Car>();

	ifstream f;
	f.open("data.txt");
	string line;

	while (getline(f, line)) {
		char identifier = line[0];
		string license_plate = line.substr(2);
		Car c = Car(license_plate);

		switch (identifier) {
		case 'A':
			g.arrival(c);
			break;
		case 'D':
			g.departure(c);
			break;
		default:
			assert("Invalid Input");
		}
	}

	system("pause");
	return 0;
}

void getData() {
	ifstream f;
	f.open("data.txt");
	string line;

	while (getline(f, line)) {
		char identifier = line[0];
		string license_plate = line.substr(2);
	}
}