#include "Point.h"
#include "Vector.h"
#include "Triangle.h"
#include "Line.h"
#include "Tetrahedron.h"
#include <iostream>
#include <exception>

int VMC(CVector &, int);
int LMC(CLine &, int);

int main() {
	char key = 'y';

	while (key == 'y') {
		int element;
		double len, len1;
		std::cout << "Please, choose the type of object: \n 1-Point\n 2-Vector \n 3-Line \n 4-Triangle \n 5-Tetrahedron\n";
		std::cin >> element;

		switch (element) {
		case 1: {
			CPoint a;
			std::cout << "\nCollecting the coordinates of the point: \n";
			std::cin >> a;
			std::cout << a << "\n";
			break;
		}
		case 2: {
			CVector vector;
			int vmc = 0;
			vmc = VMC(vector, vmc);
			std::cin >> vector;//if the couts cause problems!?!??!?!
			std::cout << vector << "\n";
			int mode;
			std::cout << "Please, choose the operation which you want to perform: \n 1-Calculate vector length \n 2-Calculate vector POSOKA \n 3-Zero vector check \n 4-Vector parallelism check \n 5-Vector perpendicularity check \n 6-Vector addition \n 7-Vector addition with number \n 8-Vector SKALARNO PROIZVEDENIE \n 9-Vector VEKTORNO PROIZVEDENIE\n 10-Vector substraction";
			std::cin >> mode;
			switch (mode) {
			case 1: {
				len = vector.vectorLength();
				std::cout << "The lenght of the vector is " << len << "\n";
				break;
			}
			case 2: {
				vector.vectorDirection(len);
				break;
			}
			case 3: {
				bool zeroV = vector.zeroVector();
				std::cout << "Is the vector a zero vector - " << ((zeroV == true) ? "yes!\n" : "no!\n");
				break;
			}
			case 4: {
				CVector vector1;
				int vmc1 = 0;
				vmc1 = VMC(vector1, vmc1);
				std::cin >> vector1;
				std::cout << vector1 << "\n";
				len1 = vector1.vectorLength();
				std::cout << "The lenght of the vector is " << len1 << "\n";
				bool vParallelism = vector.vectorParallelism(vector1, len, len1);
				std::cout << "Are the vectors paralell - " << ((vParallelism == true) ? "yes!\n" : "no!\n");
				break;
			}
			case 5: {
				CVector vector1;
				int vmc1 = 0;
				vmc1 = VMC(vector1, vmc1);
				std::cin >> vector1;
				std::cout << vector1 << "\n";
				bool vPerpendicularity = vector.vectorPerpendicularity(vector1, len, len1);
				std::cout << "Are the vectors perpendicular - " << ((vPerpendicularity == true) ? "yes!\n" : "no!\n");
				break;
			}
			case 6: {
				CVector vector1, vector2;
				int vmc1 = 0;
				vmc1 = VMC(vector1, vmc1);
				std::cin >> vector1;
				std::cout << vector1 << "\n";
				vector2 = vector + vector1;
				std::cout << vector2;
				break;
			}
			case 7: {
				CVector vector2;
				int vmc2 = 0;
				vmc2 = VMC(vector2, vmc2);
				std::cin >> vector2;
				std::cout << vector2 << "\n";
				double num;
				std::cout << "Please, enter a number with which the newly created vector will be multiplied: ";
				std::cin >> num;
				vector2 = vector2 * num;
				std::cout << vector2;
				break;
			}
			case 8: {
				CVector vector1;
				int vmc1 = 0;
				vmc1 = VMC(vector1, vmc1);
				std::cin >> vector1;
				std::cout << vector1 << "\n";
				double skalProizv = vector * vector1;
				std::cout << skalProizv;
				break;
			}
			case 9: {
				CVector vector1, vector2;
				int vmc1 = 0;
				vmc1 = VMC(vector1, vmc1);
				std::cin >> vector1;
				std::cout << vector1 << "\n";
				vector2 = vector ^ vector1;
				std::cout << vector2;
				break;
			}
			case 10: {
				CVector vector1, vector2;
				int vmc1 = 0;
				vmc1 = VMC(vector1, vmc1);
				std::cin >> vector1;
				std::cout << vector1 << "\n";
				vector2 = vector - vector1;
				std::cout << vector2;
				break;
			}
			}
			break;
		}
		case 3: {
			CLine line;
			int lmc = 0;
			lmc = LMC(line, lmc);
			std::cin >> line;
			std::cout << line;
			break;
		}
		case 4: {
			CTriangle triangle;
			std::cin >> triangle;
			std::cout << triangle;
			int mode;
			std::cout << "Please, choose the operation which you want to perform: \n 1-Find triangle condition \n 2-Calculate area \n 3-Calculate perimeter \n 4-Find centroid\n 5-Is a point inside the triangle? \n 6-Is a point outside of the triangle?\n 7-Does the point lie on one of the sides of the triangle? \n ";
			std::cin >> mode;
			switch (mode) {
			case 1: {
				triangle.triangleCondition();
				break;
			}
			case 2: {
				triangle.findArea();
				break;
			}
			case 3: {
				triangle.findPerimeter();
				break;
			}
			case 4: {
				CPoint centroid;
				centroid = triangle.findCentroid();
				std::cout << "The centroid is: " << centroid;
				break;
			}
			case 5: {
				CPoint IT;
				std::cout << "\nPlease, enter the coordinates of the point for which you want of check if it is inside in the given triangle: \n";
				std::cin >> IT;
				bool isInside = triangle < IT;
				std::cout << "Is the point inside the triangle " << ((isInside == true) ? "YES!\n" : "NO!\n");
				break;
			}
			case 6: {
				CPoint OT;
				std::cout << "\nPlease, enter the coordinates of the point for which you want of check if it is outside in the given triangle: \n";
				std::cin >> OT;
				bool isOutside = triangle > OT;
				std::cout << "Is the point outside the triangle " << ((isOutside == true) ? "YES!\n" : "NO!\n");
				break;
			}
			case 7: {
				CPoint LOS;
				std::cout << "\nPlease, enter the coordinates of the point for which you want of check if it lies on one of the sides of the given triangle: \n";
				std::cin >> LOS;
				bool liesOnSide = triangle == LOS;
				std::cout << "Does the point lie on one of the sides of the triangle " << ((liesOnSide == true) ? "YES!\n" : "NO!\n");
				break;
			}
			}
			break;
		}
		case 5: {
			CTetrahedron tetrahedron;
			std::cin >> tetrahedron;
			std::cout << tetrahedron;
			int mode;
			std::cout << "Please, choose the operation which you want to perform: \n 1-Is it right? \n 2-Is it ortrocentric? \n 3-Calculate OKOLNA POVARHNINA \n";
			std::cin >> mode;
			switch (mode) {
			case 1: {
				bool isRight = tetrahedron.isRight();
				std::cout << "\nIs the tetrahedron right " << ((isRight == true) ? "YES!\n" : "NO!\n");
				break;
			}
			case 2: {
				bool isOrthrocentric = tetrahedron.isOrthrocentric();
				std::cout << "\nIs the tetrahedron orthrocentric " << ((isOrthrocentric == true) ? "YES!\n" : "NO!\n");
				break;
			}
			case 3: {
				std::cout << "The OKOLNATA POVURHNINA of the tetrahedron in " << tetrahedron.volume() << "\n";
				break;
			}
			}
		}
		}

		/*
		CPoint a;
		std::cout << "\nCollecting the coordinates of the point: \n";
		std::cin >> a;
		std::cout << a << "\n";

		CVector vector;
		int vmc = 0;
		vmc = VMC(vector, vmc);
		std::cin >> vector;//if the couts cause problems!?!??!?!
		std::cout << vector << "\n";

		//double len = vector.vectorLength(vector); -- the element is implicit
		double len = vector.vectorLength();
		std::cout << "The lenght of the vector is " << len << "\n";
		vector.vectorDirection(len);
		bool zeroV = vector.zeroVector();
		std::cout << "Is the vector a zero vector - " << ((zeroV == true) ? "yes!\n" : "no!\n");
		CVector vector1;
		int vmc1 = 0;
		vmc1 = VMC(vector1, vmc1);
		std::cin >> vector1;
		std::cout << vector1 << "\n";

		//double len1 = vector.vectorLength(vector1); -- the element is implicit
		double len1 = vector1.vectorLength();
		std::cout << "The lenght of the vector is " << len1 << "\n";
		bool vParallelism = vector.vectorParallelism(vector1, len, len1);
		std::cout << "Are the vectors paralell - " << ((vParallelism == true) ? "yes!\n" : "no!\n");
		bool vPerpendicularity = vector.vectorPerpendicularity(vector1, len, len1);
		std::cout << "Are the vectors perpendicular - " << ((vPerpendicularity == true) ? "yes!\n" : "no!\n");

		//exception for Parallelism in main
		/*
		try {
			if (len == 0 || len1 == 0) {
				throw std::exception("One of the vector legths is zero!\n");
			}
			else {
				bool vParallelism = vector.vectorParallelism(vector1);
				std::cout << "Are the vectors paralell - " << ((vParallelism == true) ? "yes!\n" : "no!\n");
			}
		}
		catch (std::exception & e) {
			std::cerr << e.what();
		}
		*/
		/*
		//exception for Perpendicularity in main
		try {
			if (len == 0 || len1 == 0) {
				throw std::exception("One of the vector legths is zero!\n");
			}
			else {
				bool vPerpendicularity = vector.vectorPerpendicularity(vector1);
				std::cout << "Are the vectors perpendicular - " << ((vPerpendicularity == true) ? "yes!\n" : "no!\n");
			}
		}
		catch (std::exception & e) {
			std::cerr << e.what();
		}
		*/
		/*
		CVector vector2;
		vector2 = vector + vector1;
		std::cout << vector2;
		vector2 = vector - vector1;
		std::cout << vector2;
		double num;
		std::cout << "Please, enter a number with which the newly created vector will be multiplied: ";
		std::cin >> num;
		vector2 = vector2 * num;
		std::cout << vector2;
		double skalProizv = vector * vector1;
		std::cout << skalProizv;
		vector2 = vector ^ vector1;
		std::cout << vector2;

		CTriangle triangle;
		std::cin >> triangle;
		std::cout << triangle;
		triangle.triangleCondition();
		triangle.findArea();
		triangle.findPerimeter();

		{
			CPoint centroid;
			centroid = triangle.findCentroid();
			std::cout << "The centroid is: " << centroid;
		}
		{
			CPoint IT;
			std::cout << "\nPlease, enter the coordinates of the point for which you want of check if it is inside in the given triangle: \n";
			std::cin >> IT;
			bool isInside = triangle < IT;
			std::cout << "Is the point inside the triangle " << ((isInside == true) ? "YES!\n" : "NO!\n");
		}
		{
			CPoint OT;
			std::cout << "\nPlease, enter the coordinates of the point for which you want of check if it is outside in the given triangle: \n";
			std::cin >> OT;
			bool isOutside = triangle > OT;
			std::cout << "Is the point outside the triangle " << ((isOutside == true) ? "YES!\n" : "NO!\n");
		}
		{
			CPoint LOS;
			std::cout << "\nPlease, enter the coordinates of the point for which you want of check if it lies on one of the sides of the given triangle: \n";
			std::cin >> LOS;
			bool liesOnSide = triangle == LOS;
			std::cout << "Does the point lie on one of the sides of the triangle " << ((liesOnSide == true) ? "YES!\n" : "NO!\n");
		}

		CLine line;
		int lmc = 0;
		lmc = LMC(line, lmc);
		std::cin >> line;
		std::cout << line;

		CTetrahedron tetrahedron;
		std::cin >> tetrahedron;
		std::cout << tetrahedron;
		bool isRight = tetrahedron.isRight();
		std::cout << "\nIs the tetrahedron right " << ((isRight == true) ? "YES!\n" : "NO!\n");
		bool isOrthrocentric = tetrahedron.isOrthrocentric();
		std::cout << "\nIs the tetrahedron orthrocentric " << ((isOrthrocentric == true) ? "YES!\n" : "NO!\n");
		std::cout << "The OKOLNATA POVURHNINA of the tetrahedron in " << tetrahedron.volume() << "\n";
		*/

		std::cout << "Do you wish to choose new geomethrical object: input y/n ";
		std::cin >> key;
		while (key != 'y' && key != 'n') {
			std::cout << "Do you wish to choose new geomethrical object: input y/n ";
			std::cin >> key;
		}
	}
	return 0;
}

int VMC(CVector & v, int vmc) {
	int mode = 0;
	while (mode < 1 || mode > 2) {
		std::cout << "\nHow do you wish to initialize the vector (enter the corresponding number):\n 1 With two points A and B? \n 2 With three variables?\n Choice: ";
		std::cin >> mode;
	}
	v.setVMC(mode);
	return mode;
}

int LMC(CLine & l, int lmc) {
	int mode = 0;
	while (mode < 1 || mode > 2) {
		std::cout << "\nHow do you wish to initialize the line (enter the corresponding number):\n 1 With two points A and B? \n 2 With a point and a vector?\n Choice: ";
		std::cin >> mode;
	}
	l.setLMC(mode);
	return mode;
}