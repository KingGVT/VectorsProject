#include "Tetrahedron.h"
#include "EqualPointException.h"

CTetrahedron::CTetrahedron(CPoint & a, CPoint & b, CPoint & c, CPoint & d) {
	CPoint tmpA, tmpB, tmpC, tmpD;
	try {
		if (a == b) throw EqualPointException("Points A and B are the same! Collecting again:\n");
		else if (b == c) throw EqualPointException("Points B and C are the same! Collecting again:\n");
		else if (c == d) throw EqualPointException("Points A and C are the same! Collecting again:\n");
		else if (a == d) throw EqualPointException("Points A and C are the same! Collecting again:\n");
		else {
			A = a;
			B = b;
			C = c;
			D = d;
		}
	}
	catch (EqualPointException & e) {
		std::cerr << e.what();
		if (a == b || b == c || c == d || d == a) {
			while (tmpA == tmpB || tmpB == tmpC || tmpC == tmpD || tmpD == tmpA) {
				std::cin >> tmpA >> tmpB >> tmpC >> tmpD;
			}
		}
		A = tmpA;
		B = tmpB;
		C = tmpC;
		D = tmpD;
	}
	AB = length(A, B);
	BC = length(B, C);
	AC = length(A, C);
	AD = length(A, D);
	BD = length(B, D);
	CD = length(C, D);
}

CTetrahedron::CTetrahedron(const CTetrahedron & rhs) {
	A = rhs.A;
	B = rhs.B;
	C = rhs.C;
	D = rhs.D;
	AB = length(A, B);
	BC = length(B, C);
	AC = length(A, C);
	AD = length(A, D);
	BD = length(B, D);
	CD = length(C, D);
}

int CTetrahedron::setA(const CPoint & a) {
	A = a;
	return 0;
}

int CTetrahedron::setB(const CPoint & b) {
	B = b;
	return 0;
}

int CTetrahedron::setC(const CPoint & c) {
	C = c;
	return 0;
}

int CTetrahedron::setD(const CPoint & d) {
	D = d;
	return 0;
}

const CPoint CTetrahedron::getA()const { return A; }

const CPoint CTetrahedron::getB()const { return B; }

const CPoint CTetrahedron::getC()const { return C; }

const CPoint CTetrahedron::getD()const { return D; }

bool CTetrahedron::isRight() const {
	if (AB == BC && BC == AC && AC == AD && AD == BD && BD == CD) return true;
	return false;
}

bool CTetrahedron::isOrthrocentric()const {
	double first, second, third;
	first = AB * AB + CD * CD;
	second = AC * AC + BD * BD;
	third = AD * AD + BC * BC;
	if (first == second && second == third) return true;
	return false;
}

double CTetrahedron::volume()const {
	double volume, dm, p;
	CPoint M((B.getX() - A.getX()) / 2, (B.getY() - A.getY()) / 2, (B.getZ() - A.getZ()) / 2);
	dm = length(D, M);
	p = (AB + BC + CD) / 2;
	volume = dm * p;
	return volume;
}

CTetrahedron & CTetrahedron::operator=(const CTetrahedron & rhs) {
	if (this != &rhs) {
		A = rhs.A;
		B = rhs.B;
		C = rhs.C;
		D = rhs.D;
		AB = length(A, B);
		BC = length(B, C);
		AC = length(A, C);
		AD = length(A, D);
		BD = length(B, D);
		CD = length(C, D);
	}
	return *this;
}

std::ostream & CTetrahedron::inserter(std::ostream & out) const {
	return out << "\nTetrahedron:\nA:" << A << "\nB" << B << "\nC" << C << "\nD" << D;
}

std::istream & CTetrahedron::extractor(std::istream & in) {
	std::cout << "\nCollecting the coordinates for the tetrahedron:\n";
	in >> A >> B >> C >> D;
	try {
		if (A == B) throw EqualPointException("Points A and B are the same! Collecting again:\n");
		if (B == C) throw EqualPointException("Points B and C are the same! Collecting again:\n");
		if (C == D) throw EqualPointException("Points A and C are the same! Collecting again:\n");
		if (A == D) throw EqualPointException("Points A and C are the same! Collecting again:\n");
	}
	catch (EqualPointException & e) {
		std::cerr << e.what();
		while (A == B || B == C || C == D || D == A) {
			in >> A >> B >> C >> D;
		}
	}
	AB = length(A, B);
	BC = length(B, C);
	AC = length(A, C);
	AD = length(A, D);
	BD = length(B, D);
	CD = length(C, D);
	return in;
}

std::ostream & operator << (std::ostream & lhs, const CTetrahedron & rhs) { return rhs.inserter(lhs); }

std::istream & operator >> (std::istream & lhs, CTetrahedron & rhs) { return rhs.extractor(lhs); }