#include<iostream>
using namespace std;

int main() {
	int n = 2;
	for (int i = 1; i < 20; i++) {
		n = n + n;
	}

	cout <<"On the 20th day of employment you will make "<< n << endl;


	system("pause");
	return 0;
}

