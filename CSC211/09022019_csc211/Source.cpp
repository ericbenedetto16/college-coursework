#include <iostream>
#include <array>

using namespace std;

void switchVals(int *arr, int size);

int main() {

	int arr[5] = { 1,2,3,4,5 };
	int *p = arr;
	int s = sizeof(arr) / sizeof(arr[0]);
	cout << s << '\n';

	switchVals(p, s);

	for(int i = 0; i < 5; i++)
		cout << arr[i];

	system("pause");
	return 0;
}

void switchVals(int *arr, int size) {
	int t = arr[0];

	arr[0] = arr[size - 1];
	arr[size - 1] = t;
}