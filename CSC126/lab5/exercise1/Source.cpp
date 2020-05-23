#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main() {
	ofstream myfile;
	myfile.open("myEvenRandoms.txt");
	srand(time(0));
	for (int i = 0; i < 1000; i++) {
		int r = (rand() % 10 + 1) + 10;
		if (r % 2 == 0) {
			myfile << r << endl;
		}
	}
	myfile.close();
	return 0;
}