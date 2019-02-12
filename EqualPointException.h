#ifndef  EQUALPOINTEXCEPTION_H
#define EQUALPOINTEXCEPTION_H

#include <exception>
#include <iostream>

class EqualPointException : public std::exception {
public:
	EqualPointException(std::string = "");
	virtual~EqualPointException();

	const char * what()const;//mostly acts like a getter for the exception 

private:
	std::string exc;
};

#endif // ! EQUALPOINTEXCEPTION_H
