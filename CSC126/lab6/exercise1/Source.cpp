#include <iostream>

using namespace std;

int main() {
	double alpha[50];

	for (int i = 0; i < 50; i++) {
		if (i < 25) {
			alpha[i] = sqrt(i);
		}
		else {
			alpha[i] = i * 3;
		}
		
		if (i % 10 == 0) {
			cout << endl;
			cout << alpha[i] << " ";
		}
		else {
			cout << alpha[i] << " ";
		}
	}

	cout << endl;
	system("pause");
	return 0;
}