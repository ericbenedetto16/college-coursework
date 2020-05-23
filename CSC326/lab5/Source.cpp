#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "ArrayQueue.h"
#include "NoServersException.h"
#include "InvalidTimeException.h"
#include "Server.h"

using namespace std;

float runSimulation(int numServers, double arrivTimeDist, double exptServTime, double lengthSim);

int main() {
	float n = runSimulation(1,5,6,100);
	float n2 = runSimulation(2, 5, 6, 100);

	cout << "Average Wait Time (1 Server): " << n << endl;
	cout << "Average Wait Time (2 Server): " << n2 << endl;

	system("pause");
	return 0;
}

float runSimulation(int numServers, double arrivTimeDist, double exptSvcTime, double lengthSim) {
	// Guard Clauses
	if (numServers < 1) { throw NoServersException(); }
	if (lengthSim <= 0 || exptSvcTime <= 0 || arrivTimeDist <= 0) { throw InvalidTimeException(); }
	
	// Initialize Queue
	ArrayQueue<Customer*>* queuePtr = new ArrayQueue <Customer*>();

	// Trackers for Tellers and Customers
	vector<Customer*> customers;
	vector<Server*> tellers;

	// Initialize list of tellers
	for (int i = 0; i <= numServers; i++) {
		tellers.push_back(&Server());
	}

	// Main Logic
	double time = 0.0;
	// While the time is less than total simulation
	while (time < lengthSim) {
		// Increment Time
		time++;

		// Calculate Probability of Arrival
		float prob = 1 / float(arrivTimeDist);
		float n = rand() / float(RAND_MAX);

		// If customer arrives
		if (n <= prob) 
		{
			Customer *c = new Customer(time);
			// Add Customer to tracking list
			customers.push_back(c);
			// Enqueue
			queuePtr->enqueue(c);
		}

		// Increment wait for waiting customers
		for (Customer *c : customers) {
			if (c->isWaiting()) {
				c->incrementWait();
			}
		}

		// Work on tellers
		for (Server *s : tellers) {
			// If a teller is free and customers in line
			if (!s->isBusy() && queuePtr->length() > 0) {
				// Get customer from front of line
				Customer* c = queuePtr->peekFront();
				// Assign teller customer and make busy
				s->setCustomer(c, exptSvcTime);
				s->makeBusy();

				// Remove customer from line
				queuePtr->dequeue();
			} else {
				// Serve customer
				s->serve();
			}
		}
	}

	double totalWait = 0.0;
	// Get the wait time from all customers
	for (Customer *c : customers) {
		totalWait += c->getWait();
	}

	// Release the queuePtr
	delete queuePtr;

	// Get total customers
	int numCustomers = customers.size();

	// Get average wait time
	return float(totalWait) / float(numCustomers);
}