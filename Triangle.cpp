#include "Triangle.h"
#include "EqualPointException.h"
#include <exception>
#include <iostream>
#include <cmath>


#define PI 3.1415926535

CTriangle::CTriangle() {};

CTriangle::CTriangle(CPoint & a, CPoint & b, CPoint & c) : CPoint(x, y, z) {
	CPoint tmpA, tmpB, tmpC;
	try {
		if (a == b) throw EqualPointException("Points A and B are the same!");
		else if (b == c) throw EqualPointException("Points B and C are the same!");
		else if (a == c) throw EqualPointException("Points A and C are the same!");
		else {
			PointA = a;
			PointB = b;
			PointC = c;
		}
	}
	catch (EqualPointException & e) {
		std::cerr << e.what();
		if (a == b || b == c || c == a) {
			while (tmpA == tmpB || tmpB == tmpC || tmpC == tmpA) {
				std::cin >> tmpA >> tmpB >> tmpC;
			}
		}
		PointA = tmpA;
		PointB = tmpB;
		PointC = tmpC;
	}
	sideA = length(PointB, PointC);
	sideB = length(PointA, PointC);
	sideC = length(PointA, PointB);
}

CTriangle::CTriangle(const CTriangle & rhs) {
	std::cout << "\nTriangle copied!\n";
	PointA = rhs.PointA;
	PointB = rhs.PointB;
	PointC = rhs.PointC;
	sideA = rhs.sideA;
	sideB = rhs.sideB;
	sideC = rhs.sideC;
}

CTriangle& CTriangle::operator=(const CTriangle & rhs) {
	if (this != &rhs) {
		PointA = rhs.PointA;
		PointB = rhs.PointB;
		PointC = rhs.PointC;
		sideA = rhs.sideA;
		sideB = rhs.sideB;
		sideC = rhs.sideC;
	}
	return *this;
}

const CPoint CTriangle::getPointA()const { return PointA; }

const CPoint CTriangle::getPointB()const { return PointB; }

const CPoint CTriangle::getPointC()const { return PointC; }

int CTriangle::setPA(const CPoint & a) {
	PointA = a;
	return 0;
}

int CTriangle::setPB(const CPoint & b) {
	PointB = b;
	return 0;
}

int CTriangle::setPC(const CPoint & c) {
	PointC = c;
	return 0;
}

int CTriangle::triangleCondition()const {
	if (sideA == sideB && sideA != sideC) {
		std::cout << "\nThe triangle is Isosceles.\n";//ravnobedren
	}
	else if (sideA == sideB && sideB == sideC) {
		std::cout << "\nThe triangle is Equilateral.\n";//ravnostranen
	}
	else {
		std::cout << "\nThe triangle is Scalene.\n";//raznostranen
	}

	double a = sqrt(sideA), b = sqrt(sideB), c = sqrt(sideC);

	double alpha = acos((sideB + sideC - sideA) / (2 * b*c)), betta = acos((sideA + sideC - sideB) / (2 * a*c)), gamma = acos((sideA + sideB - sideC) / (2 * a*b));
	alpha = alpha * 180 / PI;
	betta = betta * 180 / PI;
	gamma = gamma * 180 / PI;
	std::cout << "Aplha angle: " << alpha << " | Betta angle: " << betta << " | Gamma angle: " << gamma << "\n";
	if (alpha == 90 || betta == 90 || gamma == 90) {
		std::cout << "The triangle is right.\n";//pravougalen
	}
	else if (alpha < 90 && betta < 90 && gamma < 90) {
		std::cout << "The triangle is acute.\n";//ostrougalen
	}
	else if (alpha > 90 || betta > 90 || gamma > 90) {
		std::cout << "The triangle is obtuse.\n";//tupougalen
	}
	return 0;
}

int CTriangle::findArea()const {
	double p = (sideA + sideB + sideC) / 2, area;
	area = sqrt(p*(p - sideA)*(p - sideB)*(p - sideC));
	std::cout << "The area of the triangle is " << area << "\n";
	return 0;
}

