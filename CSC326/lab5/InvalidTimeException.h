#pragma once
#include <exception>

#ifndef INVALID_TIME_EXCEP_
#define INVALID_TIME_EXCEP_

struct InvalidTimeException : public std::exception
{
	const char * what() const throw () {
		return "Time Cannot Be Negative.";
	}
};

#endif