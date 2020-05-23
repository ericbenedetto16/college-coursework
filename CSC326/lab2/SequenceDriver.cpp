#include "Sequence.cpp"
#include <iostream>
#include <string>
#include <map>

using namespace std;

void showMenu(sequence<int> &);
int get_single_input();
map<string, int> get_user_input();
void fixCin();
void fixCin(string s, int &);

// Driver Program
int main() {
	sequence<int> seq;
	seq.push_back(16);
	seq.push_back(1);
	seq.push_back(25);

	showMenu(seq);

	return 0;
}

void showMenu(sequence<int> &seq) {
	bool responding = true;

	map<string, int> input;

	while (responding) {
		int response;
		cout << "Your current sequence is: {";
		seq.print();
		cout << "}\n";

		cout << "Enter a number from 1-6 to select a function:\n1. Get an element at a position\n2. Overwrite an element at a given position\n3. Add an element to the end of the array\n4. Insert an element at a given position\n5. Remove an element from a given position\n6. Exit\nSelection: ";
		cin >> response;

		switch (response) {
		case 1:
			cout << seq.at(get_single_input()) << endl;
			break;
		case 2:
			input = get_user_input();
			seq.set(input["entry"], input["position"]);
			break;
		case 3:
			seq.push_back(get_single_input());
			break;
		case 4:
			input = get_user_input();
			seq.insert(input["entry"], input["position"]);
			break;
		case 5:
			seq.remove_current(get_single_input());
			break;
		case 6:
			cout << "\n\nYour final sequence was: {";
			seq.print();
			cout << "}\n\n";
			responding = false;
			break;
		default:
			fixCin();
			cout << "Invalid Response. Please Try Again.\n";
			break;
		}
	}
}

map<string, int> get_user_input() {
	map<string, int> input;
	cout << "Enter a position and an element:\nPosition: ";
	cin >> input["position"];
	
	if (cin.fail()) fixCin("Position: ", input["position"]);
		
	cout << "Value: ";
	cin >> input["entry"];

	if (cin.fail()) fixCin("Value: ", input["entry"]);
	
	return input;
}

int get_single_input() {
	int ret;
	cout << "Enter a value: ";
	cin >> ret;
	if (cin.fail()) fixCin("Enter a value: ", ret);
	return ret;
}

void fixCin() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void fixCin(string s, int &n) {
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Data!\n" << s;
		cin >> n;
	}
}