int CTriangle::findPerimeter()const {
	double P = sideA + sideB + sideC;
	std::cout << "The perimeter of the triangle is " << P << "\n";
	return 0;
}

const CPoint CTriangle::findCentroid()const {
	double x, y, z;
	x = (PointA.getX() + PointB.getX() + PointC.getX()) / 3;
	y = (PointA.getY() + PointB.getY() + PointC.getY()) / 3;
	z = (PointA.getZ() + PointB.getZ() + PointC.getZ()) / 3;
	return CPoint(x, y, z);
}

double area(double x1, double y1, double x2, double y2, double x3, double y3) {
	return abs((x1*(y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

bool CTriangle::operator < (const CPoint & point)const {
	double a, a1, a2, a3;
	a = area(PointA.getX(), PointA.getY(), PointB.getX(), PointB.getY(), PointC.getX(), PointC.getY());
	a1 = area(point.getX(), point.getY(), PointB.getX(), PointB.getY(), PointC.getX(), PointC.getY());
	a2 = area(PointA.getX(), PointA.getY(), point.getX(), point.getY(), PointC.getX(), PointC.getY());
	a3 = area(PointA.getX(), PointA.getY(), PointB.getX(), PointB.getY(), point.getX(), point.getY());
	if (a == (a1 + a2 + a3)) return true;
	return false;
}

bool CTriangle::operator > (const CPoint & point)const {
	double a, a1, a2, a3;
	a = area(PointA.getX(), PointA.getY(), PointB.getX(), PointB.getY(), PointC.getX(), PointC.getY());
	a1 = area(point.getX(), point.getY(), PointB.getX(), PointB.getY(), PointC.getX(), PointC.getY());
	a2 = area(PointA.getX(), PointA.getY(), point.getX(), point.getY(), PointC.getX(), PointC.getY());
	a3 = area(PointA.getX(), PointA.getY(), PointB.getX(), PointB.getY(), point.getX(), point.getY());
	if (a != (a1 + a2 + a3)) return true;
	return false;
}

bool liesOnSide(double s1, double s2, double s) {
	if ((s1 + s2) == s) return true;
	return false;
}

bool CTriangle::operator == (const CPoint & point)const {
	double am, bm, cm;
	am = length(PointA, point);
	cm = length(PointC, point);
	bm = length(PointB, point);
	if (liesOnSide(am, cm, sideB)) return true;
	if (liesOnSide(am, bm, sideC)) return true;
	if (liesOnSide(bm, cm, sideA)) return true;
	return false;
}

std::ostream & CTriangle::inserter(std::ostream & out) const { return out << "\nPoint A:" << PointA << "\nPoint B:" << PointB << "\nPoint C" << PointC << "\nSide A: " << sideA << "\nSide B: " << sideB << "\nSide C: " << sideC; }

std::istream & CTriangle::extractor(std::istream & in) {
	std::cout << "\nCollecting the points for the triangle:\n";
	in >> PointA >> PointB >> PointC;
	try {
		if (PointA == PointB) throw EqualPointException("Points A and B are the same! Collecting again:\n");
		if (PointB == PointC) throw EqualPointException("Points B and C are the same! Collecting again:\n");
		if (PointA == PointC) throw EqualPointException("Points A and C are the same! Collecting again:\n");
	}
	catch (EqualPointException & e) {
		std::cerr << e.what();
		while (PointA == PointB || PointB == PointC || PointA == PointC) {
			in >> PointA >> PointB >> PointC;
		}
	}
	sideA = length(PointB, PointC);
	sideB = length(PointA, PointC);
	sideC = length(PointA, PointB);
	return in;
}

std::ostream & operator << (std::ostream& lhs, const CTriangle & rhs) { return rhs.inserter(lhs); }

std::istream & operator >> (std::istream& lhs, CTriangle & rhs) { return rhs.extractor(lhs); }