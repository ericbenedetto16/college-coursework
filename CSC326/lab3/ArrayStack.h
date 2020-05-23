//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT stack: Array-based implementation.
 Listing 7-1
 @file ArrayStack.h */

#ifndef ARRAY_STACK_
#define ARRAY_STACK_

#include "StackInterface.h"

const int MAX_STACK = 5;

template<class ItemType>
class ArrayStack : public StackInterface<ItemType>
{
private:
	ItemType items[MAX_STACK]; // Array of stack items
	int      top;              // Index to top of stack

public:
	ArrayStack();             // Default constructor
	bool isEmpty() const;
	bool push(const ItemType& newEntry);
	bool pop();
	ItemType peek() const;

	// Custom Methods
	bool full() const {
		return (this->top + 1) >= MAX_STACK;
	}

	bool isPresent(ItemType& item) {
		// Return if item is in items[]
		for (int i = 0; i < (top + 1); i++) {
			if (items[i] == item) {
				return true;
			}
		}
		return false;
	}


}; // end ArrayStack

#include "ArrayStack.cpp"
#endif