#ifndef LINE_H
#define LINE_H

#include "Vector.h"

class CLine : public CVector {
public:
	CLine() {};
	CLine(CPoint &, CPoint &);
	CLine(CPoint &, CVector &);
	CLine(const CLine &);
	virtual~CLine() {
		//std::cout << "\nLine destroyed!\n";
	}

	int setLP(const CPoint &);
	int setLineVector(const CVector &);
	int setLMC(unsigned);
	int getLMC()const;
	const CPoint getLP()const;
	const CVector getLineVector()const;

	CLine & operator=(const CLine &);

	virtual std::ostream & inserter(std::ostream &) const;
	virtual std::istream & extractor(std::istream &);

private:
	CPoint linePoint;
	CVector lineVector;

	int lineModeCreation;
};

std::ostream& operator << (std::ostream&, const CLine &);
std::istream & operator >> (std::istream&, CLine &);

#endif