#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"

class CTriangle : public CPoint {
public:
	CTriangle();
	CTriangle(CPoint &, CPoint &, CPoint &);
	virtual~CTriangle() {
		//std::cout << "\nTriangle destroyed!\n";
	}
	CTriangle(const CTriangle &);
	CTriangle& operator=(const CTriangle&);

	const CPoint getPointA()const;
	const CPoint getPointB()const;
	const CPoint getPointC()const;
	int setPA(const CPoint &);
	int setPB(const CPoint &);
	int setPC(const CPoint &);

	int triangleCondition()const;
	int findArea()const;
	int findPerimeter()const;
	const CPoint findCentroid()const;
	
	bool operator < (const CPoint &)const;
	bool operator > (const CPoint &)const;
	bool operator == (const CPoint &)const;

	virtual std::ostream & inserter(std::ostream &) const;
	virtual std::istream & extractor(std::istream &);

private:
	CPoint PointA, PointB, PointC;
	double sideA, sideB, sideC;
};

double area(double, double, double, double, double, double);
bool liesOnSide(double, double, double);

std::ostream & operator << (std::ostream&, const CTriangle &);
std::istream & operator >> (std::istream&, CTriangle &);

#endif
