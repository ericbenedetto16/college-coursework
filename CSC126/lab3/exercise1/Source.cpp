#include<iostream>
using namespace std;

int main() {
	int n;

	cout << "Enter a number: ";
	cin >> n;

	for (int i = n; i >= 0; i--) {
		cout << "It is now " << i << endl;
	}

	system("pause");
	return 0;
}