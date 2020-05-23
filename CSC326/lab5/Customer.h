#pragma once

#ifndef CUSTOMER
#define CUSTOMER

using namespace std;

class Customer {
private:
	bool waiting;
	double arrivalTime, waitTime, timePassed, timeRemaining;
public:
	Customer() { ; }
	Customer(double arrivalTime) {
		this->waiting = true;
		this->arrivalTime = arrivalTime;
		this->waitTime = 0;
	}

	void setRemaining(double remaining) { this->timeRemaining = remaining; }
	void incrementWait() { this->waitTime++; }
	void serve() { this->timeRemaining--; }
	void setWaiting(bool waiting) { this->waiting = waiting; }
	double getRemaining() { return this->timeRemaining; }
	double getWait() { return this->waitTime; }
	bool isWaiting() { return this->waiting; }
	~Customer() {}
};

#endif