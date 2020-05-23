#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main() {
	cout << fixed << setprecision(2);
	char c;
	double firstSalary,
		deductSalary,
		rate,
		tax,
		netSal,
		loan;
	int children;

	cout << "What was your annual salary? $";
	cin >> firstSalary;

	cout << "Do you have any children? (Y/N) ";
	cin >> c;

	c = toupper(c);

	if (c == 'Y') {
		cout << "How many children? ";
		cin >> children;

		deductSalary = firstSalary - ((0.05*firstSalary)*children);
	}

	cout << "Do you make student loan payments? (Y/N) ";
	cin >> c;

	c = toupper(c);

	if (c == 'Y') {
		cout << "How much interest was paid on the loan last year? $";
		cin >> loan;

		deductSalary = deductSalary - loan;
	}

	if (deductSalary <= 12000) {
		rate = 0.06;
	}
	else if (deductSalary >= 12001 && firstSalary <= 38000) {
		rate = 0.27;
	}
	else if (deductSalary >= 38001 && firstSalary <= 55000) {
		rate = 0.33;
	}
	else {
		rate = 0.39;
	}

	tax = deductSalary * rate;
	netSal = firstSalary - tax;

	cout << "This year you paid $" << tax << " dollars in tax.\nSo your net salary after taxes are taken out is $" << netSal << endl;

	system("pause");
	return 0;
}