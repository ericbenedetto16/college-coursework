#include <iostream>
using namespace std;

double findAverage(double numOne, double numTwo, double numThree, double numFour) {
	double average = 0;
	double sum = (numOne + numTwo + numThree + numFour);
	average = double(sum / 4);
	cout << "The sum of those numbers is " << sum << endl << endl;
	cout << "The average of those numbers is " << average << endl << endl;
	return 0;
}

int main() {
	//findAverage(578, 986, 1066, 714);

	double numOne = 578,
		numTwo = 986,
		numThree = 1066,
		numFour = 714,
		average;
	double sum = (numOne + numTwo + numThree + numFour);
	average = double(sum / 4);
	cout << "The sum of those numbers is " << sum << endl << endl;
	cout << "The average of those numbers is " << average << endl << endl;

	system("pause");
	return 0;
}