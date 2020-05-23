#pragma once

#include "Customer.h"

#ifndef SERVER
#define SERVER

using namespace std;

class Server {
private:
	bool busy;
	Customer *c;
public:
	Server() {
		this->busy = false;
	}

	Server(bool busy) {
		this->busy = busy;
	}

	bool isBusy() { return this->busy; }
	void serve() {
		if (c->getRemaining() == 1) {
			this->c->serve();
			this->busy = false;
		}
		else {
			this->c->serve();
		}
	}
	void setCustomer(Customer *c, double time) {
		this->c = c;
		c->setWaiting(false);
		c->setRemaining(time);
	}
	void makeBusy() { this->busy = true; }

	~Server() { c = nullptr; }
};

#endif