#include <iostream>

using namespace std;
void filterEvens(int arr[]);
int main() {
	int myArray[8];

	for (int i = 0; i < 8; i++) {
		cin >> myArray[i];
	}
	filterEvens(myArray);

	system("pause");
	return 0;
}

void filterEvens(int arr[]) {
	for (int i = 0; i < 8; i++) {
		if (arr[i] % 2 == 0) {
			cout << arr[i] << " ";
		}
	}
}