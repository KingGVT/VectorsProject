#include "Point.h"
#include <iostream>
#include <fstream>

double length(const CPoint & first, const CPoint & second) {
	double x, y, z, length;
	x = first.getX() - second.getX();
	y = first.getY() - second.getY();
	z = first.getZ() - second.getZ();
	length = abs(sqrt(x * x + y * y + z * z));
	return length;
}

CPoint::CPoint(double x, double y, double z) :x(x), y(y), z(z) {}

CPoint::CPoint(const CPoint & obj) {
	std::cout << "\nPoint copied!\n";
	x = obj.x;
	y = obj.y;
	z = obj.z;
}

bool CPoint::operator==(const CPoint & rhs) const {
	if (x == rhs.x && y == rhs.y && z == rhs.z) return true;
	return false;
}

int CPoint::setX(double x) {
	this->x = x;
	return 0;
}

int CPoint::setY(double y) {
	this->y = y;
	return 0;
}

int CPoint::setZ(double z) {
	this->z = z;
	return 0;
}

double CPoint::getX() const { return x; }

double CPoint::getY() const { return y; }

double CPoint::getZ() const { return z; }

CPoint& CPoint::operator=(const CPoint & rhs) {
	if (this != &rhs) {
		this->x = rhs.x;
		this->y = rhs.y;
		this->z = rhs.z;
	}
	return *this;
}

std::ostream & CPoint::inserter(std::ostream & out) const { return out << "\nPrinting POINT:\n Coordinate X = " << x << "\n Coordinate Y = " << y << "\n Coordinate Z = " << z; }

std::istream & CPoint::extractor(std::istream & in) {
	//the cout may cause problems with the writing in the file
	std::cout << "Please, enter the X coordinate of the point: ";
	in >> x;
	std::cout << "Please, enter the Y coordinate of the point: ";
	in >> y;
	std::cout << "Please, enter the Z coordinate of the point: ";
	in >> z;
	return in;
}

std::ostream& operator << (std::ostream& lhs, const CPoint & rhs) { return rhs.inserter(lhs); }

std::istream& operator >> (std::istream& lhs, CPoint & rhs) { return rhs.extractor(lhs); }
