// q2_181172_imp_cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "rectangle.h"
using namespace std;
int main()
{
	int length = 0;
	int width = 0;
	rectangle barr;

	cout << "Enter the length of rectangle:" << endl;
		cin >> length;
		cout << "Enter the width of the rectangle:" << endl;
		cin >> width;


		barr.setWidth(width);
		barr.setLength(length);
		//now we will return these values from get functions

		cout << "The inputed length of rectangle is:" << barr.getLength() << endl;
		cout << "The inputed width of rectagle is:" << barr.getWidth() << endl;
		//calculate area by multiplying w*l
		cout << "The calculated of the rectangle is:" << barr.getArea() << endl;
		cout << "The shape of the rectangle is as follow:" << endl << endl;
		barr.draw();
		barr.rotateRectangle();//rotates rectangle
		cout << "The rectangle after rotation:" << endl;
		cout << "The inputed length of rectangle is:" << barr.getLength() << endl;
		cout << "The inputed width of rectagle is:" << barr.getWidth() << endl;
		//calculate area by multiplying w*l
		cout << "The calculated of the rectangle is:" << barr.getArea() << endl;
		cout << "The shape of the rectangle is as follow:" << endl << endl;
		barr.draw();




		return 0;

}