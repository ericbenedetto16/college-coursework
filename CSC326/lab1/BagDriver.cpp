#include <iostream>
#include <string>
#include <vector>
#include "Bag.h"
using namespace std;

int removeItems(Bag<string>&, string);
void transferFragile(Bag<string>&, Bag<string>&, vector<string>&);

int main()
{
	string items[] = { "Coffee", "Milk", "Eggs", "Bread", "Eggs", "Cereal" };

	// Create our bags to hold items.
	Bag<string> storeBag;
	Bag<string> fragileBag;

	// Place the items in the bag.
	for (string item : items) {
		storeBag.add(item);
	}

	// Remove fragile items.
	vector<string> fragileItems = { "Bread", "Eggs" };
	transferFragile(storeBag, fragileBag, fragileItems);

	// Remove a specific item.
	string removableItem = "Cereal";
	cout << "Removed " << removeItems(storeBag, removableItem) << " instances of " << removableItem << '\n';
	cout << '\n';

	// Print bag contents.
	cout << "Storebag Contents: \n";
	storeBag.displayBagContents();
	cout << '\n';

	cout << "Fragilebag Contents: \n";
	fragileBag.displayBagContents();

	return 0;
}; // end main

int removeItems(Bag<string> &bag, string item) {
	const int iterations = bag.getFrequencyOf(item);
	for (int i = 0; i < iterations; i++) {
		bag.remove(item);
	}
	return iterations;
}

void transferFragile(Bag<string> &safeBag, Bag<string> &fragileBag, vector<string> &items) {
	for (string item : items) {
		const int iterations = safeBag.getFrequencyOf(item);
		for (int i = 0; i < iterations; i++) {
			fragileBag.add(item);
			safeBag.remove(item);
		}
	}
}