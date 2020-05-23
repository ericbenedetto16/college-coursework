#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class textLines {
	private:
		// Data Members
		int size;
		int index;
		string * list = NULL;

		// Setter Functions
		void setSize(ifstream & f);
		void setSize(int n);
		void setIndex(int n);
		void populateList(ifstream & f);
	public:
		// Constructors
		textLines(ifstream & f);
		textLines(int n);
		textLines(const textLines & t);
		
		// Destructor
		~textLines();

		// Getter Functions
		int getSize();
		int getIndex();

		// Accessors & Modifiers
		void append(string s);
		void append(ifstream & f);
		void expand();
		string pop();
		void empty();
		void combine(textLines & t);
		string getLine(int i);

		// Printing
		void getSummary();
		friend ostream& operator<<(ostream& os, const textLines& t);

};

/**
 * Constructor with File Input
 * 
 * @param Input file which values will populate the list.
 */
textLines::textLines(ifstream & f) {
	this->setSize(f);
	this->setIndex(this->size);
	this->list = new string[this->size];
	this->populateList(f);
}

/**
 * Constructor with List Size
 * 
 * @param Integer n to set size of List.
 */
textLines::textLines(int n) {
	this->setSize(n);
	this->setIndex(-1);
	this->list = new string[this->size];
}

/** 
 * Copy Constructor
 * 
 * @param textLines Object to deep copy list into new object.
 */
textLines::textLines(const textLines & t) {
	size = t.size;
	list = new string[size];
	copy(t.list, t.list + size, list);
}

/**
 * Destructor
 * 
 * Deletes memory allocated for list
 */
textLines::~textLines() {
	delete [] this->list;
}

/**
 * Size Setter from File
 * 
 * Sets size of size member in textLines object
 * 
 * @param File f to count number of entries
 */
void textLines::setSize(ifstream & f) {
	int n = 0;
	string l;
	while (getline(f, l)) {
		n++;
	}

	this->size = n;

	f.clear();
	f.seekg(0, ios::beg);
}

/**
 * Size Setter from Integer
 * 
 * Sets size of size member in textLines object.
 * 
 * @param Integer n to initialize size.
 */
void textLines::setSize(int n) {
	this->size = n;
}

/**
 * Size Getter
 * 
 * Returns size member of textLines object.
 * 
 * @return Integer size of list.
 */
int textLines::getSize() {
	return this->size;
}

/**
 * Index Setter
 * 
 * Sets the number of the index in the list for
 * the last item modified or added.
 * 
 * @param Integer n of last modified list entry.
 */
void textLines::setIndex(int n) {
	this->index = n;
}

/**
 * Index Getter
 * 
 * Gets the number of the index in the list for
 * the last item modified or added.
 * 
 * @return Integer n of last modified list entry.
 */
int textLines::getIndex() {
	return this->index;
}

/**
 * List Population
 * 
 * Adds all items onto a list from a File and close it.
 * 
 * @param Input file f that contains lines of strings to be added to list.
 */
void textLines::populateList(ifstream & f) {
	int n = 0;
	string l;

	while (getline(f, l)) {
		this->list[n] = l;
		n++;
	}

	f.close();
}

/**
 * Remove Last Item from list
 * 
 * @return String of item being removed from list.
 */
string textLines::pop() {
	string l = "";
	if (this->index >= 0) {
		l = this->list[this->size-1];

		string * temp = new string[this->size];

		copy(this->list, this->list + this->index-1, temp);

		delete[] this->list;

		this->list = temp;

		this->setIndex(this->getIndex() - 1);
	}
	else {
		cout << "Trying to pop empty list!\n";
		return l;
	}

	return l;
}

// Empty Entire List
void textLines::empty() {
	for (int i = 0; i < this->size; i++) {
		this->pop();
	}
	
	cout << "List Emptied!\n";
}

/**
 * Append Item to List
 * 
 * @param String s of text to be appended to list.
 */
void textLines::append(string s) {
	for (int i = 0; i < this->size; i++) {
		if (this->list[i] == "") {
			this->list[i] = s;
			this->setIndex(i+1);
			cout << "Appended \"" << s << "\" to list\n";
			return;
		}
	}
	this->expand();
	this->append(s);
}

/**
 * Append Items from File
 * 
 * @param Input file f which contains lines of text to be appended.
 */
void textLines::append(ifstream & f) {
	this->populateList(f);
}

// Expand the List Allocation
void textLines::expand() {
	cout << "List Expanding...\n";

	string * temp = new string[this->size + 1];

	copy(this->list, this->list + this->size, temp);

	delete[] this->list;

	this->setSize(this->size + 1);

	this->list = temp;
}

// Get Lines Remaining and Occupied from List
void textLines::getSummary() {
	cout << "Number of Lines Occupied in List: " << this->index << "\nCurrent List Size: " << this->size << '\n';
}

/**
 * Set cout << textLines obj
 * 
 * @param Output Stream s to output the text.
 * @param textLines Object to get data from.
 * @return Output Stream s to be output.
 */
ostream& operator<<(ostream & os, const textLines & t) {
	for (int i = 0; i < t.size; i++) {
		if (t.list[i] != "") {
			os << t.list[i] << '\n';
		}
	}
	return os;
}

/**
 * Get Line from List
 * 
 * @param Integer i for the index of the item in the list.
 */
string textLines::getLine(int i) {
	return this->list[i];
}

/**
 * Combine Two Lists
 * 
 * @param textLines Object t to compare and combine lists with.
 */
void textLines::combine(textLines & t) {
	bool duplicate = false;
	for (int i = 0; i < t.getSize(); i++) {
		duplicate = false;
		for (int j = 0; j < this->size; j++) {
			if (t.getLine(i) == this->list[j] || t.getLine(i) == "") {
				duplicate = true;
			}
		}
		if (!duplicate) {
			this->append(t.getLine(i));
		}
	}
}

int main() {
    // Open Input File.
	ifstream f;
	f.open("input.txt");
	
	// Initialize textLines Object using File Constructor.
	textLines one(f);
	
	// Initialize textLines Object using Integer Constructor.
	textLines two(8);
    // Append Values to textLines Empty List.
	two.append("0");
	two.append("1");
	two.append("2");
	two.append("3");
	two.append("4");
	two.append("5");
	two.append("6");
	two.append("7");

    // Print the Two textLines Object Lists.
	cout << one;
	cout << two;
	
	// Pop an Element from the end of textLines Object one.
	cout << "Removing Element: " << one.pop() << '\n';
	
	// Print textLine Object one's List.
	cout << one;
	
	// Append Values to textLines Object one and Print.
	one.append("999");
	cout << one;
	one.append("888");
	cout << one;
	
	// Empty textLines Object one's list and Print.
	one.empty();
	cout << one;
	
	// Print Summary of textLines Object one.
	one.getSummary();
	
	// Reopen Input File.
	f.open("input.txt");
	
	// Append Items from File to textLines Object one and Print.
	one.append(f);
	cout << one;
	
	// Combine textLines Object one and textLines Object two.
	one.combine(two);
	
	// Deep Copy textLines Object one Into textLines Object three and Print.
	textLines three = one;
	cout << three;

	system("pause");
	return 0;
}