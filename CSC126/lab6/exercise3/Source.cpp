#include <iostream>

using namespace std;

int main() {
	int cars[10] = { 7,3,6,0,14,8,1,2,9,8 };
	int highest = 0;
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += cars[i];
		if (cars[i] > highest) {
			highest = cars[i];
		}
	}
	cout << "There was a total of " << sum << " cars sold at the entire dealership.\n";
	cout << "Salesperson(s) with the most cars sold: \n";
	for (int i = 0; i < 10; i++) {
		if (cars[i] == highest) {
			cout << "Salesperson #" << i + 1 << " with a total of " << cars[i] << " cars sold. \n";
		}
	}

	system("pause");
	return 0;
}