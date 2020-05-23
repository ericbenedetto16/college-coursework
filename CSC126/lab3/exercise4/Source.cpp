#include <iostream>
using namespace std;

int main() {
	int sum = 0;

	for (int i = 0; i <= 100; i++) {
		sum += i;
	}
	cout << "Sum of all numbers from 1 to 100 is: " << sum << endl;

	sum = 0;
	for (int i = 0; i <= 100; i += 2) {
		sum += i;
	}
	cout << "Sum of all even numbers from 1 to 100 is: " << sum << endl;

	sum = 0;
	for (int i = 1; i <= 100; i += 2) {
		sum += i;
	}
	cout << "Sum of all odd numbers from 1 to 100 is: " << sum << endl;

	system("pause");
	return 0;
}