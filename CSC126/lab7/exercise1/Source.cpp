#include <iostream>

using namespace std;

double getSum(double arr[3][4]);

int main() {
	double myFancyArray[3][4] =
	{
		{23, 14.12, 17, 85.99},
		{6.06, 13, 1100, 0},
		{36.36, 90.09, 3.145, 5.4}
	};

	cout << "Sum: " << getSum(myFancyArray) << "\n";

	system("pause");
	return 0;
}

double getSum(double arr[3][4]) {
	double sum = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			sum += arr[i][j];
		}
	}
	return sum;
}