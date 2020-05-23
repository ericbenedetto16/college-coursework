#include<iostream>
using namespace std;

int main() {
	char a,
		b,
		c,
		high,
		mid,
		low;
	
	cout << "Enter The First Character: ";
	cin >> a;

	cout << "Enter The Second Character: ";
	cin >> b;

	cout << "Enter The Third Character: ";
	cin >> c;

	if (((a >= 'A' && a <= 'Z') && (b >= 'A' && b <= 'Z') && (c >= 'A' && c <= 'Z')) || ((a >= 'a' && a <= 'z') && (b >= 'a' && b <= 'z') && (c >= 'a' && c <= 'z'))) {
		if (a > b && a > c) {
			high = a;
			if (b > c) {
				mid = b;
				low = c;
			}
			else {
				mid = c;
				low = b;
			}
		}
		else if (b > a && b > c) {
			high = b;
			if (a > c) {
				mid = a;
				low = c;
			}
			else {
				mid = c;
				low = a;
			}
		}
		else if (c > a && c > b) {
			high = c;
			if (a > b) {
				mid = a;
				low = b;
			}
			else {
				mid = b;
				low = a;
			}
		}

		cout << low << endl << mid << endl << high << endl;
	}
	else {
		cout << "There was an error in your input, please run again." << endl;
	}

	system("pause");
	return 0;
}