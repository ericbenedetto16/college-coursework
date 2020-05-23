#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;

	//Create Menu
	cout << "***************************************************" << endl << endl;
	cout << "                     Welcome!                      " << endl << endl;
	cout << "Please choose a number from the following options:" << endl << endl;
	cout << "1.\tChoose Your Own Adventure!" << endl << endl;
	cout << "2.\tMadlib!" << endl << endl;
	cout << "3.\tExit" << endl << endl;
	cout << "****************************************************" << endl;

	//Listen For Input and Run Code Based on Input
	cin >> n;
	cin.ignore();
	if (n == 1) {
		//Choose Your Own Adventure Code
		//Initialize Global Variable
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

		system("cls");
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

		//Option 1 - Winter Concert

		/**************************************
		 Ask User If They Are Going to Concert
		 **************************************/
		cout << name << ", there is a winter concert coming up at school.\nYour crush " << crush << " will be there, are you going to go? (Y/N) ";
		cin >> cur;
		cout << endl;

		if (toupper(cur) == 'Y') {
			//Storyline A
			attend = true;
			cout << "You walk into the auditorium and peek your head around to look for " << crush << "." << endl;
			cout << "You see " << crush << " and " << other << " sitting only a few rows apart on the right side of the auditorium." << endl;
			cout << "Will you sit next to your crush? (Y/N) ";
			cin >> cur;
			cout << endl;

			if (toupper(cur) == 'Y') {
				//Crush Story
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
			//Storyline B intersects and text when go home
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
			//Storyline B
			cout << "Now that you decided to ditch the concert and leave school early,\nWhat do you think about stopping at the deli for some lunch? (Y/N) ";
			cin >> cur;
			cout << endl;

			if (toupper(cur) == 'Y') {
				//Continue Storyline B
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
		//Stories Reconnect
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
		system("pause");
		return 0;
	}
	else if (n == 2) {
		//Madlib Code
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

		system("cls");

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

		system("pause");
		return 0;
	}
	else {
		return 0;
	}


	system("pause");
	return 0;
}