#include <iostream>
using namespace std;

void addThem(int num1,int num2) {
	int sum = num1 + num2;
	cout << "The sum of " << num1 << " and " << num2 << " is " << sum << endl;
}

int main() {
	int num1,
		num2;

	cout << "Enter two integers: ";
	cin >> num1;
	cin >> num2;

	addThem(num1, num2);
	

	system("pause");
	return 0;
}