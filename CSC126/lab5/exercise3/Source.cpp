#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <windows.h>
using namespace std;

void renderMenu();
void listen();
void madLibs();
void adventure();
void psychic();
void treasure();
void dice();
void guess();
void proceed();

int main() {
	bool ended = false;
	renderMenu();
	return 0;
}

void renderMenu() {
	system("cls");
	cout << "***************************************************" << endl << endl;
	cout << "                     Welcome!                      " << endl << endl;
	cout << "Please choose a number from the following options:" << endl << endl;
	cout << "1.\tMadlibs!" << endl << endl;
	cout << "2.\tChoose Your Own Adventure !" << endl << endl;
	cout << "3.\tPsychic future !" << endl << endl;
	cout << "4.\tFind the Treasure !" << endl << endl;
	cout << "5.\tDice Game !" << endl << endl;
	cout << "6.\tGuessing Game !" << endl << endl;
	cout << "7.\tExit" << endl << endl;
	cout << "****************************************************" << endl;

	listen();
}

void listen() {
	int n;
	cin >> n;

	switch (n) {
	case 1:
		madLibs();
		proceed();
		break;
	case 2:
		adventure();
		proceed();
		break;
	case 3:
		psychic();
		proceed();
		break;
	case 4:
		treasure();
		proceed();
		break;
	case 5:
		dice();
		proceed();
		break;
	case 6:
		guess();
		proceed();
		break;
	case 7:
		break;
	default:
		cout << "Invalid Input. Please try Again";
		renderMenu();
	}
}

void madLibs() {
	system("cls");
	string article,
		verb,
		pastVerb1,
		number,
		adjective1,
		verbING1,
		pastVerb2,
		company,
		nounP,
		adjective2,
		noun1,
		adjective3,
		noun2,
		adjective4,
		verbING2;

	cout << "Mad Libs" << endl << endl;
	cout << "My Interview" << endl << endl;

	cout << "Enter an Article of Dress: ";
	getline(cin, article);

	cout << "Enter a Verb: ";
	getline(cin, verb);

	cout << "Enter a Past Tense Verb: ";
	getline(cin, pastVerb1);

	cout << "Enter an Ordinal Number (1st, 3rd, etc): ";
	getline(cin, number);

	cout << "Enter an Adjective: ";
	getline(cin, adjective1);

	cout << "Enter a Verb (ending in ing): ";
	getline(cin, verbING1);

	cout << "Enter a Past Tense Verb: ";
	getline(cin, pastVerb2);

	cout << "Enter a Name of a Company: ";
	getline(cin, company);

	cout << "Enter a Noun (plural): ";
	getline(cin, nounP);

	cout << "Enter an Adjective: ";
	getline(cin, adjective2);

	cout << "Enter a Noun: ";
	getline(cin, noun1);

	cout << "Enter an Adjective: ";
	getline(cin, adjective3);

	cout << "Enter a Noun: ";
	getline(cin, noun2);

	cout << "Enter an Adjective: ";
	getline(cin, adjective4);

	cout << "Enter a Verb (ending in ing): ";
	getline(cin, verbING2);
	cout << endl;

	system("cls");

	cout << "Today I had an interview with "
		<< company << ". It was really pretty "
		<< adjective1 << " because it was only my "
		<< number << " interview."
		<< endl << endl << "I wore a(n) "
		<< adjective2 << " "
		<< article << ", and specially "
		<< pastVerb1 << " my hair just for today. But it didn't matter, because "
		<< endl << "everyone at the company wore "
		<< adjective3 << " clothing."
		<< endl << endl << "I suppose I shouldn't have brought up the topic of "
		<< nounP << ", but I did. From there on, things got really "
		<< adjective4 << "."
		<< endl << "They asked me all about my "
		<< noun1 << ", and also about my "
		<< noun2 << ". I nearly "
		<< pastVerb2 << "."
		<< endl << endl << "It didnt't help that they kept "
		<< verbING1 << ". I still don't know if they'll "
		<< verb << " me or not. I guess I'll just"
		<< endl << "have to keep "
		<< verbING2 << "." << endl;
}

