#include <iostream>
#include <fstream>
#include <string>

using namespace std;


const int ARRAY_SIZE = 100;

struct listType
{
	string listElem[ARRAY_SIZE];
	int listLength;
};

struct sectionInfo
{
	listType studentList;
	string sectionNum;
};


bool lp(int y);
int ndm(int m, bool l);
int ndy(bool l);
string day(int t);
void res(int d, int m, int y);

int main() {

	sectionInfo CSC211;

	CSC211.studentList.listElem[0] = "Joe";
	CSC211.studentList.listElem[1] = "Mel";
	CSC211.studentList.listElem[2] = "Sal";
	CSC211.sectionNum = "9056";
	CSC211.studentList.listLength = 3;

	for (int i = 0; i < CSC211.studentList.listLength; i++)
		cout << "Student # " << i << " of class " << CSC211.sectionNum << ":"
		<< CSC211.studentList.listElem[i] << endl;


	ifstream n;
	ofstream o;

	string l;
	int c = 0;

	n.open("data.txt");
	if (n.is_open()) {
		while (getline(n, l)) {
			const int md = l.find('/', 0);
			const int dd = l.find('/', md+1);

			int m = stoi(l.substr(0, md));
			int d = stoi(l.substr(md+1, dd));
			int y = stoi(l.substr(dd+1));

			res(d, m, y);
		}
	}

	system("pause");
	return 0;
}

bool lp(int y) {
	if (y % 4 == 0) {
		return true;
	}
	return false;
}

int ndm(int m, bool l) {
	if (m == 4 ^ m == 6 ^ m == 9 ^ m == 11) {
		return 30;
	}else if (m == 2) {
		if (l) {
			return 29;
		}
		return 28;
	}
	else {
		return 31;
	}
}

int ndy(bool l) {
	if (l) {
		return 366;
	}
	return 365;
}

string day(int t) {
	switch (t % 7) {
		case 0:
			return "Sunday";
			break;
		case 1:
			return "Monday";
			break;
		case 2:
			return "Tuesday";
			break;
		case 3:
			return "Wednesday";
			break;
		case 4:
			return "Thursday";
			break;
		case 5:
			return "Friday";
			break;
		case 6:
			return "Saturday";
			break;
	}
}

void res(int d, int m, int y) {
	const bool f = lp(y);
	int t = 0;

	for (int i = 1900; i < y; i++) {
		const bool l = lp(i);
		t += ndy(l);
	}

	for (int i = 1; i < m; i++) {
		t += ndm(i, f);
	}

	t += d-1;

	cout << day(t) << " " << m << "/" << d << "/" << y << " has a day value of " << t << endl;
}