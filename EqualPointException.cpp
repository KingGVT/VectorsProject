#include "EqualPointException.h"
#include "Triangle.h"
#include <exception>
#include <iostream>

EqualPointException::EqualPointException(std::string str) {
	if (!str.empty()) {
		exc = str;
	}
}

EqualPointException::~EqualPointException() {
	std::cout << "\nException destroyed!\n";
}

const char * EqualPointException::what()const {
	if (!exc.empty()) {
		const char * msg = exc.c_str();
		return msg;
	}
	return NULL;
}