void adventure() {
	system("cls");
	string crush;
	string other;
	string name;
	string lunch;
	string firstPronoun;
	string secondPronoun;
	char cur;
	bool attend = false;
	bool text = false;
	bool nextTo = false;
	int choice;

	cout << "Welcome to Your School Adventure Game, Please Enter Your Name: ";
	getline(cin, name);

	cout << "Enter Your Gender (M/F) ";
	cin >> cur;

	if (toupper(cur) == 'F') {
		crush = "Eric";
		other = "John";
		firstPronoun = "he";
		secondPronoun = "him";
	}
	else if (toupper(cur) == 'M') {
		crush = "Kelly";
		other = "Katie";
		firstPronoun = "she";
		secondPronoun = "her";
	}
	else {
		while (toupper(cur) != 'M' && toupper(cur) != 'F') {
			cout << "Please input a valid response (M/F) ";
			cin >> cur;
		}
		if (toupper(cur) == 'F') {
			crush = "Eric";
			other = "John";
			firstPronoun = "he";
			secondPronoun = "him";
		}
		else {
			if (toupper(cur) == 'M') {
				crush = "Kelly";
				other = "Katie";
				firstPronoun = "she";
				secondPronoun = "her";
			}
		}
	}
	cout << name << ", there is a winter concert coming up at school.\nYour crush " << crush << " will be there, are you going to go? (Y/N) ";
	cin >> cur;
	cout << endl;

	if (toupper(cur) == 'Y') {
		attend = true;
		cout << "You walk into the auditorium and peek your head around to look for " << crush << "." << endl;
		cout << "You see " << crush << " and " << other << " sitting only a few rows apart on the right side of the auditorium." << endl;
		cout << "Will you sit next to your crush? (Y/N) ";
		cin >> cur;
		cout << endl;

		if (toupper(cur) == 'Y') {
			nextTo = true;
			cout << "You sit down next to " << crush << " and " << firstPronoun << " tells you how strongly " << firstPronoun << " dislikes the genre \nof music being played." << endl;
			cout << crush << " pulls a bottle of Advil out of their bag and takes a couple. A few minutes before the concert \nends, " << crush << "'s brother comes over and tells " << secondPronoun << " they are leaving." << endl;
			cout << "Do you ask " << crush << " to text you when they get home or not? (Y/N) ";
			cin >> cur;
			cout << endl;

			if (toupper(cur) == 'Y') {
				text = true;
			}
		}
		else {
			cout << "You sit with " << other << " and you two carry a good conversation the entire concert." << endl;
			cout << crush << " is still sitting behind you while you and " << other << " talk." << endl;
			cout << "When the concert is coming to an end, " << other << " leaves.\nDo you turn around and talk to your crush now that " << other << " is gone? (Y/N) ";
			cin >> cur;
			cout << endl;

			if (toupper(cur) == 'Y') {
				nextTo = true;
				cout << "You begin a converstation with " << crush << " and you as the conversation builds,\nyou realize you should've sat with " << secondPronoun << "." << endl;
				cout << "Do you tell " << crush << " you regret not sitting next to " << secondPronoun << "? (Y/N) ";
				cin >> cur;
				cout << endl;

				if (toupper(cur) == 'Y') {
					cout << "As you go to tell " << secondPronoun << ", " << crush << "'s brother comes over and cuts\nthe conversation short because they're leaving." << endl;
					cout << "You do not get to tell her." << endl;
				}
				else {
					cout << crush << "'s brother comes over and they leaving." << endl;
				}
			}
		}
		cout << "You leave the concert and start to walk home.\nWhat do you think about grabbing some lunch? (Y/N) ";
		cin >> cur;
		cout << endl;

		if (toupper(cur) == 'Y') {
			cout << "You walk around the corner and go to John's, the hotspot deli\nfor your school. What do you order? (Enter 1 or 2)\n1.\t Bacon Egg and Cheese\n2.\t Beef Patty" << endl;
			cin >> choice;
			cout << endl;

			if (choice == 1) {
				lunch = "Bacon Egg and Cheese";
			}
			else {
				lunch = "Beef Patty";
			}
			cout << "You thoroughly enjoyed your " << lunch << ",\nand you walk the rest of the way home." << endl;
		}
		else {
			cout << "You had a big lunch so you take the hike home emptyhanded" << endl;
		}
	}
	else {
		cout << "Now that you decided to ditch the concert and leave school early,\nWhat do you think about stopping at the deli for some lunch? (Y/N) ";
		cin >> cur;
		cout << endl;

		if (toupper(cur) == 'Y') {
			cout << "You walk around the corner and go to John's, the hotspot deli\nfor your school. What do you order? (Enter 1 or 2)\n1.\t Bacon Egg and Cheese\n2.\t Beef Patty" << endl;
			cin >> choice;
			cout << endl;

			if (choice == 1) {
				lunch = "Bacon Egg and Cheese";
			}
			else {
				lunch = "Beef Patty";
			}
			cout << "You thoroughly enjoyed your " << lunch << ",\nand you walk the rest of the way home." << endl;
		}
		else {
			cout << "You had a big lunch so you take the hike home emptyhanded" << endl;
		}
	}
	cout << "You finally get home and go lay in bed.\nYou decide to get ready for a nap. Do you check your phone before you go to sleep? (Y/N) ";
	cin >> cur;
	cout << endl;

	if (toupper(cur) == 'Y') {
		if (attend == true && text == true) {
			cout << "You check your phone and see a text from " << crush << " that thanks you for having a conversation.\n" << crush << " admits feelings for you and wants to call you later." << endl;
			cout << "You go to sleep happily." << endl << endl;
			cout << "******************************THE END******************************" << endl;
		}
		else if (attend == true && nextTo == false) {
			cout << "You check your phone and see a text from " << crush << " that says you should've sat next to " << secondPronoun << " because " << firstPronoun << " has a crush on you." << endl;
			cout << "You go to sleep upset and feeling guilty." << endl << endl;
			cout << "******************************THE END******************************" << endl;
		}
		else if (attend == false) {
			cout << "You have a text from " << crush << " saying that " << firstPronoun << " wishes you came to the concert and " << firstPronoun << " missed you." << endl;
			cout << "You regret not attending the concert and you struggle to fall asleep." << endl << endl;
			cout << "******************************THE END******************************" << endl;

		}
		else {
			cout << "You check your phone and have no texts from " << crush << endl;
			cout << "You go to sleep sad and unsure about what you did and how to fix it." << endl << endl;
			cout << "******************************THE END******************************" << endl;
		}
	}
	else {
		cout << "You go to sleep and get some rest for tomorrow." << endl;
		cout << "******************************THE END******************************" << endl;
	}
}

