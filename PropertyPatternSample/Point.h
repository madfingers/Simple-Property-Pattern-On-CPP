#pragma once
#include "Property.h"
class Point {
	int x, y;
public:
	Point();
	const Property<int, Point> X, Y;
private:
	int GetX();
	int GetY();
	void SetX(int value);
	void SetY(int value);
};