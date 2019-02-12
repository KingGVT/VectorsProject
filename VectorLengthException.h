#ifndef VECTORLENGTHEXCEPTION_H
#define VECTORLENGTHEXCEPTION_H

#include <exception>
#include <iostream>

class VectorLengthException : public std::exception {
public:
	VectorLengthException(std::string = "");
	virtual~VectorLengthException();

	const char * what()const;//mostly acts like a getter for the exception 

private: 
	std::string exc;
};

#endif // !VECTORLENGTHEXCEPTION
