#include<iostream>
//header file needed for files
#include<fstream>
using namespace std;

void readData(ifstream &inFile, ofstream &outFile);

int main()
{
	ifstream inFile;
	ofstream outFile;

	inFile.open("data.txt"); //put the name of your text file in the quotes
	outFile.open("out.txt"); //this file will be created when the program runs

	readData(inFile, outFile);

	//close files
	inFile.close();
	outFile.close();

	return 0;
}


void readData(ifstream &inFile, ofstream &outFile) {
	//declarations for file stream variables

	//declarations for other variables
	int total = 0;
	int inputVal;


	//read from the file
	inFile >> inputVal;

	//do the loop while there are still numbers in the file
	while (!inFile.eof())
	{
		total += inputVal;
		inFile >> inputVal;

	}

	//output to the standard output and to a file
	outFile << "The total is: " << total << endl;
}
