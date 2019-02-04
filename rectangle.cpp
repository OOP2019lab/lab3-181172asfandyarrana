#include "pch.h"
#include<iostream>
#include "rectangle.h"
using namespace std;


void rectangle::setLength(int l)
{
	if (l >= 0) // no negative values: if not negative than input
	{
		len = l;
	}
}
int rectangle::getLength() const // const to avoid alteration
{
	return len;// return length of rect
}
int rectangle::getWidth() const
{
	return width;
}
void rectangle::setWidth(int w)// same as length function
{
	if (w >= 0)
	{
		width = w;
	}
}
int rectangle::getArea() const //calculate area and return value
{
	return len * width;
}
void rectangle::rotateRectangle()//rotate by storing in temp var
{
	int temp;
	temp = len;
	len = width;
	width = temp;
	
}
void rectangle::draw() const
{
	for (int y= 0; y < width; y++)
	{
		for (int z = 0; z < len; z++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
