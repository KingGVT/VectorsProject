#include "VectorLengthException.h"
#include "Vector.h"
#include <iostream>

VectorLengthException::VectorLengthException(std::string str) {
	if (!str.empty()) {
		exc = str;
	}
}

VectorLengthException::~VectorLengthException() {
	//std::cout << "\nException destroyed!\n";
}

const char * VectorLengthException::what()const {
	if (!exc.empty()) {
		const char * msg = exc.c_str();
		return msg;
	}
	return NULL;
}
