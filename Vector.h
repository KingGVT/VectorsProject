#ifndef VECTOR_H
#define VECTOR_H

#include "Point.h"

class CVector : public CPoint {
public: 
	CVector(double = 0., double = 0., double = 0.);
	CVector(CPoint &, CPoint &); 
	CVector(const CVector &);
	virtual~CVector() { 
		//std::cout << "\n--------Vector destroyed!"; 
	}

	int setVPA(CPoint &);
	int setVPB(CPoint &);
	int setVMC(int);
	int setXV(double);
	int setYV(double);
	int setZV(double);
	const CPoint getVPA()const;//nigga not sure if they have to return reference
	const CPoint getVPB()const;//nigga not sure if they need to return reference
	int getVMC()const;
	double getXV()const;
	double getYV()const;
	double getZV()const;

	//double vectorLength(const CVector &); --- the lhs is implicit element and we dont have to make it explicit
	double vectorLength()const;
	double vectorDirection(double)const;
	bool zeroVector()const;
	//bool vectorParallelism(const CVector &, const CVector &); --- the lhs in implicit element
	bool vectorParallelism(const CVector &, double, double);
	bool vectorPerpendicularity(const CVector &, double, double);

	friend const CVector operator+(const CVector &, const CVector &);//with friend works 
	friend const CVector operator-(const CVector &, const CVector &);
	const CVector operator*(double)const;
	friend double operator*(const CVector &, const CVector &);
	friend const CVector operator^(const CVector &, const CVector &);
	CVector& operator=(const CVector&);

	virtual std::ostream & inserter(std::ostream &) const;
	virtual std::istream & extractor(std::istream &);

private:
	CPoint VectorPointA, VectorPointB; //check if we can print them when the vector is created with x, y,z

	int modeVectorCreation;

	double xV;
	double yV; 
	double zV;
};

std::ostream& operator << (std::ostream&, const CVector &);
std::istream & operator >> (std::istream&, CVector &);

#endif // !VECTOR_H
