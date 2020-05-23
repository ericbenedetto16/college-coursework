#include<iostream>
using namespace std;

int main() {
	int temp;

	cout << "Enter today's temperature: ";
	cin >> temp;

	if (temp >= 80) {
		cout << "It is very hot today!" << endl;
	}
	else if (temp <= 40) {
		cout << "It is very cold today!" << endl;
	}
	else {
		cout << "It is a beautiful day outside!" << endl;
	}



	system("pause");
	return 0;
}