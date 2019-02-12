#include "Vector.h"
#include "VectorLengthException.h"
#include <iostream>
#include <fstream>

CVector::CVector(double x, double y, double z) : xV(x), yV(y), zV(z) {};

CVector::CVector(CPoint & a, CPoint & b) : CPoint(x, y, z) {
	VectorPointA = a;
	VectorPointB = b;
	xV = b.getX() - a.getX();
	yV = b.getY() - a.getY();
	zV = b.getZ() - a.getZ();
}

CVector::CVector(const CVector & rhs) {
	std::cout << "\nVector copied!\n";
	if (modeVectorCreation == 1) {
		VectorPointA = rhs.VectorPointA;
		VectorPointB = rhs.VectorPointB;
		xV = rhs.xV;
		yV = rhs.yV;
		zV = rhs.zV;
	}
	else {
		xV = rhs.xV;
		yV = rhs.yV;
		zV = rhs.zV;
	}
}

int CVector::setVPA(CPoint & a) {
	VectorPointA = a;
	return 0;
}

int CVector::setVPB(CPoint & b) {
	VectorPointB = b;
	return 0;
}

const CPoint CVector::getVPA()const { return VectorPointA; }

const CPoint CVector::getVPB()const { return VectorPointB; }

int CVector::setXV(double x) {
	xV = x;
	return 0;
}

int CVector::setYV(double y) {
	yV = y;
	return 0;
}

int CVector::setZV(double z) {
	zV = z;
	return 0;
}

int CVector::setVMC(int vmc) {
	modeVectorCreation = vmc;
	return 0;
}

int CVector::getVMC()const { return modeVectorCreation; }

double CVector::getXV()const { return xV; }

double CVector::getYV()const { return yV; }

double CVector::getZV()const { return zV; }

CVector& CVector::operator=(const CVector& rhs) {
	if (this != &rhs) {
		if (modeVectorCreation == 1) {
			//CPoint::operator=(rhs); doesnt do shit
			VectorPointA = rhs.VectorPointA;
			VectorPointB = rhs.VectorPointB;
			xV = rhs.xV;
			yV = rhs.yV;
			zV = rhs.zV;
		}
		else {
			//CPoint::operator=(rhs); doesnt do shit
			xV = rhs.xV;
			yV = rhs.yV;
			zV = rhs.zV;
		}
	}
	return *this;
}

std::ostream & CVector::inserter(std::ostream & out) const { return out << "\nPrinting VECTOR:\n Coordinate X = " << xV << " | Y = " << yV << " | Z = " << zV << "\n"; }

std::istream & CVector::extractor(std::istream & in) {
	if (modeVectorCreation == 1)
	{
		in >> VectorPointA >> VectorPointB;
		xV = VectorPointB.getX() - VectorPointA.getX();
		yV = VectorPointB.getY() - VectorPointA.getY();
		zV = VectorPointB.getZ() - VectorPointA.getZ();
		std::cout << VectorPointA << "\n" << VectorPointB;
	}
	else
	{
		//CPoint::extractor(in); doesnt do shit
		std::cout << "Please, enter the X coordinate: ";
		in >> xV;
		std::cout << "Please, enter the Y coordinate: ";
		in >> yV;
		std::cout << "Please, enter the Z coordinate: ";
		in >> zV;
	}
	return in;
}

std::ostream& operator << (std::ostream & lhs, const CVector & rhs) { return rhs.inserter(lhs); }

std::istream & operator >> (std::istream & lhs, CVector & rhs) { return rhs.extractor(lhs); }

/*
double CVector::vectorLength(const CVector & rhs) {
	double length = abs(sqrt((rhs.getXV() * rhs.getXV()) + (rhs.getYV() * rhs.getYV()) + (rhs.getZV() * rhs.getZV())));
	return length;
}
*/

double CVector::vectorLength()const {
	double length = abs(sqrt((xV * xV) + (yV * yV) + (zV * zV)));
	return length;
}

double CVector::vectorDirection(double len)const {
	double direction;
	try {
		if (len == 0) {
			throw VectorLengthException("The vector lenght is zero!\n");
		}
		else {
			direction = len / fabs(len);
			std::cout << "The vector direction is " << direction << "\n";
		}
	}
	catch (VectorLengthException & e) {
		std::cerr << e.what();
		direction = 0.;
	}

	return direction;
}

bool CVector::zeroVector()const {
	if (xV == 0 && yV == 0 && zV == 0) return true;
	return false;
}

/*
bool CVector::vectorParallelism(const CVector & rhs, const CVector & lhs) {
	double first = rhs.getXV() / lhs.getXV(), second = rhs.getYV() / lhs.getYV(), third = rhs.getZV() / lhs.getZV();
	if (first == second && second == third)	return true;
	return false;
}
*/

bool CVector::vectorParallelism(const CVector & rhs, double l1, double l2) {
	try {
		if (l1 == 0 || l2 == 0) throw VectorLengthException("One of the vector legths is zero!\n");
		else {
			double first = rhs.getXV() / xV, second = rhs.getYV() / yV, third = rhs.getZV() / zV;
			if (first == second && second == third)	return true;
		}
	}
	catch (VectorLengthException & e) {
		std::cerr << e.what();
	}

	return false;
}

bool CVector::vectorPerpendicularity(const CVector & rhs, double l1, double l2) {
	try {
		if (l1 == 0 || l2 == 0) {
			throw VectorLengthException("One of the vector legths is zero!\n");
		}
		else {
			double first = rhs.getXV() * xV, second = rhs.getYV() * yV, third = rhs.getZV() * zV, result;
			result = first + second + third;
			if (result == 0) return true;
		}
	}
	catch (VectorLengthException & e) {
		std::cerr << e.what();
	}

	return false;
}

const CVector operator+(const CVector & lhs, const CVector & rhs) {
	std::cout << "\nVector addition:\n";
	return CVector(lhs.getXV() + rhs.getXV(), lhs.getYV() + rhs.getYV(), lhs.getZV() + rhs.getZV());
}

const CVector operator-(const CVector & rhs, const CVector & lhs) {
	std::cout << "\nVector substraction:\n";
	return CVector(lhs.getXV() - rhs.getXV(), lhs.getYV() - rhs.getYV(), lhs.getZV() - rhs.getZV());
}

const CVector CVector::operator*(double a) const {
	std::cout << "\nVector multiplication with number:\n";
	return CVector(a * xV, a * yV, a * zV);
}

double operator*(const CVector & rhs, const CVector & lhs) {
	std::cout << "\nSkalarno proizvedenie: ";
	double num = (rhs.getXV() * lhs.getXV()) + (rhs.getYV() * lhs.getYV()) + (rhs.getZV() * lhs.getZV());
	return num;
}

const CVector operator^(const CVector & a, const CVector & b) {
	std::cout << "\nVectorno proizvedenie:\n";
	return CVector(a.getYV() * b.getZV() - a.getZV() * b.getYV(), -a.getXV() * b.getZV() + a.getZV() * b.getXV(), a.getXV() * b.getYV() - a.getYV() * b.getXV());
}