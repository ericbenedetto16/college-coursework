//Fill in the missing parts of this code
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class classGrades
{
	public:
		void printlist() const;
		void inputGrades(ifstream &);
		double returnAvg() const;
		void setName(string);
		void setNumStudents(int);
		classGrades();
		classGrades(int);

	private:
		int gradeList[30];
		int numStudents;
		string name;
};

int main()
{
	classGrades intro(5), intermediate;
	intro.printlist();
	ifstream infile;

	infile.open("data.txt");
	if (!infile)
	{
		cout << "Error opening file!" << endl;
		exit(1);
	}

	intro.setName("CSC126"); //set the name of the classGrades object intro to CSC126

	intermediate.setName("CSC211"); //set the name of the object intermediate to CSC211

	intermediate.setNumStudents(4);

	intermediate.inputGrades(infile); //input the grades for intermediate from a file

	intermediate.printlist(); //print the intermediate grades

	cout << intermediate.returnAvg() << '\n'; //print the average of the intermediate grades

	system("pause");
	return 0;
}

void classGrades::printlist() const
{
	int i;
	cout << "***" << name << "***" << numStudents << endl;
	for (i = 0; i < numStudents; i++)
		cout << i << ' ' << gradeList[i] << endl;
}

void classGrades::inputGrades(ifstream & in)
{
	int i;
	for (i = 0; i < numStudents; i++)
		in >> gradeList[i];
}

double classGrades::returnAvg() const
{
	int i;
	double average;
	double sum = 0;

	for (i = 0; i < this->numStudents; i++) { //write code to return the average
		sum += this->gradeList[i]; //write code to return the average
	} //write code to return the average

	average = sum / this->numStudents; //write code to return the average
	return average; //write code to return the average
}



void classGrades::setName(string n)
{
	name = n;
}

void classGrades::setNumStudents(int x)
{
	numStudents = x;
}

classGrades::classGrades()
{
	int i;
	name = "";
	numStudents = 30;
	for (i = 0; i < 30; i++)
		gradeList[i] = 0;
}

classGrades::classGrades(int n)
{
	int i;
	name = "";
	numStudents = n;
	for (i = 0; i < n; i++)
		gradeList[i] = 0;
}


classGrades allCS[15]; //the default constructor is applied to 					  //all elements of this array

//to set the number of students in each class to 25

for (int i = 0; i < 15; i++)
{
	allCS[i].setNumStudents(25);
}

//Assume values in all classes. How can we print all class averages?

for (int i = 0; i < 15; i++)
{
	cout << allCS[i].returnAvg() << '\n';
}