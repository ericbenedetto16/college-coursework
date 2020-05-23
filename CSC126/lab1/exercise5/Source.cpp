#include<iostream>
#include<string>
using namespace std;

int main() {
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

	system("pause");
	return 0;
}