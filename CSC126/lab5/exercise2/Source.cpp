#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>

using namespace std;

void welcome();
void prompt();
void ask();
void rollDice(int times);
void again();
void lost();
void end();


bool running = true;
bool ended = false;
bool allIn = false;
int remaining = 500;
int bet;
int rolls[2];
int main() {
	srand(time(0));
	welcome();
	while (running) {
		prompt();
		rollDice(2);
		if (rolls[0] == rolls[1]) {
			remaining += bet;
			ask();
		}
		else {
			remaining -= bet;
			lost();
		}
		again();
	}

	if (!running && !ended) {
		end();
	}
	return 0;
}

void welcome() {
	cout << "\tWelcome to 2 of a Kind\n\n\n";
	cout << "                   (( _______\n";
	cout << "         _______     /\\O    O\\\n";
	cout << "        /O     /\\   /  \\      \\\n";
	cout << "       /   O  /O \\ / O  \\O____O\\ ))\n";
	cout << "    ((/_____O/    \\    /O     /\n";
	cout << "      \\O    O\\    / \\  /   O  /\n";
	cout << "       \\O    O\\ O/   \\/_____O/\n";
	cout << "        \\O____O\\/ ))          ))\n";
	cout << "      ((\n\n\n";
	cout << "In this game you place bets on a pair of dice.\nIf when rolled, the dice land on the same numbers,\nyou win your bet and earn a chance to double\nthe winning but risk losing your original stake.\n\n";
	cout << "Good Luck. Have Fun!\n\n";

	cout << "Loading";
	for (int i = 0; i < 5; i++) {
		Sleep(600);
		cout << "." << flush;
		Sleep(500);
		cout << "." << flush;
		Sleep(200);
		cout << "." << flush;
		Sleep(700);
	}
	system("cls");
}

void prompt() {
	cout << "You have $" << remaining << " remaining.\nPlace your bet (Bets are Placed in Increments of $10): $";
	cin >> bet;
	cout << endl;

	if ((bet > 0 && bet <= remaining) && bet % 10 == 0) {
		bet = bet;
	}else {
		cout << "Out of Range. Try again." << endl;
		prompt();
	}
}
void rollDice(int times) {
	system("cls");
	for (int i = 0; i < times; i++) {
		int r = rand() % 6 + 1;
		rolls[i] = r;
		cout << "Roll number " << i + 1 << ": " << rolls[i] << endl;
	}
	cout << endl;
}

void ask() {
	bool valid = false;
	char cur;
	cout << "You rolled the same number and won $" << bet << "\nYou know have $" << remaining << "\n\nIf you would like to risk your winnings, you can risk it for a chance to win an additional $" << bet * 2 << "\nBringing your total profit for this set to $" << bet * 2 + bet << " (y/n)\n";
	cin >> cur;
	switch (cur) {
	case 'y':
	case 'Y':
		valid = true;
		allIn = true;
		break;
	case 'n':
	case 'N':
		valid = true;
		allIn = false;
		break;
	default:
		valid = false;
		cout << "Invalid Input. Please Try Again.\n\n";
		ask();
		break;
	}
	cout << endl;

	if (valid) {
		if (allIn) {
			rollDice(2);

			if (rolls[0] == rolls[1]) {
				remaining += bet * 2;
				cout << "Congratulations! You just doubled your winnings!\nYou now have a total balance of $" << remaining << "\n\n";
			}
			else {
				remaining -= bet * 2;
			}
		}
	}
}

void lost() {
	ended = true;
	cout << "You lost this set.\nYou now have $" << remaining << endl << endl;
}

void again() {
	char cur;
	if (remaining > 0) {
		cout << "Would you like to continue playing and roll again? (y/n)\n";
		cin >> cur;
		cout << endl;
		switch (cur) {
		case 'y':
		case 'Y':
			running = true;
			system("cls");
			break;
		case 'n':
		case 'N':
			running = false;
			break;
		default:
			cout << "Invalid Input. Please Try Again.\n\n";
			again();
			break;
		}
	}
	else {
		cout << "You busted! Thank you for playing.\n";
		running = false;
	}
}

void end() {
	system("cls");
	cout << "You finished with a total of $" << remaining << "\n\nThank You For Playing!\n\n";
	cout << "Press Enter To Exit...";
	cin.get();
	cin.ignore();
}