bool running = true;
bool valid = false;
char cur;
void love();
void finance();
void school();
void search();
void prompt();
void psychic() {
	system("cls");
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

void treasure() {
	system("cls");
	int x = 15, y = 15;
	int x1, y1;
	int steps = 0;
	char direction;
	float distance;
	bool treasure = false;

	srand(time(0));
	x1 = rand() % 30 + 1;
	y1 = rand() % 30 + 1;
	distance = sqrt(static_cast<double>((x - x1)*(x - x1) + (y - y1)*(y - y1)));
	cout << "Distance From Treasure: " << distance << endl;

	do {
		cout << "Enter a direction: N S E W\n";
		cin >> direction;
		switch (direction)
		{
		case 'N':
		case 'n':
			y++;
			break;
		case 'S':
		case 's':
			y--;
			break;
		case 'E':
		case 'e':
			x++;
			break;
		case 'W':
		case 'w':
			x--;
			break;
		default:
			cout << "Invalid/Unrecognized Character, Please Try Again.\n";
			break;
		}
		steps++;
		distance = sqrt(static_cast<double>((x - x1)*(x - x1) + (y - y1)*(y - y1)));
		if (distance == 0) {
			treasure = true;
		}

		cout << "Distance From Treasure: " << distance << endl;
	} while (!treasure);

	cout << "Congratulations! You have found the treasure in " << steps << " steps!\n";
}

void welcome();
void dicePrompt();
void ask();
void rollDice(int times);
void again();
void lost();
void end();
bool diceRunning = true;
bool diceEnded = false;
bool allIn = false;
int remaining = 500;
int bet;
int rolls[2];
void dice() {
	system("cls");
	welcome();
	while (diceRunning) {
		dicePrompt();
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

	if (!diceRunning && !diceEnded) {
		end();
	}
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

void dicePrompt() {
	cout << "You have $" << remaining << " remaining.\nPlace your bet (Bets are Placed in Increments of $10): $";
	cin >> bet;
	cout << endl;

	if ((bet > 0 && bet <= remaining) && bet % 10 == 0) {
		bet = bet;
	}
	else {
		cout << "Out of Range. Try again." << endl;
		dicePrompt();
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
	diceEnded = true;
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
			diceRunning = true;
			system("cls");
			break;
		case 'n':
		case 'N':
			diceRunning = false;
			break;
		default:
			cout << "Invalid Input. Please Try Again.\n\n";
			again();
			break;
		}
	}
	else {
		cout << "You busted! Thank you for playing.\n";
		diceRunning = false;
	}
}

void end() {
	system("cls");
	cout << "You finished with a total of $" << remaining << "\n\nThank You For Playing!\n\n";
}

void guess() {
	system("cls");
	int num, guessed;
	bool isGuessed = false;
	int numOfGuesses = 0;

	srand(time(0));
	num = rand() % 100;
	
	while (!isGuessed) {
		cout << "Enter an integer, >= 0 and <=100: \n";
		cin >> guessed;
		cout << endl;

		if (guessed == num) {
			cout << "Correct! Congrats!" << endl;
			isGuessed = true;
		}
		else if (guessed < num) {
			cout << "Too small. Guess again!\n";
		}
		else {
			cout << "Too big. Guess again!\n";
			numOfGuesses++;
		}
		cout << "You guessed " << numOfGuesses << " times.\n\n";
	}
}

void proceed() {
	cout << "\nPress Enter To Continue...";
	cin.get();
	cin.ignore();
	Sleep(1000);
	renderMenu();
}