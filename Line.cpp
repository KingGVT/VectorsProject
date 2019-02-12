#include "Line.h"
#include "VectorLengthException.h"
#include <iostream>

CLine::CLine(CPoint & first, CPoint & second) {
	linePoint = first;
	lineVector = CVector(first, second);
}

CLine::CLine(CPoint & point, CVector & vector) {
	linePoint = point;
	lineVector = vector;
}

CLine::CLine(const CLine & rhs) {
	linePoint = rhs.linePoint;
	lineVector = rhs.lineVector;
}

int CLine::setLP(const CPoint & point) {
	linePoint = point;
	return 0;
}

int CLine::setLineVector(const CVector & vector) {
	lineVector = vector;
	return 0;
}

int CLine::setLMC(unsigned mode) {
	lineModeCreation = mode;
	return 0;
}

int CLine::getLMC()const { return lineModeCreation; }

const CPoint CLine::getLP()const { return linePoint; }

const CVector CLine::getLineVector()const { return lineVector; }

CLine& CLine::operator=(const CLine & rhs) {
	if (this != &rhs) {
		linePoint = rhs.linePoint;
		lineVector = rhs.lineVector;
	}
	return *this;
}

std::ostream & CLine::inserter(std::ostream & out) const {
	return out << "\nPrinting the line:" << linePoint << lineVector;
}

std::istream & CLine::extractor(std::istream & in) {
	CPoint tmp;
	if (lineModeCreation == 1) {
		in >> linePoint >> tmp;
		lineVector = CVector(linePoint, tmp);
	}
	else {
		in >> linePoint >> lineVector;
	}
	return in;
}

std::ostream& operator << (std::ostream & lhs, const CLine & rhs) { return rhs.inserter(lhs); }

std::istream & operator >> (std::istream& lhs, CLine & rhs) { return rhs.extractor(lhs); }