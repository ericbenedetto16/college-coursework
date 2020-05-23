#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	double owed,
		rate,
		pay,
		paid,
		remain,
		interest;

	int months = 0;
	cout << fixed << setprecision(2);

	cout << "How much money do you owe? $";
	cin >> owed;
	remain = owed;

	cout << "What is the yearly interest rate? (In Decimal Form) ";
	cin >> rate;
	interest = 0;

	cout << "How much will you pay each month? $";
	cin >> pay;
	paid = 0;

	do {
		if (remain >= pay) {
			remain -= pay;
			paid += pay;
		}
		else {
			paid += remain;
			remain -= remain;
		}

		if (remain > 0) {
			interest = (remain * (rate/12));
			remain += interest;

		}

		months++;
	}
	while (remain > 0);

	cout << "It will take you " << months << " months to pay off your loan." << endl;
	system("pause");
	return 0;
}