#include <iostream>
using namespace std;

double findUIAverage() {
	double numOne,
		numTwo,
		numThree,
		numFour,
		average;
	cout << "Enter the first number: ";
	cin >> numOne;
	cout << endl;

	cout << "Enter the second number: ";
	cin >> numTwo;
	cout << endl;

	cout << "Enter the third number: ";
	cin >> numThree;
	cout << endl;

	cout << "Enter the fourth number: ";
	cin >> numFour;
	cout << endl;

	double sum = (numOne + numTwo + numThree + numFour);
	average = double(sum / 4);
	cout << "\nThe average of these numbers is: " << average << endl;
	return 0;
}

int main() {
	//findUIAverage();

	double numOne,
		numTwo,
		numThree,
		numFour,
		average;
	cout << "Enter the first number: ";
	cin >> numOne;
	cout << endl;

	cout << "Enter the second number: ";
	cin >> numTwo;
	cout << endl;

	cout << "Enter the third number: ";
	cin >> numThree;
	cout << endl;

	cout << "Enter the fourth number: ";
	cin >> numFour;
	cout << endl;

	double sum = (numOne + numTwo + numThree + numFour);
	average = double(sum / 4);
	cout << "\nThe average of these numbers is: " << average << endl;

	system("pause");
	return 0;
}