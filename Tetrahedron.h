#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include "Point.h"

class CTetrahedron : public CPoint {
public:
	CTetrahedron() {};
	CTetrahedron(CPoint &, CPoint &, CPoint &, CPoint &);
	virtual~CTetrahedron() {
		std::cout << "\nTetrohedron destroyed!\n";
	}
	CTetrahedron(const CTetrahedron &);

	int setA(const CPoint &);
	int setB(const CPoint &);
	int setC(const CPoint &);
	int setD(const CPoint &);
	const CPoint getA()const;
	const CPoint getB()const;
	const CPoint getC()const;
	const CPoint getD()const;
	bool isRight()const;
	bool isOrthrocentric()const;
	double volume()const;

	CTetrahedron & operator=(const CTetrahedron &);

	virtual std::ostream & inserter(std::ostream &) const;
	virtual std::istream & extractor(std::istream &);
	
private:
	CPoint A, B, C, D;
	double AB, BC, AC, AD, BD, CD;
};

std::ostream& operator << (std::ostream&, const CTetrahedron &);
std::istream & operator >> (std::istream&, CTetrahedron &);

#endif // !TERTAHEDRON_H
