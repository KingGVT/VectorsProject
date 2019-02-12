#ifndef POINT_H
#define POINT_H

#include <iostream>

class CElement {
public:
	CElement() {};
	virtual~CElement() { 
		//std::cout << "\n-------Element destroyed!"; 
	}
};

class CPoint : public CElement {
public:
	CPoint(double = 0., double = 0., double = 0.);
	CPoint(const CPoint &);
	virtual~CPoint() { 
		//std::cout << "\n--------Point destroyed!";
	}

	bool operator==(const CPoint &) const;

	int setX(double);
	int setY(double);
	int setZ(double);

	double getX() const;
	double getY() const;
	double getZ() const;

	CPoint & operator=(const CPoint &);

	virtual std::ostream & inserter(std::ostream &) const;
	virtual std::istream & extractor(std::istream &); 

protected:
	double x;
	double y;
	double z;
};

std::ostream & operator << (std::ostream &, const CPoint &);
std::istream & operator >> (std::istream &, CPoint &);

double length(const CPoint &, const CPoint &);

#endif // !PointH
