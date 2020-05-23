#include <iostream> 

using namespace std;

void pattern(int index_to_zero, int upper_bound, int n);

int main()
{
	int n;
	cout << "What number do you want your pyramid to print to?\n";
	cin >> n;

	pattern(n, n, n-1);
	system("pause");
	return 0;
}

void print_spaces(int n) {
	for (int i = 0; i < n; i++) {
		cout << "  ";
	}
}

void pattern(int index_to_zero, int upper_bound, int n) {
	const int spaces = index_to_zero - 1;
	const int current_num = upper_bound - index_to_zero + 1;
	const bool greater_ten = upper_bound > 9;

	if (index_to_zero == 0) {
		cout << "Pyramid complete!\n";
		return;
	}

	if (greater_ten) {
		for (int i = 0; i < spaces + n; i++) {
			cout << " ";
		}
		if (current_num < 10) {
			for (int i = 0; i < current_num; i++) {
				cout << current_num << "   ";
			}
		}
		else {
			for (int i = 0; i < current_num; i++) {
				cout << current_num << "  ";
			}
		} 

	}
	else {
		for (int i = 0; i < spaces; i++) {
			cout << " ";
		}

		for (int i = 0; i < current_num; i++) {
			cout << current_num << " ";
		}
	}

	cout << endl;

	pattern(index_to_zero - 1, upper_bound, n-1);
}