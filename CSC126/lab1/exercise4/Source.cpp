#include <iostream>
#include <iomanip>
using namespace std;

double profitCalculator() {
	cout << fixed << setprecision(2);
	double shares,
		purchased,
		selling,
		profit;

	cout << "How many shares did you purchase? ";
	cin >> shares;
	cout << endl << endl;

	cout << "What price did you buy your stocks? ";
	cin >> purchased;
	cout << endl << endl;

	cout << "What is the current selling price of the stock? ";
	cin >> selling;
	cout << endl << endl;

	profit = (shares * selling) - (shares * purchased);

	cout << "You have made a profit of $" << profit << " dollars since you bought " << shares << " of this stock." << endl;
	return 0;
}

int main() {
	//profitCalculator();
	
	cout << fixed << setprecision(2);
	double shares,
		purchased,
		selling,
		profit;

	cout << "How many shares did you purchase? ";
	cin >> shares;
	cout << endl << endl;

	cout << "What price did you buy your stocks? ";
	cin >> purchased;
	cout << endl << endl;

	cout << "What is the current selling price of the stock? ";
	cin >> selling;
	cout << endl << endl;

	profit = (shares * selling) - (shares * purchased);

	cout << "You have made a profit of $" << profit << " dollars since you bought " << shares << " of this stock.";

	system("pause");
	return 0;
}