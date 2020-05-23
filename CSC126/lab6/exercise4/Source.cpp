#include <iostream>
#include <string>

using namespace std;

string dna_to_rna(string& dna);

int main() {
	string dna;
	cin >> dna;

	cout << dna_to_rna(dna) << "\n";


	system("pause");
	return 0;
}

string dna_to_rna(string& dna) {
	string str = dna;
	string rna = "";
	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) == 'A') {
			rna += "U";
		}
		else if (str.at(i) == 'C') {
			rna += "G";
		}
		else if (str.at(i) == 'G') {
			rna += "C";
		}
		else if (str.at(i) == 'T') {
			rna += "A";
		}
	}
	return rna;
}