#include <assert.h>
#include<type_traits>

#include "ArrayStack.h"

template<typename t>
class Garage {
	// Only Allow Template Types of IGarageItem to Ensure Count and Move Methods.
	static_assert(std::is_base_of<IGarageItem, t>::value, "t must inherit from IGarageItem");
private:
	ArrayStack<t> lane1;
	ArrayStack<t> lane2;
	ArrayStack<t> street;

	// Returns Pointer to Stack Containing Search Item
	ArrayStack<t>** findItem(t& item) {
		if (this->lane1.isPresent(item)) {
			ArrayStack<t>* s[3];
			s[0] = &(this->lane1);
			s[1] = &(this->lane2);
			s[2] = &(this->street);
			return s;
		}

		if (this->lane2.isPresent(item)) {
			ArrayStack<t>* s[3];
			s[0] = &(this->lane2);
			s[1] = &(this->lane1);
			s[2] = &(this->street);
			return s;
		}

		assert("No Item With Those Attributes Were found");
	}

	void moveItems(t& item) {
		if (this->search(item)) { 
			ArrayStack<t>** stacks = this->findItem(item);
			ArrayStack<t>* foundStack = stacks[0];
			ArrayStack<t>* secondaryStack = stacks[1];
			ArrayStack<t>* streetStack = stacks[2];
			
			while (!foundStack->isEmpty() && foundStack->peek() != item) {
				t blockingItem = (t&)(foundStack->peek());
				
				// Update Count on GarageItem
				blockingItem.move();
				
				cout << "Moving out of the way " << blockingItem << endl;
				if (!secondaryStack->full()) {
					secondaryStack->push(blockingItem);
				}
				else {
					street.push(blockingItem);
				}
				foundStack->pop();
			}

			// Remove Item Completely
			cout << "Departing " << (t&)foundStack->peek() << endl;
			foundStack->pop();

			// Push back onto stack
			while (!streetStack->isEmpty()) {
				t streetItem = (t&)streetStack->peek();

				// Update Count on GarageItem
				streetItem.move();
				if (!secondaryStack->full()) {
					cout << "Moving Back to Secondary Lane From Street " << streetItem << endl;

					secondaryStack->push(streetItem);

				}
				else {
					cout << "Moving Back to Initial Lane From Street " << streetItem << endl;
					foundStack->push(streetItem);
				}
				streetStack->pop();
			}
		} else {
			assert("Item With Given Attributes Does Not Exist");
		}
	}

public:
	Garage() {}

	~Garage() {}

	void arrival(t& item) {
		// Make Sure Car Doesn't Exist Already
		if (!this->search(item)) {
			// Check if stacks are full
			if (!this->lane1.full()) {
				cout << "Placing in Lane 1 " << item << endl;;
				this->lane1.push(item);
			}
			else if (!this->lane2.full()) {
				cout << "Placing in Lane 2 " << item << endl;
				this->lane2.push(item);
			}
			else {
				// Depart without Entering
				cout << "No Room. Departing " << item << endl;
			}
		}
		else {
			cout << "Item With Given Attributes Already Exists. Ignoring..." << endl;
		}
	}

	void departure(t& item) {
		// Shuffle to Street
		this->moveItems(item);
	}

	bool search(t& item) {
		// Find Item in Stack(s)
		if (this->lane1.isPresent(item) ^ this->lane2.isPresent(item)) {
			return true;
		}

		cout << "Item with Given Attributes Does Not Exist. Ignoring..." << endl;
		return false;
	}

	void clearStreet() {
		// Completely pop street stack
		while (!this->street.isEmpty()) {
			this->street.pop();
		}
	}
};