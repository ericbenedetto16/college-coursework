#pragma once
#include <exception>

#ifndef NO_SERVERS_EXCEP_
#define NO_SERVERS_EXCEP_

struct NoServersException : public std::exception
{
	const char * what() const throw () {
		return "No Servers Were Available";
	}
};

#endif