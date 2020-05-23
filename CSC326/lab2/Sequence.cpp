#include "Sequence.h"
#include <iostream>
#include <assert.h>

using namespace std;

template<class value_type>
sequence<value_type>::sequence(int size) {
	this->capacity = size;
	this->num_used = 0;
	this->data = new value_type[size];
}

template<class value_type>
sequence<value_type>::~sequence() {
	delete [] this->data;
}

template<class value_type>
bool sequence<value_type>::full() const {
	// Greater than should never occur.
	return this->num_used >= this->capacity;
}

template<class value_type>
bool sequence<value_type>::empty() const {
	// Less than should never occur.
	return this->num_used <= 0;
}

template<class value_type>
int sequence<value_type>::num_element() const {
	return this->num_used;
}

template<class value_type>
int sequence<value_type>::max_capacity() const {
	return this->capacity;
}

template<class value_type>
value_type sequence<value_type>::at(int position) const {
	/**
	* Exit if user tries to access an element further than
	* the interval from 0 to the last position of
	* numbers used.
	**/
	assert(position < this->num_used && position >= 0);
	return this->data[position];
}

template<class value_type>
void sequence<value_type>::set(const value_type& entry, int position) {
	/**
	* Exit if user tries to overwrite an element further than
	* the interval from 0 to the last position of
	* numbers used.
	* 
	* i.e. [0,1,2,3] positions 0-3 are valid because
	* 4 is the equivalent to push_back and is not an
	* invalid request.
	**/
	assert(position < this->num_used && position >= 0);
	this->data[position] = entry;
}

template<class value_type>
void sequence<value_type>::insert(const value_type& entry, int position) {
	/**
	* Exit if user tries to input an element further than
	* the interval from 0 to the last position of
	* numbers used + 1.
	* 
	* i.e. [0,1,2,3] positions 0-3 are valid because
	* 4 is the equivalent to push_back and is not an
	* invalid request.
	**/
	assert(position < this->num_used && position >= 0);

	if (full()) allocate_space();
	for (int i = this->num_used-1; i >= position; i--) {
		this->data[i + 1] = this->data[i];
	}

	this->data[position] = entry;
	this->num_used++;

}

template<class value_type>
void sequence<value_type>::push_back(const value_type& entry) {
	if (full()) allocate_space();
	
	this->data[num_used] = entry;
	this->num_used++;
}

template<class value_type>
void sequence<value_type>::remove_current(int position) {
	/**
	* Exit if user tries to access an element further than
	* the interval from 0 to the last position of
	* numbers used.
	**/
	assert(!empty() || (position < this->num_used && position >= 0));
	
	for (int i = position; i < this->num_used; i++) {
		this->data[i] = this->data[i+1];
	}

	this->num_used--;

}

template<class value_type>
void sequence<value_type>::print() const {
	for (int i = 0; i < this->num_used; i++) {
		i < (this->num_used-1) 
			? 
			cout << this->data[i] << ", " 
			:
			cout << this->data[i];
	}
}

// Part B
template<class value_type>
void sequence<value_type>::allocate_space() {
	// Memory Allocation and Cleanup
	this->capacity *= 2;

	value_type *temp = new value_type[this->capacity];

	copy(this->data, this->data + this->num_used, temp);
	
	delete [] this->data;

	this->data = temp;
}