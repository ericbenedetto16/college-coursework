#include<iostream>
#include<string>

#include "ArrayStack.h"
#include "GarageItemInterface.h"

using namespace std;

class Car : public IGarageItem {
private:
	string license_plate;

public:
	Car() {}

	Car(string license_plate) {
		this->license_plate = license_plate;
		this->count = 0;
	}

	~Car() {}

	string getLicensePlate() {
		return this->license_plate;
	}

	void move() {
		this->count++;
	}
 	
	friend bool operator== (const Car& car1, const Car& car2) {
		return (car1.license_plate == car2.license_plate);
	}

	friend bool operator!= (const Car &car1, const Car &car2) {
		return !(car1 == car2);
	}

	friend ostream& operator<< (ostream& os, Car& c)
	{
		os << "License Plate: " << c.license_plate << ". Times Moved: " << c.count;
		return os;
	}
};