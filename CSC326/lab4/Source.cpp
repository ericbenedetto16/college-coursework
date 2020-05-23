#include <iostream>
#include <fstream>
#include <string>

#include "ArrayList.h"
#include "LinkedList.h"

using namespace std;

template <class ItemType>
void ArrayList<ItemType>::print() const {
	try {
		int upper = this->itemCount;
		for (int i = 1; i <= upper; i++) {
			if (i != upper) { cout << this->getEntry(i) << ", "; }
			else { cout << this->getEntry(i); }
		}
	}
	catch (exception &e) {
		cerr << e.what() << endl;
	}
}

template <class ItemType>
void LinkedList<ItemType>::print() const {
	try {
		int upper = this->itemCount;
		for (int i = 1; i <= upper; i++) {
			if (i != upper) { cout << this->getEntry(i) << ", "; }
			else { cout << this->getEntry(i); }
		}
	}
	catch (exception &e) {
		cerr << e.what() << endl;
	}
}

template <class ItemType>
void LinkedList<ItemType>::selectionSort() {
	if (this->getLength() <= 1) { return; }

	try {
		const int length = this->getLength();
		int currIndex, searchIndex, lowestIndex;
		ItemType currNum, searchNum, lowestNum;

		currIndex = searchIndex = lowestIndex = 1;
		currNum = searchNum = lowestNum = this->getEntry(1);

		// Loop through entire list
		for (int i = 1; i < length; i++) {
			// Current index is initially the search item 
			currIndex = lowestIndex = i;
			currNum = lowestNum = this->getEntry(i);

			// Loop through rest of list
			for (int j = currIndex + 1; j <= length; j++) {
				// Set search index and currentNum everytime moved
				searchIndex = j;
				searchNum = this->getEntry(j);

				// If the current number is less than the lowest
				if (searchNum < lowestNum) {
					// Set the lowest num and lowest index to current
					lowestNum = searchNum;
					lowestIndex = searchIndex;
				}
			}

			// Once finished looping through list
			// If the lowest index is not the current starting index
			if (lowestIndex != currIndex) {
				// Switch the values of the two indices
				this->replace(currIndex, lowestNum);
				this->replace(lowestIndex, currNum);
			}
		}
	}
	catch (exception &e) {
		cerr << e.what() << endl;
	}
}

template <class ItemType>
void selectionSort(ListInterface<ItemType> &list) {
	if (list.getLength() <= 1) { return; }

	try {
		const int length = list.getLength();
		int currIndex, searchIndex,lowestIndex;
		ItemType currNum, searchNum, lowestNum;

		currIndex = searchIndex = lowestIndex = 1;
		currNum = searchNum = lowestNum = list.getEntry(1);

		// Loop through entire list
		for (int i = 1; i < length; i++) {
			// Current index is initially the search item 
			currIndex = lowestIndex = i;
			currNum = lowestNum = list.getEntry(i);

			// Loop through rest of list
			for (int j = currIndex + 1; j <= length; j++) {
				// Set search index and currentNum everytime moved
				searchIndex = j;
				searchNum = list.getEntry(j);

				// If the current number is less than the lowest
				if (searchNum < lowestNum) {
					// Set the lowest num and lowest index to current
					lowestNum = searchNum;
					lowestIndex = searchIndex;
				}
			}

			// Once finished looping through list
			// If the lowest index is not the current starting index
			if (lowestIndex != currIndex) {
				// Switch the values of the two indices
				list.replace(currIndex, lowestNum);
				list.replace(lowestIndex, currNum);
			}
		}
	}
	catch (exception &e) {
		cerr << e.what() << endl;
	}
}

int main() {
	ifstream infile;
	infile.open("data.txt");
	ArrayList<string> arrListString;
	LinkedList<string> linkListString;
	LinkedList<string> linkListStringPublic;

	ArrayList<int> arrListInt;
	LinkedList<int> linkListInt;

	if (infile) {
		string line;
		int counter = 1;
	
		while (getline(infile, line)) {
			if (counter <= 5) {
				arrListString.insert(counter, line);
				linkListString.insert(counter, line);
			}
			if (counter > 5 && counter <= 10) {
				int n = stoi(line);
				arrListInt.insert(counter - 5, n);
				linkListInt.insert(counter - 5, n);
			}
			if(counter > 10 && counter <= 15) linkListStringPublic.insert(counter-10, line);

			counter++;

		}
	}
	else {
		cout << "There was an issue opening the file!" << endl;
		system("pause");
		exit(1);
	}

	cout << "ArrayList Integer: ";
	arrListInt.print();
	cout << endl;

	cout << "LinkedList Integer: ";
	linkListInt.print();
	cout << endl << endl;

	selectionSort(arrListInt);
	selectionSort(linkListInt);

	cout << "Sorted ArrayList Integer: ";
	arrListInt.print();
	cout << endl;

	cout << "Sorted LinkedList Integer: ";
	linkListInt.print();
	cout << endl << endl;

	cout << "ArrayList String: ";
	arrListString.print();
	cout << endl;

	cout << "LinkedList String: ";
	linkListString.print();
	cout << endl << endl;

	selectionSort(arrListString);
	selectionSort(linkListString);

	cout << "Sorted ArrayList String: ";
	arrListString.print();
	cout << endl;

	cout << "Sorted LinkedList String: ";
	linkListString.print();
	cout << endl << endl;

	cout << "Part B LinkedList String: ";
	linkListStringPublic.print();
	cout << endl;

	linkListStringPublic.selectionSort();

	cout << "Part B Sorted LinkedList String: ";
	linkListStringPublic.print();
	cout << endl << endl;

	system("pause");
	return 0;
}