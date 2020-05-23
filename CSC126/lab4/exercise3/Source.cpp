#include <iostream>
#include <windows.h>
using namespace std;

//Global Variables
bool running = true;
bool valid = false;
char cur;
void love();
void finance();
void school();
void search();
void prompt();

int main() {
	int num;

	cout << "Welcome to the Psychic Computer Network\n";
	cout << "My name is Dionne, and I will be your psychic computer guide\n\n";
	cout << "Please enter your lucky number:  ";
	cin >> num;
	cout << "\n\n";

	while (running) {

		cout << "Please enter an \"L\" for my predictions on your lovelife.\n";
		cout << "Enter the letter \"S\" for my predictions on your school life.\n";
		cout << "Enter the letter \"M\" for my predictions on your financial situation.\n";
		cin >> cur;

		while (!valid) {
			switch (cur) {
			case 'L':
			case 'l':
				valid = true;
				love();
				break;
			case 'S':
			case 's':
				valid = true;
				school();
				break;
			case 'M':
			case 'm':
				valid = true;
				finance();
				break;
			default:
				cout << "\nPlease enter an \"L\" for my predictions on your lovelife.\n";
				cout << "Enter the letter \"S\" for my predictions on your school life.\n";
				cout << "Enter the letter \"M\" for my predictions on your financial situation.\n";
				cin >> cur;
			}
		}
	}

	system("pause");
	return 0;
}

void love() {
	search();
	cout << endl;

	int r = rand() % 5 + 1;
	switch (r) {
	case 1:
		cout << "I see that marriage will lead to happiness." << endl << endl;
		break;
	case 2:
		cout << "I see that you will meet your true love in the upcoming year." << endl << endl;
		break;
	case 3:
		cout << "I see that you will find a companion very soon." << endl << endl;
		break;
	case 4:
		cout << "I see that you must learn to love yourself." << endl << endl;
		break;
	case 5:
		cout << "I see that there is a big event coming in your love life." << endl << endl;
		break;
	}
	

	prompt();
}

void finance() {
	search();
	cout << endl;

	int r = rand() % 5 + 1;
	switch (r) {
	case 1:
		cout << "Your poverty today will turn into wealth tomorrow." << endl << endl;
		break;
	case 2:
		cout << "Your every wish will come true if you continue what you are doing." << endl << endl;
		break;
	case 3:
		cout << "Your bank account is expecting a good surprise in the coming weeks." << endl << endl;
		break;
	case 4:
		cout << "Your boss might be looking for a higher paid position to fill soon." << endl << endl;
		break;
	case 5:
		cout << "Your upcoming birthday will bring you wealth." << endl << endl;
		break;
	}
	prompt();
}

void school() {
	search();
	cout << endl;

	int r = rand() % 5 + 1;
	switch (r) {
	case 1:
		cout << "You will learn to love computer science and your wonderful computer science instructors." << endl << endl;
		break;
	case 2:
		cout << "You will learn to love mathematics and your wonderful mathematics instructors." << endl << endl;
		break;
	case 3:
		cout << "You will learn to love chemistry and your wonderful chemistry instructors." << endl << endl;
		break;
	case 4:
		cout << "You will learn to love space science and your wonderful space science instructors." << endl << endl;
		break;
	case 5:
		cout << "You will learn to love statistics and your wonderful statistics instructors." << endl << endl;
		break;
	}
	prompt();
}

void search() {
	cout << "\nI am looking into my crystal ball\n\n";
	for (int i = 0; i < 10; i++) {
		Sleep(100);
		cout << "\b\\" << flush;
		Sleep(100);
		cout << "\b|" << flush;
		Sleep(100);
		cout << "\b/" << flush;
		Sleep(100);
		cout << "\b-" << flush;
		if (i == 9) {
			cout << "\b \b";
		}
	}
}

void prompt() {
	char temp;
	cout << "Thank you for using the psychic computer network.\n";
	cout << "Would you like me to make another prediction?  y/n\n";
	cin >> temp;
	if (temp == 'y' || temp == 'Y') {
		running = true;
		valid = false;
		cur = ' ';
	}
	else if (temp == 'n' || temp == 'N') {
		running = false;
	}
	else {
		cout << "\n";
		prompt();
	}
}